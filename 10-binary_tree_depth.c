#include "binary_trees.h"

/* Helper function to compute depth of the leftmost leaf */
static size_t _tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/* Helper function to check perfection recursively */
static int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (depth == level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
			is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = _tree_depth(tree);
	return (is_perfect(tree, depth, 0));
}
