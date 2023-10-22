#include "sort.h"

size_t i = 1, j = 0; /*i is for accessing the array from the end, j is the opposite*/
int pivot;
int current;
int rule = 0; /*a switch from 0 to 1*/

void rule0(int *array, size_t size);
void rule1(int *array, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick Sort algorithm.
 * 
 * @array: the array to sort.
 * @size: the size of the array.
*/
void quick_sort(int *array, size_t size)
{
    pivot = array[size - i]; /*Declaring the pivot*/
    current = array[j];

    while(1)
    {
        if (j + i == size)
        {
            return;
        }

        if (rule == 0)
            rule0(array, size);

        if (rule == 1)
            rule1(array, size);
    }
}

/**
 * rule0 - This rule applies Initially, or after a second switch.
 * @array: the array to sort.
 * @size: the size of the array.
*/
void rule0(int *array, size_t size)
{
    if (current <= pivot)
    {
        i++;
        pivot = array[size - i];
    }
    else if (current > pivot)
    {
        array[j] = pivot;
        array[size - i] = current;
        print_array(array, size);

        j++;
        pivot = array[j];

        rule = 1;
    }
}

/**
 * rule1 - This rule applies after a switch.
 * @array: the array to sort.
 * @size: the size of the array.
*/
void rule1(int *array, size_t size)
{
    if (pivot < current)
    {
        j++;
        pivot = array[j];
    }
    else if (pivot > current)
    {
        array[j] = current;
        array[size - i] = pivot;
        print_array(array, size);

        i++;
        pivot = array[size - i];

        rule = 0;
    }
}