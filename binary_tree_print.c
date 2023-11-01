#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
  if (tree == NULL)
    return;

  if (tree->right != NULL)
    binary_tree_print(tree->right);

  printf("%d", tree->n);

  if (tree->left != NULL || tree->right != NULL)
    printf("(");

  if (tree->left != NULL)
    {
      binary_tree_print(tree->left);
    }

  if (tree->left != NULL && tree->right == NULL)
    printf("()");

  if (tree->left != NULL && tree->right != NULL)
    printf(", ");

  if (tree->right != NULL)
    {
      binary_tree_print(tree->right);
    }

  if (tree->left != NULL || tree->right != NULL)
    printf(")");

  if (tree->parent == NULL)
    printf("\n");
}
