#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/*enumeration of boolean values*/
typedef enum bool
{
	false = 0,
	true
} bool;

/*data structure*/
/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*print list*/
void print_list(const listint_t *list);

/*print array*/
void print_array(const int *array, size_t size);

/*bubble sort*/
void bubble_sort(int *array, size_t size);

/*insertion sort*/
void insertion_sort_list(listint_t **list);

/*selection sort*/
void selection_sort(int *array, size_t size);

/*quick sort*/
void quick_sort(int *array, size_t size);

/*shell sort*/
void shell_sort(int *array, size_t size);

/* Cocktail shaker sort*/
void cocktail_sort_list(listint_t **list);

/*counting sort*/
void counting_sort(int *array, size_t size);

/*merge sort*/
void merge_sort(int *array, size_t size);

/*heap sort*/
void heap_sort(int *array, size_t size);

/*radix sort*/
void radix_sort(int *array, size_t size);

/*bitonic sort*/
void bitonic_sort(int *array, size_t size);

/*quick sort using hoare partition*/
void quick_sort_hoare(int *array, size_t size);
#endif
