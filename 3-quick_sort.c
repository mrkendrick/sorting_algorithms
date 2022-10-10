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
 * partition - function to divide the array
 * @array: array
 * @low: left part of the pivot
 * @high: right part of the pivot
 * @size: size of the array
 * Return: pivot index
*/

int partition(int *array, int low, int high, size_t size)
{
	/**
	 * int pivot, i, j;
	 * pivot = array[high];
	 * i = low - 1;
	 * for (j = low; j <= high - 1; j++)
	 * {
	 * if (array[j] < pivot)
	 * {
	 * i++;
	 * swap(&(array[i]), &(array[j]));
	 * print_array(array, size);
	 * }
	 * }
	 * swap(&(array[i + 1]), &(array[high]));
	 * print_array(array, size);
	 * return (i + 1);
	 */
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * sort - sorts an array
 * @array: array to be sorted
 * @low: left part of pivot
 * @high: right part of pivot
 * @size: size of the array
 * Return: void
*/

void sort(int *array, int low, int high, size_t size)
{
	int i;

	if (low >= high || low < 0)
		return;
	i = partition(array, low, high, size);
	sort(array, low, i - 1, size);
	sort(array, i + 1, high, size);
}

/**
 * quick_sort - quick sort implementation on an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	if (size > 1)
	{
		sort(array, 0, size - 1, size);
	}
}
