#include "binary_trees.h"
/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node on (Success), or NULL on (Failure).
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandad, *luncle, *runcle;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	parent = node->parent;
	grandad = parent->parent;
	luncle = grandad->left;
	runcle = grandad->right;

	if (parent == grandad->left && runcle == grandad->right)
		return (runcle);
	else if (parent == grandad->right && luncle == grandad->left)
		return (luncle);
	return (NULL);
}
