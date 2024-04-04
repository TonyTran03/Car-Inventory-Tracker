#include "../include/headerA3.h"

int countCars (a3Car * headLL){
    int count = 0;
    struct car * temp = headLL;
    while(temp !=  NULL){
        count++;
        temp = temp->nextCar;
    }
    return count;
}