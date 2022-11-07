#include "sort.h"
/**
 * swap - swapping two values
 * @array: array
 * @num1: first no to swap
 * @num2: second no to swap
 * @order: order to sort
 */
void swap(int array[], int num1, int num2, int order)
{
	int temp;

	if (order == (array[num1] > array[num2]))
	{
		temp = array[num1];
		array[num1] = array[num2];
		array[num2] = temp;
	}
}

/**
 * merge - merging two
 * @array: array
 * @low: first element
 * @element: element number
 * @order: order
 */
void merge(int array[], int low, int element, int order)
{
	int mid, i;

	if (element > 1)
	{
		mid = element / 2;
		for (i = low; i < low + mid; i++)
			swap(array, i, i + mid, order);
		merge(array, low, mid, order);
		merge(array, low + mid, mid, order);
	}
}

/**
 * bitonicsort - sorting algorithm
 * @array: array
 * @low: first element
 * @element: no of elements
 * @order: order to sort
 * @size: array size
 */
void bitonicsort(int array[], int low, int element, int order, int size)
{
	int mid;

	if (element > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", element, size);
			print_array(&array[low], element);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", element, size);
			print_array(&array[low], element);
		}
		mid = element / 2;
		bitonicsort(array, low, mid, 1, size);
		bitonicsort(array, low + mid, mid, 0, size);
		merge(array, low, element, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", element, size);
			print_array(&array[low], element);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", element, size);
			print_array(&array[low], element);
		}
	}
}

/**
 * bitonic_sort - sorting
 * @array: array to sort
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, 1, size);
}
