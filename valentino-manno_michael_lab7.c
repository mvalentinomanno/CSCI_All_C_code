/*
 * Michael Valentino-Manno 
 * Lab 7, CSCI 112
 * 03/24/17
 */

#include <stdio.h>

// Function prototypes

char *my_strncpy(char *dest, char *source, int n);
char *my_strncat(char *dest, char *source, int n);
//my_strncpy function that copies n number of chars
char *my_strncpy(char *dest, char *source, int n)
{
    int j; //int j used in for loop
    
    for(j = 0; j < n; j++) //for loop to copy from one array to another 
    {
        if(source[j] != '\0') //if to check for the end of the source
        {
            dest[j] = source[j]; //copy from source to dest
        }
    }
    while(j < n)    
    {
        dest[n] = '\0'; //append index n to null character
    }
    return dest;
}
        

char *my_strncat(char *dest, char *source, int n)
{
    char *letter = dest; //create  pointer that points to dest

    while(*dest) //while that as long as the array is pointing to dest, incrament dest
    {
        dest++;
    }
    while(n) //while that decrements n, ends when local pointer is returned
    {      
        n--;
        if(!(*dest++ = *source++)) //if the pointers dont equal
        {
            return letter; //return the local pointer
        }
    }
   
    dest[n] = '\0'; //append index n to null character
    return letter;
}

int main() //Main given to test the program
{    

    char testSrc[] = "Hello";
    char testDest[40] = "world";
    int n = 5;

    my_strncat(testDest, testSrc, n);
    printf("CAT: %s \n", testDest);

    my_strncpy(testDest, testSrc, n);
    printf("CPY: %s \n", testDest);

    printf("%s \n", testDest);

   
    return 0;
}
