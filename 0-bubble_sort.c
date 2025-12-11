#include "sort.h"

/**
 * bubble_sort - Sorts an array using bubble sort
 * @array: Array of integers
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int tmp, swapped;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swapped = 1;
                print_array(array, size);
            }
        }

        if (!swapped)
            break;
    }
}
