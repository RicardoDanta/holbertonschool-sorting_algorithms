#include "sort.h"

/**
 * bubble_sort - function that sorts an array
 * of integers in ascending order
 * @array: array to be printed
 * @size: number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t aux;

	if (array == 0)
		return;

	for (; i < size - 1; ++i)
	{
		for (; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j + 1];
				array[j + 1] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
}
