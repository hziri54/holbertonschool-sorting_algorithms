#include "sort.h"

/**
 * bubble_sort - Trie un tableau d'int dans
 * l'ordre croissant à l'aide du tri à bulles
 * @array : pointeur sur un tableau trié
 * @size : nombre d'éléments dans le tableau.
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int tmp = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
