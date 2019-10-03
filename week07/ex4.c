#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void * realloc_new(void * p, int prev_s, int new_s){
    //nothing allocated -> malloc(size)
    if(p == NULL){
        p = malloc(new_s);
        return p;
    }

    //have to free memory
    if(new_s == 0){
        free(p);
        return NULL;
    }

    //reallocate memory to the new size
    void * new_p;
    new_p = malloc(new_s);
    memcpy(new_p, p, prev_s);
    free(p);
    return new_p;

}

int main() {
//Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1 = 0;
    scanf("%d", &n1);

    //Create a new array of n1 ints
    int *a1 = (int *) malloc(sizeof(int) * n1);
    int i;
    for (i = 0; i < n1; i++) {
        //Set each value in a1 to 100
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    a1 = (int *) realloc_new(a1, n1* sizeof(int), n2 * sizeof(int));

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    for (int j = n1; j < n2; ++j) {
        a1[j] = 0;
    }


    for (i = 0; i < n2; i++) {
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    free(a1);
    return 0;
}
