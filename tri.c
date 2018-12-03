#include "stdio.h"

int main()
{   
    int height;
    printf("Enter the triangle size (number of row):");
    scanf("%d",&height);

    int height_half = height/2;

    int crnt_row = 1, row_hash = 1, space_num = 0,hash = 0; //row hash = maximum number of hash per row, hash = current hash, crnt_row = row that is being worked on, space num = counter for how many spaces have been printed
    
    int row2_space = height-1; // maximum number of space before the 2nd triangle.

    for( ; crnt_row <= height; crnt_row++) //counts which row is to be printed.
    {

        /*--- top triangle ---*/
        if(crnt_row <= height_half) //the top triangle will take up exactly half of the total height, i.e half height = 20 rows if height is 40.
        {
            for(space_num = 0; space_num < (height-crnt_row); space_num++)
            {  
                printf(" ");  //determines how many space before  hashes of the top triangle

            }

            for(hash = 0; hash < row_hash; hash++)
            {
                printf("#"); //prints the hash
            }

            row_hash += 2; //keeps number of hash per row always odd
             if(crnt_row == height_half)
            {
                row_hash = 1; //resets it for the bottom 2 triangles
            }
        }
        else
        {   

            /*---- first triangle----- */
            
            for( space_num = 0; space_num < height-crnt_row; space_num++)
            {
                printf(" "); //same as top triangle
            }

            for(hash = 0; hash <row_hash; hash++)
            {
                printf("#"); //same as top triangle, just the values are different

            }
            /*----- second triange ----*/

            for(space_num = 0; space_num <row2_space; space_num++)
            {
                printf(" "); //different approach, number of space is determined by row2_space variable, compared to current row variable in the previous triangles
            }

            for(hash = 0; hash < row_hash; hash++)
            {
                printf("#"); //same approach as other triangle.
            }

            height_half--;
            row_hash += 2;
            row2_space -= 2;
        }

        printf("\n");

    }


}
