#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include "my_module.h"

int random_number_generator(){
    srand(time(0));
    int rnum = rand() % 100 + 1;
    return rnum;    
}

void win_message(int x){
    printf("Congratulations! you successfully guessed the number in %d attempts.\nWould you like to play again? (y/n):\n", x);
}

void guess_lower(){
    printf("Guess lower\n");
}

void guess_higher(){
    printf("Guess higher\n");
}

void ask_continue_message(){
    printf("Would you like to play again? (y/n):");
}

void error_message(){
    printf("Please enter an integer between 1-100\n");
}

void introduction_message(){
    printf("Welcome to Number Guesser.\nGuess a number between 1 and 100 in 5 attempts as the system gives you hints.\n");
}

void continue_message(){
    printf("you have chosen to continue playing\n");
}

void dis_continue_message(){
    printf("Thank you for playing!");
}

void num_range_message(){
    printf("Pick a number (1-100):\n");
}

void debug_messages(int y){
    printf("DEBUG mode target numeber:%d\n", y);
}