/*
 * Michael Valentino-Manno
 * lab 5, CSCI 112
 * 2/27/17
 */

#include <stdio.h>
#define max 12  //defined spots in array as 12

void userInput();                    //declare functions at top
int oddsTimesThree();                //so I could call them in my
int sumEvens();                      //main
int totalSum(int odds, int evens);
int checkDigit(int sum);     
void barcodeValid(int checkD);

int barcode[max];    //array that represents the barcode

int main()
{
    userInput();   //calls userInput
    int o = oddsTimesThree();  //calls oddsTimesThree and stores value
    int e = sumEvens();   //calls sumEvens and stores value
    int sum = totalSum(o, e);  //calls totalSum, with the past two values
    int checkDig = checkDigit(sum); //calls checkDig, passing sum and stores
    barcodeValid(checkDig); //checks if barcode is valid
    return 0;
}

void userInput()
{
    int i;    //my iterator
    printf("Enter a bar code to check. Seperate digits with a space >\n");
    for(i = 0; i < max; i++)  //for loop to read in each value of bar code
    {
        scanf("%d", &barcode[i]);  //read in userinput to value position in the array
    }
    printf("\n");
    printf("You entered the code: ");
    for(i = 0; i < max; i++)  //for loop to print out whole barcode
    {
        printf("%d ", barcode[i]);
    }
    printf("\n");
}

int oddsTimesThree()
{
    int i; 
    int sumOdd = 0;
    for(i = 0; i < max; i+=2) //for loop to go to each number in an odd position
    {                   //the first position is actually 0
        sumOdd += barcode[i]; //keep a running sum
    }
    sumOdd = sumOdd * 3;
    printf("STEP 1: Sum of odds times 3 is %d\n",sumOdd);
    return sumOdd; 
}

int sumEvens()
{
    int i;
    int sumEven = 0;
    for(i = 1; i < max - 2; i+=2) //for loop to go to each number in even pos
    {                      //the 2nd position is actually 1
        sumEven += barcode[i]; //keep running sum
    }
    printf("STEP 2: Sum of the even digits is %d\n",sumEven);
    return sumEven;
}

int totalSum(int odd, int even)
{
    int sum;
    sum = odd + even;
    printf("STEP 3: Total sum is %d\n",sum);
    return sum;
}

int checkDigit(int inSum)
{
    int check = inSum % 10; //use % to find the remainder when divided by 10
    check = 10 - check;     //use extracted last digit and sub from 10 to find check digit
    printf("STEP 4: Calculated check digit is %d\n",check);
    return check;
}

void barcodeValid(int checkDigit)
{
    int last = barcode[max - 1]; //last position is actually 11
    if(checkDigit == last) //if the check digit is equal to the last digit
    {
        printf("STEP 5: Check digit and last digit match\n");
        printf("Barcode is VALID.\n\n");
    }
    else  //if the last digit and check digit are unequal
    {   
        printf("STEP 5: Check digit and last digit do not match\n");   
        printf("Barcode is INVALID.\n\n");
    }
}
