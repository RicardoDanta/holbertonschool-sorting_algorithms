#include "sort.h"

/**
 * quick_sort - sorts an array of integrers using the quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of @array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	recursion(array, 0, size - 1);
}

/**
 * recursion - recursion
 *
 * @array: array
 * @l: first value
 * @r: last value
 */

void recursion(int *array, int l, int r)
{
	int i;

	if (l >= r)
		return;

	i = partition(array, l, r);
	recursion(array, l, i - 1);
	recursion(array, i + 1, r);
}

/**
 * swap - swaps integrers position of an array
 *
 * @i: int A pos
 * @j: int B pos
 */

void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}


/**
 * partition - lomuto partition scheme
 *
 * @arr: array
 * @l: first element
 * @r: last element
 * Return: int
 */
int partition(int *arr, int l, int r)
{
	int pivot = arr[r];
	int i = l;

	for (int j = l; j < r; ++j)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			++i;
		}
		}
	swap(&arr[i], &arr[r]);

	return (i);
}
