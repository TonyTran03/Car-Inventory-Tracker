#include "../include/headerA3.h"

void noMoreCars (a3Car ** headLL){
    printf("\n");
    char input;
    printf("Are you sure you want to remove all car data (entry y or yes, n for no): ");
    
    while(1){
        scanf("%c", &input);
        while(getchar() != '\n'); // clear the input buffer
        if(input == 'y' || input == 'n'){
            break;
        }

        else{
            printf("\nAre you sure you want to remove all car data (entry y or yes, n for no): ");
        }
    }

    struct car *temp = *headLL;
    struct car *nextNode = NULL;

    if (input == 'n'){
        return;
    }

    while (temp != NULL) {
        nextNode = temp->nextCar; // Save the reference to the next node
        free(temp); // Free the current node
        temp = nextNode; // Move to the next node
    }

    *headLL = NULL; // Set the head of the list to NULL to indicate it's empty

     printf("All removed. Linked list is now empty.\n");
}