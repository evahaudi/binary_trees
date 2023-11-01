#include "binary_trees.h"

/**
 *binary_tree_nodes - counts the nodes with at least 1 child in
 * a binary tree
 *@tree: pointer to the root node of the tree to count
 *
 *Return: no. of nodes with at least 1 child
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left;
	size_t right;
	size_t children;

	if (tree != NULL)
	{
		left = binary_tree_nodes(tree->left);
		right = binary_tree_nodes(tree->right);

		children = left + right;
		if (!(tree->left == NULL && tree->right == NULL))
			children++;
		return (children);
	}
	else
	{
		return (0);
	}
}
