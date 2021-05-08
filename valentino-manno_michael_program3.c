/*
 * Michael Valentino-Manno
 * Lab 9, CSCI112
 * 4/20/17
 */

#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 25 //Define the max size of the first and last name arrays as 25 chars

typedef struct{ //struct that represents a student
    int sid; //student id
    char last[NAME_SIZE]; //last name
    char first[NAME_SIZE]; //first name
    float *grades; //float pointer to grades that will point to the beginning of the grade array
    float gpa; //grade point average
} student; //name student

student inputInfo(int); //function prototypes
float calcGPA(student, int);
void printInfo(student*, int, int);
void freeMem(student*, int);

int main(void)
{
    int numStudents; //ints to be read in from user
    int numGrades;
    scanf("%d", &numStudents); //get input from user
    scanf("%d", &numGrades);    
    printf("Number of students: %d\n", numStudents);
    printf("Number of grades (each): %d\n", numGrades);
    student *array = (student*)calloc(numStudents, sizeof(student)); //dynamically allocate memory for student array
    int i;
    for(i = 0; i < numStudents; i++) //for that incraments through all of the students
    { 
        *(array + i)  = inputInfo(numGrades); //saves the student from inputInfo method into the array of students
    }
    printInfo(array, numStudents, numGrades); //call print info
    freeMem(array, numStudents); //call free mem
    return 0; //exit 
}

student inputInfo(int numGrades) //method that is used to read in info about each student
{
    student newStudent; //Create local student
    scanf("%d%s%s", &newStudent.sid, newStudent.last, newStudent.first); //get user input for id and name
    newStudent.grades = (float*)calloc(numGrades, sizeof(float)); //dynamically allocate memory for grade array of floats
    int i;
    for(i = 0; i < numGrades; i++) //for that loops through grade numbers
    {
        scanf("%f", &newStudent.grades[i]); //scan in each grade
    }
    newStudent.gpa = calcGPA(newStudent, numGrades); //save the students gpa, got from calling calcGPA method 
    return newStudent; //return the student
}

float calcGPA(student s, int numGrades) //method that calculates the passed students gpa
{
    int i;
    float total = 0;
    for(i = 0; i < numGrades; i++)  //loop through each grade and update the total
    {
        total = total + (s.grades[i]);
    }
    float avg = (total /(float)numGrades); //calculate average
    return avg; //return it
}

void printInfo(student* first, int numStudents, int numGrades) //prints the info about the students
{
    int i;
    int j;
    for(i = 0; i < numStudents; i++) //for that loops through each person
    {
        printf("ID: %d, Name: %s %s, GPA: %.2f\n", (*(first + i)).sid, (*(first + i)).first, (*(first + i)).last, (*(first + i)). gpa);
        printf("Grades:"); //uses the incrament as an offset to print each students info
        for(j = 0; j < numGrades; j++) //print the current students grades
        {
            printf(" %.1f", (*(first + i)).grades[j]);
        }
        printf("\n"); //new line afer done printing a students info
    }
}

void freeMem(student* first, int numStudents)
{   
    int i;
    for(i = 0; i < numStudents; i++) //for that loops through each student
    {
        free((*(first + i)).grades); //call free on each students grades
        (*(first + i)).grades = NULL; //set grades to null
    }
    free(first); //free first one and set it to null
    first = NULL;
}
