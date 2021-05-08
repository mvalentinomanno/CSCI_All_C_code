#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_FILENAME "element_db.csv" //input file name

typedef struct {  //struct representing an element
    int atomic_number;
    char symbol[4];
    char name[25];
    float atomic_weight;
    char state[25];
    char bonding_type[25];
    char discovered[25];
} element_t;

element_t * find_element( element_t * list, char * symbol ); //prototypes
void print_element(FILE*, element_t);

int main( int argc, char * argv[] )
{
    if (argc < 2) //if the wrong number of arguments is given, print error and exit
    {
        printf(" ERROR: Please provide at least one program argument.\n");
        return 0;
    }

    element_t * elements = (element_t *)calloc(118, sizeof(element_t)); //create array of elements, for whole input file
    
    FILE * element_file = fopen(ELEMENT_FILENAME, "r"); //read in from file
    if(element_file != NULL) //if theres a file
    {
        char line[100];
        while(fgets(line, 100, element_file) != NULL) //read
        {
            // remove newline character from line
            char * nl = strchr(line, '\n'); //new line
            if (nl)
            {
                *nl = '\0'; //append null character
            }
            element_t e; //local element
            char * str = strtok(line, ","); //have a comma represent end of each part
            int col = 0; 
            while (str != NULL) //until the end of a line
            {
                switch(col) //switch that reads in each part into the struct depending on its position in the file
                {
                    case 0:
                        e.atomic_number = atoi(str);
                        break;
                    case 1:
                        strcpy(e.symbol, str);
                        break;
                    case 2:
                        strcpy(e.name, str);
                        break;
                    case 3:
                        e.atomic_weight = atof(str);
                        break;
                    case 4:
                        strcpy(e.state, str);
                        break;
                    case 5:
                        strcpy(e.bonding_type, str);
                        break;
                    case 6:
                        strcpy(e.discovered, str);
                        break;
                }
                str = strtok(NULL, ","); 
                col++;
            }
            elements[e.atomic_number - 1] = e;
        }
        fclose(element_file); //close input file
    }
    //process program arguments.
    FILE * output_f = NULL; //Create new output file
    int i;
    int fileFound = 0; //int that keep tracks if an output file was given
    for(i = 1; i < argc; i++) //for loops through the arguments given per line
    {
        if(i == 1) //check for filename
        {
            char * dot = strchr(argv[i], '.'); //check for a dot
            if(dot) //if a dot is found
            {
                //this is a filename
                output_f = fopen(argv[i], "w");
                fileFound = 1; //set int to 1 meaning the file was found
                continue;
            }
        }
        //look up this element
        element_t * ele = find_element(elements, argv[i]);
        if(ele)
        {
            print_element(output_f ,*ele); //call print function, that prints to either the file or the screen
        }
        else //else means the atomic symbol was not found
        {
            if(fileFound == 1) //if a file was given, fprintf to file
            {
                fprintf(output_f, "WARNING: No such element: %s\n", argv[i]);
            }
            else //if a file wasn't given, print warning to screen
            {
                printf("WARNING: No such element: %s\n", argv[i]);
            }
        }
    } 
    return 0;
}

element_t * find_element(element_t * list, char * symbol)
{
    int i;
    for(i = 0; i < 118; i++) //function finds element and returns it
    {
        if(strcmp(list[i].symbol, symbol) == 0)
        {
            element_t * result = &list[i];
            return result;
        }
    }
    return NULL; //if it wasn't found, return NULL
}

void print_element(FILE * out, element_t e)
{
    if (out != NULL) //if the file was given by user, use fprintf to print to output file
    {
        fprintf(out, "---------------\n");
        fprintf(out, "| %d\t%.4f\n", e.atomic_number, e.atomic_weight);
        fprintf(out, "| %s\t%s\n", e.symbol, e.name);
        fprintf(out, "| %s\n", e.state);
        fprintf(out, "| %s\n", e.bonding_type);
        fprintf(out, "| Found: %s\n", e.discovered);
        fprintf(out, "---------------\n");
    }
    else //if the file was NOT given by user, print to screen
    {
        printf("---------------\n");
        printf("| %d\t%.4f\n", e.atomic_number, e.atomic_weight);
        printf("| %s\t%s\n", e.symbol, e.name);
        printf("| %s\n", e.state);
        printf("| %s\n", e.bonding_type);
        printf("| Found: %s\n", e.discovered);
        printf("---------------\n");
    }
}
