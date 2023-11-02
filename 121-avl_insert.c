#include "binary_trees.h"

/**
 * update_height - Updates the height of a node
 * @node: A pointer to the node to update.
 */
void update_height(avl_t *node)
{
  int left_height = node->left ? node->left->height : -1;
  int right_height = node->right ? node->right->height : -1;

  node->height = 1 + (left_height > right_height ? left_height : right_height);
}


/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly created node or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
  if (!tree)
    return NULL;

  if (*tree == NULL)
    {
      *tree = binary_tree_node(NULL, value);
      if (!*tree)
	return NULL;
      return *tree;
    }

  if (value < (*tree)->n)
    {
      (*tree)->left = avl_insert(&((*tree)->left), value);
      if (!(*tree)->left)
	return NULL;
    }
  else if (value > (*tree)->n)
    {
      (*tree)->right = avl_insert(&((*tree)->right), value);
      if (!(*tree)->right)
	return NULL;
    }
  else
    return *tree;

  update_height(*tree);

  int bf = binary_tree_balance(*tree);

  if (bf > 1)
    {
      if (value < (*tree)->left->n)
	*tree = binary_tree_rotate_right(*tree);
      else
	{
	  (*tree)->left = binary_tree_rotate_left((*tree)->left);
	  *tree = binary_tree_rotate_right(*tree);
	}
    }
  else if (bf < -1)
    {
      if (value > (*tree)->right->n)
	*tree = binary_tree_rotate_left(*tree);
      else
	{
	  (*tree)->right = binary_tree_rotate_right((*tree)->right);
	  *tree = binary_tree_rotate_left(*tree);
	}
    }

  return *tree;
}
