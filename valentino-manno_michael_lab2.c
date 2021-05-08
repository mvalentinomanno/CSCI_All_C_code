/*
 * Michael Valentino-Manno
 * Lab 2, CSCI 112
 * 1/27/2017
 */
 #include <stdio.h>

 //get_input function that reads in user input, stores, and returns it
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

 double get_next(double x1, double x2)
 {
   //calculate and return the next term in the sequence
   return((x1/2) + 3 * x2);
 }

 void print_result(double x5)
 {
    //print the result rounded two decimal places
    printf("The result is %.2f \n", x5);
 }

 double main(void)
 {
    //call the get_input method twice
    double X1 = get_input();
    double X2 = get_input();
    //call get_next three times, passing past calculated values to find the next
    double X3 = get_next(X1,X2);
    double X4 = get_next(X2,X3);
    double X5 = get_next(X3,X4);
    //vall print_result method to print X5
    print_result(X5);
    return (0.0);
 }
