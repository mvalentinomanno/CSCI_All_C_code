/*
 * Michael Valentino-Manno
 * Lab 1, CSCI 112
 * 1/23/2017
 */
 #include <stdio.h>

 int
 main(void)
 {
   /* declare variables */
   double celsius = 0, fahrenheit = 0;

   /* get the temperature in Celsius */
   printf("Enter a temperature in degrees Celsius: ");
   /* read in user input */
   scanf("%lf",&celsius);
   
   /* convet to Fahrenheit */
   fahrenheit =  (celsius * 9.0 / 5.0) + 32.0;
   
   /* print out the temperature in Fahrenheit */
   printf("That is %.2f Fahrenheit\n", fahrenheit);

   /* get the temperature in Fahrenheit */
   printf("Enter a temperature in degrees Fahrenheit: ");
   /* read in user input */
   scanf("%lf",&fahrenheit);

   /* convert to celsius */
   celsius = (fahrenheit - 32.0 ) * 5.0/9.0;
  
   /* print out the temperature in Celsius */
   printf("That is %.2f Celsius \n", celsius);

   /* exit with no errors */
   return(0);
 
 }
