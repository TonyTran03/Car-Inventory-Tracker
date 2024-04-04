#include "../include/headerA3.h"

void swapCars(struct car *a, struct car *b) {
    int tempYear = a->year;
    a->year = b->year;
    b->year = tempYear;
    
    double tempPrice = a->price;
    a->price = b->price;
    b->price = tempPrice;
    
    char tempModel[MAX_LENGTH];
    strcpy(tempModel, a->model);
    strcpy(a->model, b->model);
    strcpy(b->model, tempModel);
    
    char tempType[MAX_LENGTH];
    strcpy(tempType, a->type);
    strcpy(a->type, b->type);
    strcpy(b->type, tempType);
    
    int tempCarId = a->carId;
    a->carId = b->carId;
    b->carId = tempCarId;
}


void sortCarId (struct car ** headLL){
    
    int swapped;
    struct car *ptr1;
    struct car *lptr = NULL;
  
    if (*headLL == NULL) // checking for empty list
        return;
  
    do { //bubble sorting
        swapped = 0;
        ptr1 = *headLL;
        while (ptr1->nextCar != lptr) {
            if (ptr1->carId > ptr1->nextCar->carId) {
                swapCars(ptr1, ptr1->nextCar);
                swapped = 1;
            }
            ptr1 = ptr1->nextCar;
        }
        lptr = ptr1;
    }while (swapped);

}

