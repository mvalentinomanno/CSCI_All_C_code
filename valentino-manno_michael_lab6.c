/*
 * Michael Valentino-Manno
 * Lab 6, CSCI 112
 * 3/9/17
 */
 
#include <stdio.h>
#include <math.h>

//list of function prototypes

// display menu, read input, and validate
int user_menu();

//Equation functions that are pass by ref
void equation1(float *);   //calc eq1
void equation2(float *);   //calc eq2
void equation3(float *);   //calc eq3
void equation4(float *);   //calc eq4

float get_position_initial(void); //asks user for x initial
float get_position_final(void);  //asks user for x final
float get_velocity_initial(void);  //asks user of v initial
float get_velocity_final(void);  //asks user for v final
float get_acceleration(void);  //asks user for acceleration
float get_time(void);  //asks user for time

int main(void)
{
    printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");  //Opening message

    int user_choice;  //int to hold the users choice
    
    do{   //do while that executes until user chooses to quit
        while(user_choice > 5 || user_choice <= 0)  //while that keeps asking for user input until it's valid
        {
        user_choice = user_menu();
        }
        float result;  //float representing the result
        switch(user_choice)
        {
            case 1: //user chooses eq1
                equation1(&result);  //pass address of result
                break;
            case 2: //user chooses eq2
                equation2(&result);  //pass address of result
                break;
            case 3: //user chooses eq3
                equation3(&result);  //pass address of result
                break;
            case 4: //user chooses eq4
                equation4(&result);  //pass address of result
                break;
            case 5: //user chooses to quit
                printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n\n");
                return 0;
                break;
        }
        user_choice = 0;  //reset user choice so it doesn't keep asking for input for same equation
        printf("Your result is %.4f.\n\n", result); //print result
    } while (user_choice != 5);
    return 0;
}
//methods to get a variable from the user
float get_position_initial(void)  //method to get initial position
{
    float pInitial;
    printf("\tEnter initial position > ");
    scanf("%f", &pInitial);
    return pInitial;
}

float get_position_final(void)  //method to get position final
{
    float pFinal;
    printf("\tEnter final position > ");
    scanf("%f", &pFinal);
    return pFinal;
}

float get_velocity_initial(void)  //method to get initial velocity
{
    float vInitial;
    printf("\tEnter initial velocity > ");
    scanf("%f", &vInitial);
    return vInitial;
}

float get_velocity_final(void)  //method to get final valocity
{
    float vFinal;
    printf("\tEnter final velocity > ");
    scanf("%f", &vFinal);
    return vFinal;
}

float get_acceleration(void)  //method to get acceleration
{
    float acc;
    printf("\tEnter acceleration > ");
    scanf("%f", &acc); 
    return acc;
}

float get_time(void)  //method to get time
{
    float time;
    printf("\tEnter time > ");
    scanf("%f", &time);
    return time;
}
//pass by reference functions used to calulate equations 1-4, address of result is passed to each
void equation1(float *vF)  
{
    float vI = get_velocity_initial();
    float a = get_acceleration();
    float t = get_time();
    *vF = vI + a * t;  //calculate eq1, value stored as pointer
}

void equation2(float *xF)
{
    float xI = get_position_initial();
    float vI = get_velocity_initial();
    float t = get_time();
    float a = get_acceleration();
    *xF = xI + vI * t + .5 * a * pow(t, 2); //calculate eq2, value stored as pointer
}

void equation3(float *vF)
{
    float vI = get_velocity_initial();
    float a = get_acceleration();
    float xF = get_position_final();
    float xI = get_position_initial();
    *vF = sqrt((pow(vI, 2) + 2 * a * (xF - xI)));  //calculate eq3, value stored as pointer
}

void equation4(float *xF)
{
    float xI = get_position_initial();
    float vF = get_velocity_final();
    float vI = get_velocity_initial();
    float t = get_time();
    *xF = xI + .5 * (vF + vI) * t;  //calculate eq 4, value is stored as pointer
}

int user_menu(void) //method that gets user input and validates it
{
    int user_input;  //used to store the users input
    printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
    scanf("%d", &user_input); //read in
    if(user_input <= 0 || user_input > 5) //if user gave an invalid number
    {
        printf("Invalid Option. Please try again.\n\n");  //print error message
    }
    return user_input;  //return user input, if it's invalid, user_menu will be called again.
}



