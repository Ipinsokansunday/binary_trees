#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 *
 * Description: This function counts the number of nodes in a binary tree that
 *              have at least one child (either left child,right child or both)
 *              If the tree is empty (tree is NULL), the function returns 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree != NULL)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
