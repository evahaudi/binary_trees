#include "binary_trees.h"

/**
 *height_of_tree - measure the height of a binary tree
 *@tree: pointer to the root node of the tree
 *
 *Return: the height of the tree
 */


size_t height_of_tree(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree != NULL)
	{

		if (tree->left == NULL && tree->right == NULL)
			return (0);
		left = 1 + height_of_tree(tree->left);
		right = 1 + height_of_tree(tree->right);

		if (left > right)
			return (left);
		return (right);
	}
	else
	{
		return (0);
	}
}


/**
 *tree_depth - measures the depth of a node of a tree
 *@tree: pointer to the root node of the tree
 *
 *Return: depth of the node
 *
 */

size_t tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	while (tree->parent != NULL)
	{
		count++;
		tree = tree->parent;
	}
	return (count);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *@tree: pointer to the root node of the tree
 *
 *Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left;
	size_t right;
	int leaf_depth;

	if (tree != NULL)
	{

		if (height_of_tree(tree->left) != height_of_tree(tree->right))
			return (0);

		if (tree->left == NULL && tree->right == NULL)
		{
			leaf_depth = tree_depth(tree);

			return (leaf_depth);
		}


		left = binary_tree_is_perfect(tree->left);
		right = binary_tree_is_perfect(tree->right);

		if (left != right)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}
