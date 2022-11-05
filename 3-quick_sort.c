#include "sort.h"

/**
 * swap - swap two items in array
 * @array: array
 * @num1: first num to swap
 * @num2: second num to swap
 */
void swap(int *array, size_t num1, size_t num2)
{
	int temp;

	if (array != NULL)
	{
		temp = array[num1];
		array[num1] = array[num2];
		array[num2] = temp;
	}
}

/**
 * lomuto_partition - sorts using Lomuto's partition scheme
 * @array: array to have sub-array
 * @low: starting of sub-array
 * @high: ending of sub-array
 * @size: length of array
 */
void lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t k, i;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	k = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (k != i)
			{
				swap(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}
	if (k != high)
	{
		swap(array, k, high);
		print_array(array, size);
	}
	if (k - low > 1)
		lomuto_partition(array, low, k - 1, size);
	if (high - k > 1)
		lomuto_partition(array, k + 1, high, size);
}

/**
 * quick_sort - sort array using quick sort algo
 * @array: array to sort
 * @size: length of array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
		lomuto_partition(array, 0, size - 1, size);
}
