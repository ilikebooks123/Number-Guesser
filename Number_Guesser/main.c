#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "my_module.h"

//#define DEBUG 
#define MAX_ATTEMPTS 6

int main(){
    introduction_message();
    
    int rnumber = random_number_generator();
    int attempts = 1;
    int input;
    char continue_play;

    while (attempts <= MAX_ATTEMPTS){
        #ifdef DEBUG
            debug_messages(rnumber);
        #endif 
        
        for (attempts = 1; attempts <= MAX_ATTEMPTS; attempts++){
            num_range_message();
            
            if (attempts == MAX_ATTEMPTS){
                ask_continue_message();
                scanf("%c", &continue_play);

                if (continue_play == 'y' ||continue_play == 'Y'){
                    attempts = 1;
                    rnumber = random_number_generator();
                    continue_message();
                }
                else{
                    dis_continue_message();
                    return 0;
                }
            }

            int letter = scanf("%d", &input);
            
            if (letter != 1){
                attempts--;
                error_message();
            }

            else if (input > 100){
                error_message();
            }

            else if (input == rnumber ){
                win_message(attempts);
                
                scanf("%c", &continue_play);
                
                if (continue_play == 'y' || continue_play == 'Y'){
                    attempts = 1;
                    rnumber = random_number_generator();
                    continue_message();
                }
                else if (continue_play == 'n' || continue_play == 'N'){
                    dis_continue_message();
                    return 0;
                }
            }
            
            else if (input < rnumber){
                guess_higher();
            }
            
            else if (input > rnumber){
                guess_lower();
            }
            
            while (getchar() != '\n');
        }

    }
    
    return 0;
}