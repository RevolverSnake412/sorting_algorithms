#include "sort.h"

int first_rule(int *array, size_t size, size_t *i, size_t *j, int *pivot);
int second_rule(int *array, size_t size, size_t *i, size_t *j, int *pivot);

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
			rule = first_rule(array, size, &i, &j, &pivot);
		}

		/*The second rule of Quick sort*/
		if (rule == 1)
		{
			rule = second_rule(array, size, &i, &j, &pivot);
		}
	}
}

/**
 * first_rule - Called Initially or after a second swap.
 * @array: the array to sort.
 * @size: the size of the array.
 * @i: index selector from the end.
 * @j: index selector from the beginning.
 * @pivot: the pivot's value.
*/
int first_rule(int *array, size_t size, size_t *i, size_t *j, int *pivot)
{
    int current = array[*j];
	if (current <= *pivot)
	{
		(*i)++;
		*pivot = array[size - (*i)];
	}
	else if (current > *pivot)
	{
		array[*j] = *pivot;
		array[size - (*i)] = current;
		print_array(array, size);
		(*j)++;
		*pivot = array[*j];
		return 1;
	}
	return 0;
}

/**
 * second_rule - Called after the initial swap.
 * @array: the array to sort.
 * @size: the size of the array.
 * @i: index selector from the end.
 * @j: index selector from the beginning.
 * @pivot: the pivot's value.
*/
int second_rule(int *array, size_t size, size_t *i, size_t *j, int *pivot)
{
    int current = array[size - (*i)];
	if (*pivot < current)
	{
		(*j)++;
		*pivot = array[*j];
	}
	else if (*pivot > current)
	{
		array[*j] = current;
		array[size - (*i)] = *pivot;

		print_array(array, size);

		(*i)++;
		*pivot = array[size - (*i)];
		return 0;
	}
	return 1;
}
