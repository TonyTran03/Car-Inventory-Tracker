#include "../include/headerA3.h"
//1
void addNewCar (struct car ** headLL){
    struct car *temp = malloc(sizeof(struct car));
    temp->nextCar = NULL;

    char carModel[MAX_LENGTH];
    char carType[MAX_LENGTH];
    int year;
    double price;
    int carId = 0;
    printf("Enter the car model: ");
    fgets(carModel, sizeof(carModel), stdin);
    
        for(int i = 0; carModel[i]; i++) {
        if(carModel[i] == '\n') {
            carModel[i] = '\0';
            break;
        }
    }


    printf("Enter the car type: ");
    fgets(carType, sizeof(carType), stdin);
    for(int i = 0; carType[i]; i++) {
        if(carType[i] == '\n') {
            carType[i] = '\0';
            break;
        }
    }   


    printf("Enter the car year: ");
    scanf("%d", &year);

    printf("Enter its price: CDN $: ");
    scanf("%lf", &price);

    
    // sum of ASCII values of characters in carModel
    for (int i = 0; carModel[i] != '\0'; ++i) {
        carId += (int)carModel[i];
    }
    // Add the length of carType to carId
    carId += strlen(carType);


    //storing the values into a temporary car structure
    strcpy(temp->model, carModel);
    strcpy(temp->type, carType);
    temp->year = year;
    temp->price = price;
    temp->carId = carId;


    if (*headLL == NULL) { // If the list is empty
            *headLL = temp;
    }
    else{
        struct car *curNode = *headLL;
        while (curNode->nextCar != NULL) { // traverse to the last node in the list
            curNode = curNode->nextCar;
        }
        curNode->nextCar = temp; // append the new node
    }
    
    printf("Your computer-generated carID is: %d\n", carId);
}