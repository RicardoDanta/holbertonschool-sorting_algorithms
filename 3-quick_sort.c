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

	recursion(array, 0, size - 1, size);
}

/**
 * recursion - recursion
 *
 * @array: array
 * @l: first value
 * @r: last value
 */

void recursion(int *array, int l, int r, size_t size)
{
	int i;

	if (l >= r)
		return;

	i = partition(array, l, r, size);
	recursion(array, l, i - 1, size);
	recursion(array, i + 1, r, size);
}

/**
 * swap_ints - swaps integrers position of an array
 *
 * @array: array
 * @int_posA: int A pos
 * @int_posB: int B pos
 */

void swap_ints(int *array, int int_posA, int int_posB)
{
	int aux;

	aux = array[int_posA];
	array[int_posA] = array[int_posB];
	array[int_posB] = aux;
}



/**
 * partition - lomuto partition scheme
 *
 * @array: array
 * @l: first element
 * @r: last element
 * Return: int
 */
int partition(int *array, int l, int r, size_t size)
{
	int pivot = array[r];
	int i = l;

	for (int j = l; j < r; ++j)
	{
		if (array[j] < pivot)
		{
			swap_ints(array, i, j);
			print_array(array, size);
			++i;
		}
		}
	swap_ints(array, i, r);
	print_array(array, size);

	return (i);
}
