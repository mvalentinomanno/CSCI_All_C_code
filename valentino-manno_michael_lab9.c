/*
 * Michael Valentino-Manno
 * Lab 9, CSCI112
 * 4/11/17
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 20

void scan_element(int index); //function prototypes, both take in an index value
void print_element(int index);

typedef struct{  //define my structure for an element on the periodic table
    int aNum;    //structure includes: atomic number
    char name[MAX_ELEMENTS]; //names should not exceed 20 letters
    char sym[4]; //symbols do not exceed 3 letters
    char class[25]; //class, which can have more than 20 characters, so I made it length 25
    double aWeight; //atomic weight
    int shell[7]; //and electrons in each shell
} element_t; //type element_t

element_t array[MAX_ELEMENTS]; //create an array of element_t's size MAX_ELEMENT, to hold each of the elements scanned in 

int main(int argc, char *argv[]) //main to read in a command line argument
{
    if(argc != 2) //Checks if an invalid number of aruments were given  
    {
        printf("You must provide exactly one argument to this program.\n"); //if so, print error, exit program
        return 0;
    }
    int N = atoi(argv[1]); //convert the string provided to an integer
    if(argc == 2)
    {
        if(N > 0 && N <= MAX_ELEMENTS) //if N is greater than zero and less than or equal to 20
        {
            int i; //local int i used for iterating
            int small = 100000; //ints used to  
            int large = 0;      //check and save the
            int lgIndex;        //element with greatest and 
            int smIndex;        //smallest atomic numbers
            for(i = 0; i < N; i++) //for loops until it reaches the int from the command line
            {
                scan_element(i); //scan in an element each time
                if(array[i].aNum < small) //check if the elements atomic number is the new smallest
                {
                    small = array[i].aNum; //save new small
                    smIndex = i; //save index
                }
                if(array[i].aNum > large) //check if the elements atomic number is the new largest
                {
                    large = array[i].aNum; //save new large
                    lgIndex = i; //save index
                } 
            }
            printf("%d total elements.\n", N); //prints total elements
            printf("%s had the smallest atomic number.\n", array[smIndex].name); //prints smallest atomic number
            printf("%s had the largest atomic number.\n", array[lgIndex].name); //prints largest atomic number
            for(i = 0; i < N; i++) //for that loops until n
            {
                print_element(i); //prints each element
            }
        }
        else
        {
                printf("ERROR: You must provide an integer greater than 0 and less than or equal to 20.\n"); //If n isn't in between 0 and 20 print error and exit
                return 0;
        }
    }
    return 0;
}

void scan_element(int index) //scan_element method uses a (long) scanf to read in each part of the structure from one line from the user
{
    scanf("%d%s%s%s%lf%d%d%d%d%d%d%d", &array[index].aNum, array[index].name, array[index].sym, array[index].class, &array[index].aWeight, &array[index].shell[0], &array[index].shell[1], &array[index].shell[2], &array[index].shell[3], &array[index].shell[4], &array[index].shell[5], &array[index].shell[6]); //reads in each thing to the structure instance at the passed array value index
} 

void print_element(int index) //print_element method prints the structure at the passed index
{
    int i = 0; //used for iteration
    printf("---------------\n"); //print top bar of block
    printf("| %d\t%.4lf\n", array[index].aNum, array[index].aWeight); //print atomic number, tab, then print atomic weight to 4 decimal places
    printf("| %s\t%s\n", array[index].sym, array[index].name); //print symbol, teb, them print the elements name
    printf("| ");
    while(array[index].shell[i] != 0) //while that loops until a shell has zero electrons
    {
        printf("%d ", array[index].shell[i]); //print the number at that current shell
        i++;
    }
    printf("\n"); //new line
    printf("---------------\n"); //bottom bar of the block
}
