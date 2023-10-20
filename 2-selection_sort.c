#include "sort.h"

/**
 * selection_sort - Repeatedly select the minimum element and swap.
 * @array: The provided array to sort.
 * @size: The size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest;
	int idx;
	int flag;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];
		flag = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				idx = j;
				flag = 1;
			}
		}

		if (flag == 1)
		{
			array[idx] = array[i];
			array[i] = smallest;
			print_array(array, size);
		}
	}
}
