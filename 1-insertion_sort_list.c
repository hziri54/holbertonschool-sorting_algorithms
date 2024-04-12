#include "sort.h"

/*
 * insertion_sort_list - Trie une liste doublement chaînée d'entiers dans l'ordre croissant
 * @list: Un pointeur sur la tête d'une liste double
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			prev = current->prev;
			print_list(*list);
		}

		current = temp;
	}
}
