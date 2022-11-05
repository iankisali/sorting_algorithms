#include "sort.h"

/**
 * selection_sort - sorts int list using selsction
 * @array: array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, step, min;
	int temp;

	for (step = 0; step < size - 1; step++)
	{
		min = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[min])
				min = i;
		}
		if (min != step)
		{
			temp = array[step];
			array[step] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
