#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, your function must return 0,else return the depth.
 *
 * Description: This function measures the depth of a given node in a binary
 *		tree.If the node is NULL or if it is the root of
 *              the tree (has no parent),
 *		the function returns 0. Otherwise, it recursively calculates
 *		the depth of the parent node and adds 1 to the result.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
