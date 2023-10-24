#include "sort.h"

void new_split(int *new_arr, size_t size, int *pv, int *cur);
void get_pv(int *new_arr, size_t size,int *pv);
void get_cur(int *new_arr, int *cur);


/**
 * quick_sort - Sorts an array of integers in ascending order
 *				using the Quick Sort algorithm.
 * @array: The provided array to sort.
 * @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	int *new_arr = malloc(size * sizeof(int));
	int cur = 0;
	int swap = -1;
	int pv = size - 1;
	int tmp;
	int pv_tmp = pv;


	while (cur != 11)
	{
		if (array[cur] > array[pv])
			cur++;
		else if (array[cur] <= array[pv])
		{
			
			swap++;
			if (array[cur] < array[swap])
			{
				tmp = array[cur];
				array[cur] = array[swap];
				array[swap] = tmp;
				print_array(array, size);

				if (cur == pv)
				{
					pv = swap;
					new_arr[swap] = swap + 1;
					//print_array(new_arr, size);
					if (pv != pv_tmp)
					{
						new_split(new_arr, size, &pv, &cur);
						
					}
				}
			}
			else if (array[cur] == array[swap])
				cur++;	
		}		
	}
}

void new_split(int *new_arr, size_t size, int *pv, int *cur)
{
	int k = size;
	int flag = 0;
	int tmp;
	if ((*pv) - 1 >= 0 && new_arr[(*pv) - 1] == 0)
	{
		(*pv)--;
		*cur = *pv;

		printf("hello from left %d\n", (*pv));
		get_cur(new_arr, cur);
		printf("\n%d\n", *cur);
		if ((*cur) == (*pv))
		{
			new_arr[(*cur)] = (*cur) + 1;	
		}
		else
		{
			flag = 1;
		}
		
	}
	if ((*pv) + 1 < k && new_arr[(*pv) + 1] == 0)
	{
		if (flag == 1)
		{
			tmp = *pv + 1;
		}
		else
		{
			(*pv)++;
			*cur = *pv;
		}

		printf("hello from right %d\n", (*pv));
		get_pv(new_arr, size, pv);
		
	}
	else
	{
		*cur = 11;
	}
	
	
	
}


void get_pv(int *new_arr, size_t size,int *pv)
{
	int k = size;
	while ((*pv) + 1 < k && new_arr[(*pv) + 1] == 0)
	{
		(*pv)++;
	}
}

void get_cur(int *new_arr, int *cur)
{
	while ((*cur) - 1 >= 0 && new_arr[(*cur) - 1] == 0)
	{
		(*cur)++;
	}
}