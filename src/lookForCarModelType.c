#include "../include/headerA3.h"

int lookForCarModelType (struct car * headLL, char key [100]){
    struct car * temp = headLL;
    int pos = 1;

    while(temp != NULL){ //we want to go to the end of the list

        if(strcmp(key, temp->model) == 0){ //compare model name
            return pos;
        }

        temp = temp->nextCar; //move to next car
        pos++;//incremenmt the position by one
    }

    return -1;//not found
}
