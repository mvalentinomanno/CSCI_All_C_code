/*
 * Michael Valentino-Manno
 * Program 2, CSCI 112
 * 3/18/17
 */

#include <stdio.h>
#define MAX_ARRAY_SIZE 50 //Define a constant to restrict max array size

//Function prototypes that will be used in addition to main function
int populate_array(int array[]); 
void print_array(int array[], int n);
void swap(int array[], int index1, int index2);
void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
   int list[MAX_ARRAY_SIZE]; //create array of size MAX_ARRAY_SIZE
   int n = populate_array(list); //call populate_array function and store whats returned
   printf("The initial array contains:\n");
   print_array(list, n); //print array
   quicksort(list, 0, n - 1); //call quicksort function to sort the array
   printf("The array is now sorted:\n");
   print_array(list, n); //print array
   return 0; //exit
}

int populate_array(int array[])
{
    int n; //int to hold number of items user entered
    do{
        printf("Enter the value of n > ");
        scanf("%d", &n); //read in the n value
        if(n > MAX_ARRAY_SIZE) //if n is greater than the defined constant print error message
        {
            printf("%d exceeds the maximum array size. Please try again.\n\n", n);
        }
        else if(n < 0) //if n is less than 0, print an error method
        {
            printf("%d is less than zero. Please try again.\n\n", n);
        }
    }while(n > MAX_ARRAY_SIZE || n <= 0); //execute until n is between zero and defined constant
    printf("Enter %d integers (positive, negative, or zero) >\n", n);
    int i;
    for(i = 0; i < n; i++) //for loop to read in user input
    {   
        scanf("%d", &array[i]); //store user input into next array spot
    }
    return n; //return number of items user inputted
}

void print_array(int array[], int n) //function that prints the array
{
    int i;
    for(i = 0; i < n; i++) //for that loops through array 
    {
    printf("%+5d\n", array[i]); //print value at spot in array
    }
}

void swap(int array[], int index1, int index2) //function that swaps items at two index values
{
    int temp; //temp to hold a value
    temp = array[index1]; //set temp equal to the value at index1
    array[index1] = array[index2]; //set value at index1 to that at index2
    array[index2] = temp; //set value at index2, to temp, successfully swapping the initial two values
}

void quicksort(int array[], int low, int high) //quicksort function, to sort array
{
    if(low < high) //if low is less than high
    {
    int pivot = partition(array, low, high); //call partition, and save the value as pivot
    quicksort(array, low, pivot - 1); //recusivley call quicksort with a different value for high
    quicksort(array, pivot + 1, high); //recursivley call quicksort with a different value for low
    }
}

int partition(int array[], int low, int high) //partition function that sorts the values in the array, given a pivot
{
    int pivot = array[high]; //local int pivot set to the value of the array at the passed 'high' index
    int i = low; //set an int to the passed low index
    int j; //int j 
    for(j = low; j < high; j++) //for that loops until j (starting at low) isn't less than high
    {
    if(array[j] <= pivot) //if the value at index j is less than or equal to pivot
    {
    swap(array, i, j); //swap the values at index i and j
    i = i + 1; //incrament i
    }
    }
    swap(array, i, high); //swap values at index i and index high
    return i; //return i
}
