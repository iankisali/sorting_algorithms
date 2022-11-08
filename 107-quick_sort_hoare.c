#include "sort.h"
/**
 * swap - swapping two elements
 * @array: array
 * @num1: first element to swap
 * @num2: second lement
 */
void swap(int *array, ssize_t num1, ssize_t num2)
{
	int temp;

	temp = array[num1];
	array[num1] = array[num2];
	array[num2] = temp;
}

/**
 * hoare_partition - hoare partition sorting scheme implementation
 * @array: array
 * @first: first element inarray
 * @last: last element in array
 * @size: array size
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, f = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			f--;
		} while (array[f] > pivot);
		if (current >= f)
			return (current);
		swap(array, current, f);
		print_array(array, size);
	}
}

/**
 * quick_sort - quick sort
 * @array: array
 * @first: first element in array
 * @last: last element in array
 * @size: size of array
 */
void quick_sorting(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t pos = 0;

	if (first < last)
	{
		pos = hoare_partition(array, first, last, size);
		quick_sorting(array, first, pos - 1, size);
		quick_sorting(array, pos, last, size);
	}
}

/**
 * quick_sort_hoare - quick sort using hoare
 * @array: array
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sorting(array, 0, size - 1, size);
}
