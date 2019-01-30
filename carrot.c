#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* -------------------------- atoi_n --------------------------- */

/*
 * this variable takes in a string of number
 * and returns exactly the first n digits of the string in int format, so 12345, 3  will return 123.
 */

int atoi_n(char **p_input, int n) //Takes in the variable holding the pointer to the input string, and length of the string
{   
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        char digit = *(*p_input + n - 1- i);
        num +=  (digit - '0') * pow(10,i); // converts char value to int.
    }

    *p_input = *p_input + n; // modifies the variable so that the pointer it holds now points to the nth variable to the right of it.

    return num;
}
/* 


/*------------------------- karat ---------------------- */

int karat(int x, int y, int len) // takes in 2 integers and their length.
{
   if(len == 1) 
   {
       return x * y; // completes 2 simple mutiplication if the arguemnt ints are 1 digit ints.
   }
   else
   {
       /* 
        * This part takes the input integers and convert them into string.
       */
       int  n = len/2; // other wise n is half the length.
       char *x_c = malloc((len+1) * sizeof(char)); // allocates space for the 2 int so that they are converted to string
       char *y_c = malloc((len+1) * sizeof(char));
       sprintf(x_c,"%d",x); //actual int to string coversion.
       sprintf(y_c,"%d",y);

    /*
    * This part takes the resulting string calls atoi_n to get half of the original number in int format.  This is where the number gets actually divided.
    */
       int a = atoi_n(&x_c,n);
       int b = atoi_n(&x_c,n);

       int c = atoi_n(&y_c,n);
       int d = atoi_n(&y_c,n);

      
        /*
        * The recursive part, where the function calles itself with half integers
        */

       free(x_c - len); //Thanks to atoi_n, x_c points to n+n = len elements to the right, so we subtract len elements so that x_c points to the start of the memoryfield.
       free(y_c - len);
       int prod = ( pow(10,len) * karat(a,c,n) ) + ( pow(10,n) * ( karat(a,d,n)+karat(b,c,n) ) )+ ( karat(b,d,n) ) ; //bewarn of order of operations!!!!!!!

       return prod;

   }
   
   
    

}


int main(int argc, char *argv[])
{
    char *p_x = argv[1];
    char *p_y = argv[2];
    int n = strlen(p_x);

    int x = atoi(p_x);
    int y = atoi(p_y);

    int prod = karat(x,y,n);

    printf("%d",prod);
   
    return 0;

}