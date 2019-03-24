/*
 * A basic insertion sort algorithm.
 * It uses void and funtion pointers to give it "generic-ness", meaning it will work with both char and floats!
 * The void pointer and funtion pointer are used for code reusability, as it is much shorter than writing 2 seperate algorithm
 * for comparing int and floats.
 * 
 * This genericness is achieved by the fact that with the help of void pointers, the base sorting algorithm can works with any data type.
 * And to use it for a particular datatype, the funtion pointer is used!
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/* '''''''''''''''' compare '''''''''''''''''''''''''''*/
int isBiggerInt(void* key1, void* key2)
{
    int x = *(int *)key1;
    int y = *(int *)key2;

    if( x > y)
        return 1;
    else if( x < y)
        return -1;
    else 
        return 0;
}


int isBiggerFloat( void* key1, void* key2)
{
    double x = *(double *)key1;
    double y = *(double *)key2;

    if( x > y)
        return 1;
    else if( x < y)
        return -1;
    else 
        return 0;
}

int isBiggerChar( void* key1, void* key2)
{
    char x = *(char *)key1;
    char y = *(char *)key2;

    if( x > y)
        return 1;
    else if( x < y)
        return -1;
    else 
        return 0;
}


/* ''''''''''''''' insertion sort '''''''''''' */
int inssort(void *data, int num_of_obj, int type_size, int (*comp) (void *dat1, void *dat2))
{
    char *arr = (char *)data;
    void *key;
    int unsorted,sorted;
    key = (char *)malloc(type_size);
        if(key == NULL)
            return 100;

    for( unsorted = 1; unsorted < num_of_obj; unsorted++)
    {
        memcpy(key, &arr[type_size * unsorted], type_size); //copies the current value to the key.
        sorted = unsorted -1;

        while( sorted >= 0 && comp( &arr[type_size * sorted], key) > 0 ) //as long as the element to the left of the key is larger.
        {
            memcpy(&arr[type_size * (sorted +1)], &arr[type_size * sorted], type_size); //take that larger value and move it one place right
            sorted--; //count down.
        }

        memcpy( &arr[(sorted +1) * type_size], key, type_size); //copy key to the last "larger" value.
        
    }

    free(key);

    return true;
}





/*'''''''''''''''''' main funtion ''''''''''''''''''''' */

int main(void)
{
    //int array[] = {80,99,63,78,50,52,95,4,7,54,36,98,77,50,28,85,20,66,63,63,11,92,43,45,4};
    //int array[] = {71,79,68,89,90,65,76,69,72,84,82,69,86,79,83,80,77,85,74,88,79,70,78,87,79,82,66,75,73,67,85,81,65};
    //char array[] = {'A','Q','U','C','I','K','B','R','O','W','N','F','O','X','J','U','M','P','S','O','V','E','R','T','H','E','L','A','Z','Y','D','O','G'};
    char array[] = "A quick brown fox jumps over the lazy dog";
    int res = inssort(array, (sizeof array / sizeof array[0]), sizeof array[0], isBiggerChar );

    printf("%d \n", res);
    for(int i = 0; i < (sizeof array / sizeof array[0]); i++)
    {
        printf("%c ", array[i]);
    }
}
