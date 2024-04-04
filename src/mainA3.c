
#include "../include/headerA3.h"

int main(int argc, char **argv)
{   
    struct car *head  = NULL;
    char fileName[MAX_LENGTH];
    if (argc > 1) {
        strcpy(fileName, argv[1]);
    }

    int count;
    int whichPos; 
    int key;
    char model [100];
    FILE *file = fopen(fileName, "r"); 
    if (file == NULL) {
        perror("Failed to open file");
        fclose(file);
        exit(1);
    }
    

    int temp;

     do{
        count =  countCars(head);
        //prints
        printf("1. Add data on a new car\n");
        printf("2. Load data on cars from a given text file\n");
        printf("3. Print data of all cars\n");
        printf("4. Print data of the nth car\n");
        printf("5. Search car data based on carId\n");
        printf("6. Search car data based on model and type\n");
        printf("7. Count the total number of cars in the list\n");
        printf("8. Sort the cars in the list based on carId\n");
        printf("9. Remove data of the nth car\n");
        printf("10. Remove all car data\n");
        printf("11. Exit\n");

        scanf("%d", &temp);

        
        //add print statements here
        switch(temp){
            case 1: 
                while(getchar() != '\n');
                addNewCar(&head);
                break;
            case 2: 
                loadCarData(&head, fileName);
                break;
            case 3: 
                printAll(head);
                break;

            case 4: 
                do{
                    printf("Enter a position (there are %d cars): ", count);
                    scanf("%d", &whichPos);
                    while(getchar() != '\n');
                }
                while(whichPos > count);
                    printOne(head, whichPos);
            break;

            case 5: 

                    printf("Enter a car ID: ");
                    scanf("%d", &key);
                    while(getchar() != '\n');
                    if (lookForCarId(head, key) == -1){ //the return is negative one if not found
                        printf("No Id found\n");
                    }
                    else{
                        printOne(head, lookForCarId(head, key)); //print information
                    }
                break;

            case 6: 
                printf("Enter the model and type (separated by a space): ");
                scanf("%s", model);
                while(getchar() != '\n');

                if(lookForCarModelType(head, model) == -1){
                    printf("No car model found\n");
                }
                else{
                    printOne(head, lookForCarModelType(head, model)); //print information
                }
                break;
            case 7:  //count
                printf("Total number of cars = %d\n", count);
                break;
            case 8: 
                sortCarId(&head); //sort
                break;
            case 9: 

                do{
                    printf("Enter a position (there are %d cars): ", count);
                    scanf("%d", &whichPos);
                    while(getchar() != '\n');
                }
                while(whichPos >count || whichPos <0);
                
                oneLessCar(&head, whichPos);
                printf("There are now %d car(s) remaining\n",countCars(head));
                break;  

            case 10: 
                noMoreCars(&head);
                break;                
            case 11: 
                break;                
        }
        
     }while(temp != 11);
    
    return 0;
}
