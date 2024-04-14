#include "sort.h"

/**
 * quick_sort - Trie un tableau d'entiers dans l'ordre croissant
 * en utilisant l'algorithme de tri rapide (Quick sort).
 *
 * @tableau: pointeur vers le tableau à trier.
 * @taille: taille du tableau.
 */
void quick_sort(int *tableau, size_t taille)
{
	quick_sort_recursif(tableau, 0, taille - 1);
}

/**
 * quick_sort_recursif - Fonction récursive pour trier un tableau
 * d'entiers dans l'ordre croissant en utilisant l'algorithme de
 * tri rapide (Quick sort).
 *
 * @tableau: pointeur vers le tableau à trier.
 * @debut: indice du premier élément du sous-tableau à trier.
 * @fin: indice du dernier élément du sous-tableau à trier.
 */
void quick_sort_recursif(int *tableau, int debut, int fin)
{
	int pivot, i, j, temp;

	if (debut < fin)
	{
		pivot = tableau[fin];
		i = debut - 1;

		for (j = debut; j < fin; j++)
		{
			if (tableau[j] < pivot)
			{
				i++;
				temp = tableau[i];
				tableau[i] = tableau[j];
				tableau[j] = temp;
			}
		}

		i++;
		temp = tableau[i];
		tableau[i] = tableau[fin];
		tableau[fin] = temp;
		print_array(tableau, fin - debut + 1);

		quick_sort_recursif(tableau, debut, i - 1);
		quick_sort_recursif(tableau, i + 1, fin);
	}
}
