#include "sort.h"

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the whole array
 *
 * Return: index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
            i++;
        }
    }

    if (array[i] != array[high])
    {
        temp = array[i];
        array[i] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i);
}

/**
 * quicksort_rec - recursive quicksort helper
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: total size of array
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);
        quicksort_rec(array, low, pivot - 1, size);
        quicksort_rec(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array in ascending order using Quick sort
 *              (Lomuto partition scheme)
 * @array: array of integers to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_rec(array, 0, size - 1, size);
}
