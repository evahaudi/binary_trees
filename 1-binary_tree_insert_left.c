#include "binary_trees.h"

/**
 *binary_tree_insert_left - inserts a node as the left-child of another node
 *@parent: parent node
 *@value: value to store in the left_child
 *
 *Return: a pointer to the created node or null if it failed
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left = NULL;

	new_left = malloc(sizeof(binary_tree_t));
	if (!new_left)
		return (NULL);
	new_left->n = value;
	new_left->right = NULL;
	new_left->left = NULL;

	if (!parent)
	{
		free(new_left);
		return (NULL);
	}
	new_left->parent = parent;
	if (parent->left)
	{
		new_left->left = parent->left;
		new_left->left->parent = new_left;
	}
	parent->left = new_left;
	return (new_left);
}
