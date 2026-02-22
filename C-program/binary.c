#include <stdio.h>
#include <stdlib.h>
#include "type.h"

void bubbleSort(u32 *array, u32 length);
int binarySearch(const u32 *array, u32 length, u32 value);

int main(void)
{
    u32 n, value;

    printf("Enter number of elements (max 100): ");
    if (scanf("%u", &n) != 1 || n == 0 || n > 100)
        return EXIT_FAILURE;

    u32 array[100];

    for (u32 i = 0; i < n; ++i) {
        printf("A[%u]: ", i);
        if (scanf("%u", &array[i]) != 1)
            return EXIT_FAILURE;
    }

    bubbleSort(array, n);

    printf("Enter value to search: ");
    if (scanf("%u", &value) != 1)
        return EXIT_FAILURE;

    int result = binarySearch(array, n, value);

    if (result == -1)
        printf("Value not found.\n");
    else
        printf("Value found at index: %d\n", result);

    return EXIT_SUCCESS;
}

void bubbleSort(u32 *array, u32 length)
{
    for (u32 i = 0; i < length - 1; ++i)
        for (u32 j = 0; j < length - i - 1; ++j)
            if (array[j] > array[j + 1]) {
                u32 temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}

int binarySearch(const u32 *array, u32 length, u32 value)
{
    int left = 0;
    int right = (int)length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == value)
            return mid;
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}