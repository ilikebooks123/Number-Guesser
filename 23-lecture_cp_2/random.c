#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

int main(){
    srand (time(0));

    int random = (rand() %100) + 1;

    printf("%d", random);

    return 0;

}