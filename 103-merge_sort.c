#include "sort.h"

/**
 * merge - merging arrays
 * @array: array to merge
 * @start: start of array
 * @middle: array middle
 * @end: array end
 */
void merge(int *array, int start, int middle, int end)
{
	int l1, l2, l3, l4 = 0;
	int size1 = middle - start + 1, size2 = end - middle;
	int temp1[4096], temp2[4096];
	int *temp3 = malloc(sizeof(int) * (size1 + size2));

	for (l1 = 0, l2 = 0; l1 < size1 || l2 < size2; l1++, l2++)
	{
		temp1[l1] = array[start + l1];
		temp2[l2] = array[middle + 1 + l2];
	}
	for (l1 = l2 = 0, l3 = start; l1 < size1 && l2 < size2; l3++)
		if (temp1[l1] <= temp2[l2])
			array[l3] = temp3[l4++] = temp1[l1++];
		else
			array[l3] = temp3[l4++] = temp2[l2++];

	printf("Merging...\n[left]: ");
	print_array(temp1, size1);
	printf("[right]: ");
	print_array(temp2, size2);

	while (l1 < size1)
		array[l3++] = temp3[l4++] = temp1[l1++];
	while (l2 < size2)
		array[l3++] = temp3[l4++] = temp1[l2++];

	printf("[Done]: ");
	print_array(temp3, size1 + size2);
	free(temp3);
}

/**
 * sort - sort array and merge
 * @array: array to sort
 * @start: stary af arry
 * @end: array end
 */
void sort(int *array, int start, int end)
{
	int middle;

	if (start < end)
	{
		middle = (start + end - 1) / 2;
		sort(array, start, middle);
		sort(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}

/**
 * merge_sort - perfoming merger sort
 * @array: array of int to sort
 * @size: size af array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1);
}
