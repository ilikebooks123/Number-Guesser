#include<stdio.h>

#include <my_module.h>

int random_number_generator(){
    srand(time(0));
    int rnum = rand() % 100 + 1;
    return rnum;    
}