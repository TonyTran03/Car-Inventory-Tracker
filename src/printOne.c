#include "../include/headerA3.h"
//make sure main checks that whichOne is valid number
void printOne (struct car * headLL, int whichOne){
    printf("\n");
    struct car * temp = headLL;
    if (temp == NULL) {
            printf("No cars found.\n"); //return if no cars are in the LL yet
            return;
    }
    
    int carIndex = 1; //starting at car #1

    //go to the next car until we are at the correct Index
    while (carIndex!= whichOne) {
            temp = temp->nextCar;
            carIndex++;
    }
    
        printf("Car id: %d\n", temp->carId);
        printf("Model: %s\n", temp->model);
        printf("Type: %s\n", temp->type);


        int beforeDecimal = (int)temp->price;
        float afterDecimal = temp->price - beforeDecimal;

        //convert number into a iterable array
        char intStr[20];
        sprintf(intStr, "%d", beforeDecimal);

        // Print the integer part with commas
        for (int i = 0; i < strlen(intStr); i++) {
            if ((strlen(intStr) - i) % 3 == 0 && i != 0) {
                printf(",");
            }
            printf("%c", intStr[i]);
        }
        //printf("%.2f\n", afterDecimal); //example, it woud print .25 as 0.25 instead.
        printf(".%02d\n", (int)(afterDecimal * 100)); //print ".", then 25
        printf("Year of Manufacture: %d\n\n", temp->year);
        
}