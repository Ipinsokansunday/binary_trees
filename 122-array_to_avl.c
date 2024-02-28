#include "binary_trees.h"

/**
 * array_to_avl - Constructs an AVL tree from an array of integers.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Returns: A pointer to the root node of the constructed AVL tree.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL)
		return (NULL);

	for (size_t i = 0; i < size; i++)
	{
		size_t j;

		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
