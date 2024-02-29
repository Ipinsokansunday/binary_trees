#include "binary_trees.h"

/**
 * balance_factor - Measures balance factor of an AVL tree
 * @tree: Pointer to the root of the tree
 * Return: Balance factor of the tree
 */
void balance_factor(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance_factor(&(*tree)->left);
	balance_factor(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor - Finds the successor of a node in a BST
 * @node: Pointer to the node
 * Return: The value of the successor node
 */
int get_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = get_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 * remove_node - Removes a node from a BST depending on its children
 * @root: Pointer to the node to remove
 * Return: 0 if it has no children, otherwise returns a new value
 */
int remove_node(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = get_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a BST tree
 * @root: Pointer to the root of the tree
 * @value: Value of the node to remove
 * Return: The updated tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root of the tree
 * @value: Value of the node to remove
 * Return: The updated tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balance_factor(&root_a);
	return (root_a);
}
