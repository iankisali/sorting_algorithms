#include "sort.h"

/**
 * swap - swaps two values
 * @array: array to swap values
 * @num1: first no to swap
 * @num2: second no to swap
 */
void swap(int *array, int num1, int num2)
{
	int temp;

	if (array[num1] != array[num2])
	{
		temp = array[num1];
		array[num1] = array[num2];
		array[num2] = temp;
	}
}

/**
 * shell_sort - sort list in ascending using shell sort
 * @array: array to sort
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 0, i, j;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;
	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				swap(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
