#include <stdio.h>

int get_input(void)  //method to get users input and return it
{
    int userInput;
    int isVal = 0;
    do              //do while that keeps prompting user for a valid number until one is given
    {
    printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
    scanf("%d", &userInput);        //read in user input
    isVal = is_valid(userInput);    //call is_valid and stores either 1 or 0
    }while(isVal == 0);   //stops do while when the number returned from is_valid is 1 which indicates a valid number

    return userInput;
}

int is_valid(int userInput)   //method that checks if the user gave an odd number greater than 0 and less than or equal to 9
{
    if(userInput % 2 == 1 && userInput > 0 && userInput <= 9)    //if the number is odd, greater than zero, and less than or equal to 9, return 1 (value signifying the number was valid)
        {
            return 1;
        }
    else if(userInput <= 0)   //if the number is less than or equal to zero, return 0 (the value signifying the number was invalid)
        {
            printf("You have entered a number less than 1. Please try again. \n\n");
            return 0;
        }
    else if(userInput > 9)    //if the number is greater than 9, return 0
        {
            printf("You have entered a number greater than 9. Please try again. \n\n");
            return 0;
        }
    else if(userInput % 2 == 0)    //if the number is even, return 0
        {
            printf("You have entered an even number. Please try again. \n\n");
            return 0;
        }
}

void print_pattern(int N)   //method that prints the pattern, and doesn't return anything
{  
    int i;                  //ints for incrament, number printed, and the highest number to print
    int num = 1;
    int max = 1;
    printf("\n");
    for(i = 1; i <= N; i += 2)   //for loop starting at 1, going until i is greater than the number N, and incramenting by 2, used for the number of spaces to print
    {
        printf("%*s", N - i, "");   //print N - i number of spaces
        while(num <= max)           //while that prints numbers starting at 1, and incramenting until they reach the max, which is where the while ends.
    {
        printf("%d ", num);
        num++;                    
    }
        num = 1;           //after a line is complete, you start by printing 1 on the next line
        max+=2;            //as the lines progress, the highest number printed raises by 2
        printf("\n");      //makes new line
    }
    num = 1;               //sets num, max and i back to necessary values to start printing the bottom half of the output
    max -=4;
    i-=4;
    for(i; i >= 1; i-=2)   //for loop starting at i, that goes until i is less than 1, and decraments by 2 each time through
    {
        printf("%*s", N - i, "");   //print N - i number of spaces
        while(num <= max)           //while that prints numbers starting at 1, and going until they reach the max
    {
        printf("%d ", num);       
        num++;
    }
    num = 1;    //the first number on each line is 1
    max -=2;    //on the second half of whats printed, the max is decramented by 2 as it goes down a line
    printf("\n"); //new line
    }
    printf("\n");
}

int main(void)
{
    int num;
    num = get_input();   //gets user's input
    print_pattern(num);  //passes print_pattern the valid number that the user gave
    return 0;
}
