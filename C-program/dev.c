#include <stdio.h>
#include "type.h"

#define n 10

void msort(u32 x[], u32 temp[], u32 left, u32 right);
void merge(u32 x[], u32 temp[], u32 left, u32 mid, u32 right);

int main(void)
{
    u32 x[n], temp[n], i;

    printf("Merge sort\n");
    printf("Enter the 10 numbers:\n");

    for(i = 0; i < n; i++)
    {
        printf("A[%u]: ", i + 1);
        scanf("%u", &x[i]);
    }

    msort(x, temp, 0, n - 1);

    printf("\nThe sorted array is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%u ", x[i]);
    }

    return 0;
}

void msort(u32 x[], u32 temp[], u32 left, u32 right)
{
    u32 mid;

    if(left < right)
    {
        mid = (left + right) / 2;
        msort(x, temp, left, mid);
        msort(x, temp, mid + 1, right);
        merge(x, temp, left, mid + 1, right);
    }
}

void merge(u32 x[], u32 temp[], u32 left, u32 mid, u32 right)
{
    u32 i, left_end, temp_pos, num_elements;

    left_end = mid - 1;
    temp_pos = left;
    num_elements = right - left + 1;

    while(left <= left_end && mid <= right)
    {
        if(x[left] <= x[mid])
            temp[temp_pos++] = x[left++];
        else
            temp[temp_pos++] = x[mid++];
    }

    while(left <= left_end)
        temp[temp_pos++] = x[left++];

    while(mid <= right)
        temp[temp_pos++] = x[mid++];

    for(i = 0; i < num_elements; i++)
    {
        x[right] = temp[right];
        right--;
    }
}
