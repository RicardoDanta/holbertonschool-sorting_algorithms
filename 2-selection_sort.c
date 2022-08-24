#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of @array
 */

void selection_sort(int *array, size_t size)
{
	unsigned long int i, nextInitialPos = 0;
	int current_smaller_pos = 0;


	/* as many times until the array is sorted*/
	for (; nextInitialPos < size; nextInitialPos++)
	{
		current_smaller_pos = nextInitialPos;
		/*searches for the smaller number*/
		for (i = nextInitialPos; i < size; i++)
		{
			if (array[i] < array[current_smaller_pos])
			{
				current_smaller_pos = i;
			}
		}
		swap_ints(array, nextInitialPos, current_smaller_pos);
		print_array(array, size);
	}
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
