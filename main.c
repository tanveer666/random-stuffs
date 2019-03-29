#include <stdio.h>
#include "header.h"

int main(void)
{
    //double array[] = {80,99,63,78,50,52,95,4,7,54,36,98,77,50,28,85,20,66,63,63,11,92,43,45,4};
    int array[] = {71,79,68,89,90,65,76,69,72,84,82,69,86,79,83,80,77,85,74,88,79,70,78,87,79,82,66,75,73,67,85,81,65};
    //char array[] = {'A','Q','U','C','I','K','B','R','O','W','N','F','O','X','J','U','M','P','S','O','V','E','R','T','H','E','L','A','Z','Y','D','O','G'};
    //char array[] = "A quick brown fox jumps over the lazy dog";
    //int array[] = {1000,3 ,1 ,2 };
    int res = inssort(array, (sizeof array / sizeof array[0]), sizeof array[0], isBiggerInt );

    //printf("%d \n", res);
    for(int i = 0; i < (sizeof array / sizeof array[0]); i++)
    {
        printf("%d ", array[i]);
    }
}
