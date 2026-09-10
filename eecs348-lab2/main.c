#include <stdio.h>
#include "isOdd.h"

int main() {
    int num = 5; 
    if (isOdd(num)) {
        printf("%d is odd.\n", num);
    } else {
        printf("%d is even.\n", num);
    }
    return 0;
}