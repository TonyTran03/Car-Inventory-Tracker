#include "../include/headerA3.h"

void oneLessCar (a3Car ** headLL, int whichOne){
    
    struct car * temp = *headLL;
    struct car *prev = NULL; // previous node
    int count = 1;

    // if first car needs to be removed
    if (whichOne == 1) {
        *headLL = temp->nextCar; // Change head
        free(temp);
        return;
    }
    
    while (temp != NULL && count < whichOne) { // find the car before the one to be removed
        prev = temp;
        temp = temp->nextCar;
        count++;
    }
    
    // remove the car from the list
    prev->nextCar = temp->nextCar; // unlink the car from the list
    free(temp);
}
