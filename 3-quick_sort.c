#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *				using the Quick Sort algorithm.
 * @array: The provided array to sort.
 * @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	size_t i = 1, j = 0;
	int pivot = array[size - i];
	int current = array[j];
	int rule = 0;

	/*
		* Currently using an infinite while loop,
		* don't worry about it.
	*/
	while (1)
	{
		/*The if statement when pivot and current will be on the same item*/
		if (i + j == size)
		{
			return;
		}

		/*The first rule of Quick sort*/
		if (rule == 0)
		{
			if (current <= pivot)
			{
				/*Shift the pv to the left*/
				i++;
				pivot = array[size - i];
			}
			else if (current > pivot)
			{
				/*Doing the swaping between pv and curr*/
				array[j] = pivot;
				array[size - i] = current;

				print_array(array, size);
				/*Shift the pv to the right*/
				j++;
				pivot = array[j];

				rule = 1;
			}
		}

		/*The second rule of Quick sort*/
		if (rule == 1)
		{
			if (pivot < current)
			{
				/*Shift the pv to the right*/
				j++;
				pivot = array[j];
			}
			else if (pivot > current)
			{
				/*Doing the swaping between pv and curr*/
				array[j] = current;
				array[size - i] = pivot;
				print_array(array, size);

				/*Shift the pv to the left*/
				i++;
				pivot = array[size - i];

				rule = 0;
			}
		}
	}
}