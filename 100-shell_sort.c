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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (size > 1)
	{

		for (gap = 1; gap < (size / 3);)
			gap = gap * 3 + 1;

		for (; gap >= 1; gap /= 3)
		{
			for (i = gap; i < size; i++)
			{
				j = i;
				while (j >= gap && array[j - gap] > array[j])
				{
					swap(array + j, array + (j - gap));
					j -= gap;
				}
			}
			print_array(array, size);
		}
	}
}
