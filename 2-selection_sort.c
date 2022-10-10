#include "sort.h"

/**
 * swap - swaps two array elements
 * @a: first element
 * @b: second element
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp1, temp2;

	temp1 = *a;
	temp2 = *b;
	*a = temp2;
	*b = temp1;
}

/**
 * selection_sort - implements selection sort on an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			min_index = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min_index])
				{
					min_index = j;
				}
			}
			if (min_index != i)
			{
				swap(&(array[i]), &(array[min_index]));
				print_array(array, size);
			}
		}
	}
}
