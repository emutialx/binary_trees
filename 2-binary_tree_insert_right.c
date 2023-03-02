#include "binary_trees.h"
/**
  * binary_tree_insert_right - inserts node as right-child of another node
  *
  * @parent: pointer to the node to insert the right-child in
  * @value: value to store in the new node
  * Return: a pointer to the created node,
  * or NULL on failure or if parent is NULL
  */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *pright = NULL;
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	pright = parent->right;
	parent->right = new_node;

	if (pright)
	{
		pright->parent = new_node;
		new_node->right = pright;
	}
	return (new_node);
}
