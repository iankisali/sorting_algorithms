#include "sort.h"

/**
 * merge_subarr - sort subarray of int
 * @subarr: subarray of array
 * @buff: store sorted array
 * @front: fornt index of array
 * @mid: middle index of array
 * @back: back index of array
 */
void merge_subarr(int *subarr, int *buff, size_t front,
		size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);
	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_recursively - merging using recursion
 * @subarr: subarray of array
 * @buff: buffer to store sorted
 * @front: front index of subarray
 * @back: back index of subarray
 */
void merge_recursively(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_recursively(subarr, buff, front, mid);
		merge_recursively(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - sorting array of int using merger sort
 * @array: array of int
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	merge_recursively(array, buff, 0, size);
	free(buff);
}
