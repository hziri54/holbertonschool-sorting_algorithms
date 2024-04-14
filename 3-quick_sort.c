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
	if (taille < 2)
		return;

	quick_sort_recursif(tableau, 0, taille - 1, taille);
}

/**
 * quick_sort_recursif - Fonction récursive pour trier un tableau
 * d'entiers dans l'ordre croissant en utilisant l'algorithme de
 * tri rapide (Quick sort).
 *
 * @tableau: pointeur vers le tableau à trier.
 * @debut: indice du premier élément du sous-tableau à trier.
 * @fin: indice du dernier élément du sous-tableau à trier.
 * @taille: taille du tableau.
 */

void quick_sort_recursif(int *tableau, int debut, int fin, size_t taille)
{
	if (debut < fin)
	{
		int partition = partition_lomuto(tableau, debut, fin, taille);

		quick_sort_recursif(tableau, debut, partition - 1, taille);
		quick_sort_recursif(tableau, partition + 1, fin, taille);
	}
}

/**
 * partition_lomuto - Partitionne le tableau selon le schéma de
 * partition de Lomuto pour l'algorithme de tri rapide (Quick sort).
 *
 * @tableau: pointeur vers le tableau à trier.
 * @debut: indice du premier élément du sous-tableau à trier.
 * @fin: indice du dernier élément du sous-tableau à trier.
 * @taille: taille du tableau.
 * Return: Indice du pivot après partitionnement.
 */

int partition_lomuto(int *tableau, int debut, int fin, size_t taille)
{
	int pivot = tableau[fin];
	int i = debut - 1;

	for (int j = debut; j < fin; j++)
	{
		if (tableau[j] < pivot)
		{
			i++;
			int temp = tableau[i];

			tableau[i] = tableau[j];
			tableau[j] = temp;
			print_array(tableau, taille);
		}
	}
	int temp = tableau[i + 1];

	tableau[i + 1] = tableau[fin];
	tableau[fin] = temp;
	print_array(tableau, taille);
	return (i + 1);
}
