/*
 * Michael Valentino-Manno
 * Lab 8, CSCI112
 * 4/4/17
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 80

void reverse(char line[]); //function prototype

int main(int argc, char *argv[]) //main to read input from command line
{
    char str[SIZE]; //string of size 80
    int N = atoi(argv[1]); //get an int from the command line
    if(argc == 2) //only execute if correct number of arguments were given
    {
        if(N >= 0) //if n is positive, run reverse.
        {
            for(int x = 0; x < N; x++) //for to get the string from command line
            {
                fgets(str, SIZE, stdin); //f gets to get string               
                reverse(str); //call reverse on the string
            }
        }    
        else
        {
            printf("ERROR: Please provide an integer greater than or equal to 0"); //print error
            return 0;
        }
    }
    return 0;
}

void reverse(char line[]) 
{
    int length; //local ints
    int x;
    int y = 0;
    char reverse[SIZE]; //local string
    length = strlen(line); //get length by using strlen function
    for(x = length - 1; x >= 0; x--) //for the copies the reverse of the string into the local string
    {   
        reverse[y] = line[x]; 
        y++;
    }
    reverse[x] = '\0'; //append with null character
    strcpy(line, reverse); //copy reverse back into line
    for(x = 0; line[x] != '\0'; x++) //for that goes until null char
    {
        if(line[x + 1] == ' ' || line[x + 1] == '\0') //if the spot in the string isnt a space or null char
        {
            for(y = x; y >= 0 && line[y] != ' '; y--) //for that decraments y until its less than zero and not a space
            {
                if(isalnum(line[y]) != 0) //use isalnum to check if the character is alphanumeric
                {
                    printf("%c", line[y]); //print the character
                }
            }
        printf(" "); //space between words
        } 
    }
    printf("\n"); //new line
}
