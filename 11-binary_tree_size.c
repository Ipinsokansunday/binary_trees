#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 *
 * Description: This function measures the size of a binary tree starting
 *              from the given root node. If the tree is empty (tree is NULL),
 *              the function returns 0. Otherwise, it recursively calculates
 *              the size of the left and right subtrees and adds 1 (for the
 *              current node) to the sum of the sizes of the left and right
 *              subtrees.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
