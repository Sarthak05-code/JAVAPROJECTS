#include <stdio.h>
#include <stdlib.h>
#include "type.h"

int linearSearch(const u32 *array , u32 length , u32 value){
    for(u32 i = 0 ; i < length ; i++)
    {
        if(array[i] == value){
            return i;
        }
    }
    return -1;
}

int main()
{
    system("cls");
    u32 array[10];
    u32 n;

    printf("Enter how many values you want: ");
    scanf("%u" , &n);

    for(u32 i = 0 ; i < n ; i++)
    {
        printf("a[%u]: ", i);
        scanf("%u" , &array[i]);
    }

    u32 value;
    printf("Which value do you want to search: ");
    scanf("%u", &value);

    int found = linearSearch(array , n , value);

    if(found == -1){
        printf("Value not found\n");
    }
    else{
        printf("Value Found at index: %d\n" , found);
    }

    return 0;
}