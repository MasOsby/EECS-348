#include "isEven.h"
#include "isOdd.h"
#include <stdio.h>
//Entry point 
//Asks user for a number then uses both isEven and isOdd
//returns 0 upon completeion 

int main() {
    int num;
    // User input for an interger 
    printf("Enter an integer: ");
    scanf("%d", &num);
    //function calls to isEven and isOdd
    isEven(num);
    isOdd(num);
    return 0;
}
