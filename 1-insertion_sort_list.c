#include "sort.h"

/**
 * insertion_sort_list - Trie une liste doublement
 * chaînée d'entiers dans l'ordre
 * croissant en utilisant l'algorithme de tri par insertion.
 *
 * @list: pointeur sur un pointeur vers la tête de la liste chaînée.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *element_courant = NULL,
			  *element_a_inserer = NULL,
			  *element_suivant = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;

	element_a_inserer = (*list)->next;
	while (element_a_inserer != NULL)
	{
		element_suivant = element_a_inserer->next;
		element_courant = element_a_inserer->prev;

		while (element_courant != NULL && element_courant->n > element_a_inserer->n)
		{
			if (element_courant->prev != NULL)
				element_courant->prev->next = element_a_inserer;

			if (element_a_inserer->next != NULL)
				element_a_inserer->next->prev = element_courant;

			element_courant->next = element_a_inserer->next;
			element_a_inserer->prev = element_courant->prev;
			element_courant->prev = element_a_inserer;
			element_a_inserer->next = element_courant;

			if (*list == element_courant)
				*list = element_a_inserer;

			print_list(*list);

			element_courant = element_a_inserer->prev;
		}
		element_a_inserer = element_suivant;
	}
}
