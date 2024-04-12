#include "sort.h"
/**
 * swap - echange deux éléments dans un tableau
 * @array: tableau contenant des éléments
 * @i: index du premier élément.
 * @j: indice du deuxième élément.
 */
void swap(int *array, size_t i, size_t j)
{
	/* vne variable temporaire stocke la valeur à l'index i */
	int temp = array[i];
	/* valeur de l'indice j affectée à l'indice i */
	array[i] = array[j];
	/* valeur stockée dans la variable temporaire affectée à l'index j */
	array[j] = temp;
}
/**
 * selection_sort - trie un tableau d'entiers par ordre croissant.
 * @array: tableau à trier.
 * @size: initialise la taille
 *
 * Description: Uses the Selection sort algorithm.
 */
void selection_sort(int *array, size_t size)
{
	/* variables pour l'index courant, l'index de la boucle intérieure et l'index de la valeur minimale */
	size_t i, j, min_index;
	/* boucle sur chaque élément du tableau à l'exception du dernier */
	for (i = 0; i < size - 1; i++)
	{
		/* l'indice actuel est l'indice de la valeur minimale */
		min_index = i;
		/* boucle sur le reste du tableau */
		for (j = i + 1; j < size; j++)
		{
			/* si l'élément actuel est inférieur au minimum supposé, mettre à jour l'indice minimum */
			if (array[j] < array[min_index])
				min_index = j;
		}
		/* si l'élément actuel est inférieur au minimum supposé, mettre à jour l'indice minimum */
		if (min_index != i)
		{
			/* remplacer l'élément actuel par l'élément minimum trouvé */
			swap(array, i, min_index);
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
