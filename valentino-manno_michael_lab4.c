/*
 * Michael Valentino-Manno
 * Lab 4, CSCI112
 * 2/22/2017
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159    //define necessary values
#define LOOP_LIMIT 90

void calcSine();     //declared functions
void calcCosine();   //at top so I could 
void calcTangent();  //call them in my main
void user_menu();    //and user_menu

int main()
{
    user_menu();    //calls user_menu
    return 0;
}

void user_menu()
{
    typedef enum{   //enum for each menu choice
        Sine,
        Cosine,
        Tangent,
        QUIT
    } menu_t;
    
    menu_t userInput;  //userInput to compare to the menu options

    while(userInput != QUIT)  //Keep executing until the user wants to quit
    {
    printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
    printf("Enter your choice > ");
    scanf("%u", &userInput);  //reads in an int from the user

        switch(userInput)     //switch that depending on the users input
        {                     //will call the (0) calcSine(), (1) calcCosine(),
        case Sine:            //(2) calcTangent() function, print and error, or 
            calcSine();       //(3)tell the user they quit.
            break;
        case Cosine:
            calcCosine();
            break;
        case Tangent:
            calcTangent();
            break;
        case QUIT:
            printf("You chose QUIT. Thank you, come again!\n");
            break;
        default:
            printf("%d is an invalid option. Please try again.\n", userInput);
            break;
        }
    }
}

void calcSine()
{
    int degrees;    //int for degrees
    double radians; //double for calculated radian value
    double answer;  //double for answer of trig funtion

    for(degrees = 0; degrees <= LOOP_LIMIT; degrees += 15) //for loop that
    {                                          //adds 15 degrees every time
        radians = (double) PI * degrees / 180; //calculate radians
        answer = sin(radians);                 //calculate answer to trig func 
        printf("\tsin(%d) = %.4lf\n", degrees, answer);
    }
}

void calcCosine()
{
    int degrees; 
    double radians;
    double answer; 
    
    for(degrees = 0; degrees <= LOOP_LIMIT; degrees += 15) //for loop
    {                                            //adds 15 degrees each time
        radians = (double) PI * degrees / 180;
        answer = cos(radians);
        printf("\tcos(%d) = %.4lf\n", degrees, answer);
    }
}

void calcTangent()
{
    int degrees;
    double radians;
    double answer;

    for(degrees = 0; degrees <= LOOP_LIMIT; degrees += 15) //for loop
    {                                            //adds 15 degrees each time
        if(degrees == 90)    //checks if the degree value is 90, and if so
        {                    //prints the value is undefined b/c tan(90) is undef
            printf("\ttan(%d) is UNDEFINED\n", degrees);
        }
        else                 //if the degree value isn't 90, execute like
        {                    //the funtions above, calculating tan value
        radians = (double) PI * degrees / 180;
        answer = tan(radians);
        printf("\ttan(%d) = %.4lf\n", degrees, answer);
        }
    }
}
