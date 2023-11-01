#include "binary_trees.h"


/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left;
	size_t right;
	size_t size;

	if (tree != NULL)
	{
		left = binary_tree_size(tree->left);
		right = binary_tree_size(tree->right);

		size = left + right + 1;
		return (size);
	}
	else
	{
		return (0);
	}
}
