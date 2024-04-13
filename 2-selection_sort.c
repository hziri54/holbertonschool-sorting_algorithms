#include "sort.h"

/**
 * selection_sort - Trie un tableau d'entiers dans l'ordre croissant
 * en utilisant l'algorithme de tri par sélection.
 *
 * @tableau: pointeur vers le tableau à trier.
 * @taille: taille du tableau.
 */
void selection_sort(int *tableau, size_t taille)
{
	size_t i, j, indice_min;
	int temp;

	for (i = 0; i < taille - 1; i++)
	{
		indice_min = i;
		for (j = i + 1; j < taille; j++)
		{
			if (tableau[j] < tableau[indice_min])
				indice_min = j;
		}

		if (indice_min != i)
		{
			temp = tableau[i];
			tableau[i] = tableau[indice_min];
			tableau[indice_min] = temp;
			print_array(tableau, taille);
		}
	}
}
