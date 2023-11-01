#include "binary_trees.h"

/**
 *tree_height - measures the height of a tree
 *@tree: pointer to the root node of the tree
 *
 *Return: height of the tree
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree != NULL)
	{

		if (tree->left == NULL && tree->right == NULL)
			return (0);
		left = 1 + tree_height(tree->left);
		right = 1 + tree_height(tree->right);

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
 *binary_tree_balance - measure the balance factor of a tree
 *@tree: pointer to the root node of the tree
 *
 *Return: balance factor, or 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		int left, right;

		left = 0;
		right = 0;

		if (tree->left != NULL)
			left = 1 + tree_height(tree->left);
		if (tree->right != NULL)
			right = 1 + tree_height(tree->right);
		return (left - right);
	}
	return (0);
}
