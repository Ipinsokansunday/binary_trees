#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function.
 *
 * Description: This function traverses the binary tree using pre-order
 *		traversal,starting from the given root node. For each
 *		node visited, it calls the function pointed to by func
 *		and passes the value of the node as a parameter. If the
 *		input tree pointer or the function pointer is NULL, the function
 *		does nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n); /* Call function with the value of current node */

	binary_tree_preorder(tree->left, func); /* Traverse left subtree */
	binary_tree_preorder(tree->right, func); /* Traverse right subtree */
}
