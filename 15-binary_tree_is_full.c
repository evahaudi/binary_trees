#include "binary_trees.h"

/**
 *binary_tree_is_full - checks if binary tree is full
 *@tree: pointer to the root node of the tree
 *
 *Return: 1 if full, 0 if not
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		int left, right;

		left = 0;
		right = 0;

		if (tree->left == NULL && tree->right == NULL)
			return (1);
		if (tree->left != NULL)
			left = binary_tree_is_full(tree->left);
		if (tree->right != NULL)
			right = binary_tree_is_full(tree->right);

		if (left == 1 && right == 1)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
