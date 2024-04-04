#include "../include/headerA3.h"
//2
void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]){
    
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        struct car *newCar = malloc(sizeof(struct car)); //new car node
        newCar->nextCar = NULL;

        //values soon to be filled in
        int id;
        int year;
        double price;
        char carType[MAX_LENGTH];
        char carModel[MAX_LENGTH];

        //collect inputs
        sscanf(line, "%d,%[^,],%[^,],%d,%lf", &id, carType, carModel, &year, &price); //grab values separated by commas


        
        int isUnique;
        do {//Id uniqueness test by checking all of the cars
            isUnique = 1;
            for (struct car *temp = *headLL; temp != NULL; temp = temp->nextCar) {
                if (temp->carId == id) {
                    isUnique = 0; // not unique
                    id = 0;
                    
                    for (int i = 0; carModel[i] != '\0'; ++i) { // new id by summing ASCII values of carModel and length of carType
                        id += (int)carModel[i];
                    }
                    id += strlen(carType);
                    break; // Check the newly generated id for uniqueness
                }
                
            }
        } while (!isUnique);


        newCar->carId = id; // Assign unique id

        //populate new car Node
        strcpy(newCar->type,carType);
        strcpy(newCar->model,carModel);
        newCar->year = year;
        newCar->price = price;

        //assign new node to the end of list
        if (*headLL == NULL) { // If the list is empty
            *headLL = newCar;
        }
        else{
            struct car *temp = *headLL;
            while (temp->nextCar != NULL) { // traverse to the last node in the list
                temp = temp->nextCar;
            }
            temp->nextCar = newCar; // append the new node
        }

    }
    //end of while loop
}