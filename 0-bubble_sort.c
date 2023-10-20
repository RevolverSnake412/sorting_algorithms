#include "sort.h"

/**
 * bubble_sort - compares adjacent elements, swaps if needed,
 *				repeats until sorted.
 * @array: Provided array to sort.
 * @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				continue;
			}
		}
	}
}
