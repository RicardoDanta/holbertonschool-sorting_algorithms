#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integrers
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int aux, flag;
	size_t i;

	if (array == NULL)
		return;

	/* iterates as many times as necessary until the array is sorted */
	for (flag = 0; 1; flag = 0)
	{
		/* runs through the array */
		for (i = 0; i < size - 1; i++)
		{
			/* swaps the elements if the second one is smaller */
			if (array[i + 1] < array[i])
			{
				aux = array[i + 1];
				array[i + 1] = array[i];
				array[i] = aux;
				flag = 1; /* if any swap was made */
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
