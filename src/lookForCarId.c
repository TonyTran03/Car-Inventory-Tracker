#include "../include/headerA3.h"
int lookForCarId (struct car * headLL, int key){
    struct car * temp = headLL;
    int pos = 1;

    while(temp != NULL){ //we want to go to the end of the list

        if(key == temp->carId){
            return pos;
        }

        temp = temp->nextCar; //move to next car
        pos++;//incremenmt the position by one
    }


    return -1;//not found
}