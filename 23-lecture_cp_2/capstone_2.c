#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DEBUG 
#define MAX_ATTEMPTS 6

int random_number_generator(){
    srand(time(0));
    int rnum = rand() % 100 + 1;
    return rnum;    
}

int main(){
    printf("Guess a number between 1 and 100.\nYou get 5 attempts to guess the number.\n");
    
    int rnumber = random_number_generator();
    int attempts;
    int input;
    char continue_play;

    while (attempts <= MAX_ATTEMPTS){
        #ifdef DEBUG
            printf("DEBUG mode target numeber:%d\n", rnumber);
        #endif 
        
        for (attempts = 1; attempts <= MAX_ATTEMPTS; attempts++){
            printf("Pick a number (1-100):");
            
            int letter = scanf("%d", &input);
            
            if (attempts == MAX_ATTEMPTS){
                printf("Would you like to play again? (y/n): ");
                
                scanf("%c", &continue_play);
                
                if (continue_play == 'y' ||continue_play == 'Y'){
                    attempts = 1;
                    rnumber = random_number_generator();
                }
                else if (continue_play == 'n'|| continue_play == 'N'){
                    printf("Thank you for playing!");
                    return 0;
                }
                else{
                    printf("Ending program");
                    return 0;
                }
  
            }
            
            if (letter != 1){
                attempts--;
                printf("Please enter an integer between 1-100\n");
            }
            

            else if (input == rnumber ){
                printf("Congratulations! you successfully guessed the number in %d attempts.\nWould you like to play again? (y/n):\n", attempts);
                
                scanf("%c", &continue_play);
                
                if (continue_play == 'y' || continue_play == 'Y'){
                    attempts = 1;
                    rnumber = random_number_generator();
                }
                else if (continue_play == 'n' || continue_play == 'N'){
                    printf("Thank you for playing!");
                    return 0;
                }
                else{
                    printf("Ending program");
                    return 0;
                }
            }
            
            else if (input < rnumber ){
                printf("Guess higher\n");
            }
            
            else if (input > rnumber ){
                printf("Guess lower\n");
            }
            
            while (getchar() != '\n');
        }

    }
    
    return 0;

}