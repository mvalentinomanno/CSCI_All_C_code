/*
 * Michael Valentino-Manno
 * Lab 3, CSCI 112
 * 2/5/2017
 */
 
#include <stdio.h>
#include <math.h>
#include <float.h>
int get_N() //function to get n from the user
{
    int N = -1;
    do { 
        printf("Enter a value for N that is >= 0: "); //prompt user for N value
        scanf("%d", &N);
        if (N < 0)
    {
            printf("Error, enter an accaptable number\n");
    }
        else
    {
        break; // ends loop
    }
           
    }   while ( N < 0 );  //do it while N is < 0
        return(N);  //return N
}    

double get_input(void)
{
    //local variable
    double userInput;
    //prompt the user to enter a value
    printf("Enter a value >");
    //reads in value entered by user
    scanf("%lf", &userInput);
    //returns value
    return (userInput);
}

int main()
{
        int N = get_N(); //get N
        double lowest = DBL_MAX;  //Declare variables
        double highest = -DBL_MAX;
        double average;
        double range;
        double std_dev;
        double sum;
        double sum_squares;
        int i;
        for(i = 0; i < N; i++) //For that goes through all inputted values
    {
            double current = get_input();
            if (current < lowest)     //if current is lower than lowest
    {
                lowest = current;    //set lowest equal to current
    }
            if (current > highest)  //if current is higher than highest
    {
                highest = current;  //set highest equal to current
    }

            sum = sum + current;    //calculate sum
            sum_squares = sum_squares + pow (current, 2.0); //calculate sum^2
    }

        range = highest - lowest; //calculate range
        if (N == 0)    //if N is 0
    {
        average = 0.0;   //set everything to 0
        std_dev = 0.0;
        lowest = 0.0;
        highest = 0.0;
        range = 0.0;
    }
        else  //if N is not 0
    {
            average = sum / N;   //calculate average and std dev
            std_dev = sqrt(  ( sum_squares / N ) - pow (average, 2.0));
    } 
        printf("The Highest is: % .3f \n", highest);  //print results
        printf("The Lowest is: %.3f \n", lowest);
        printf("The Average is: %.3f \n", average);
        printf("The Range is: %.3f \n", range);
        printf("The Standard deviation is: %.3f \n", std_dev);
        return (0); //return a value
}
