#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 * @level: Level of the node (used for indentation)
 */
void binary_tree_print(const binary_tree_t *tree, int level)
{
  if (tree == NULL)
    return;

  binary_tree_print(tree->right, level + 1);

  for (int i = 0; i < level; i++)
    printf("  ");

  printf("%d\n", tree->n);

  binary_tree_print(tree->left, level + 1);
}
