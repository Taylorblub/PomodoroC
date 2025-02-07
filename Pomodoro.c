#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "pomodoro.h" //Didn't use the time.h library

int main() {

    struct Time timeWork;
    struct Time timeRest;
    char menu = 'y';

    do{
    
    displayHeader();
    getTimes(&timeWork, &timeRest);
    pomodoro(timeWork, timeRest);
    printf("Would you like to continue work? Enter q to quit. Enter any other char to continue.\n");
    scanf(" %c", &menu);

    }
    while(menu != 'q');
    
    printf("\aSleeping...\n");
    Sleep(1500);

    return 0;
}

void pomodoro(struct Time timeWork, struct Time timeRest){

    printf("Working for %d minute(s) and %d second(s)...\n", timeWork.minutes, timeWork.seconds);
    Sleep(timeWork.minutes*60000 + timeWork.seconds*1000); //minutes (in seconds) + seconds
    printf("\aStop Working.\n");
    printf("Resting for %d minute(s) and %d second(s)...\n", timeRest.minutes, timeRest.seconds);
    Sleep(timeRest.minutes*60000 + timeRest.seconds*1000);
    printf("\aStop Resting.\n");
}

void displayHeader(){
    printf("  _____                          _                 \n");
    printf(" |  __ \\                        | |                \n");
    printf(" | |__) |__  _ __ ___   ___   __| | ___  _ __ ___  \n");
    printf(" |  ___/ _ \\| '_ ` _ \\ / _ \\ / _` |/ _ \\| '__/ _ \\ \n");
    printf(" | |  | (_) | | | | | | (_) | (_| | (_) | | | (_) |\n");
    printf(" |_|   \\___/|_| |_| |_|\\___/ \\__,_|\\___/|_|  \\___/ \n");
    printf("                                                   \n\n\n");
    printf("Welcome to the Pomodoro App\n");

}

void getTimes(struct Time* timeWork, struct Time* timeRest){
    int minutesWork;
    int secondsWork;
    int minutesRest;
    int secondsRest;

    printf("How many minutes would you like to work? Standard method is 25. Minimum: 1\n"); //if the user types 0, the compiler will assume the user is typing octal numbers, which will cause another error if it sees an 8 or 9.
    scanf("%d", &minutesWork);
    printf("How many seconds would you like to work? Minimum: 1\n");
    scanf("%d", &secondsWork);

    printf("How many minutes would you like to rest? Standard method is 5. Minimum: 1\n");
    scanf("%d", &minutesRest);
    printf("How many seconds would you like to rest? Minimum: 1\n");
    scanf("%d", &secondsRest);

    (*timeWork).minutes = minutesWork;
    (*timeWork).seconds = secondsWork;
    (*timeRest).minutes = minutesRest;
    (*timeRest).seconds = secondsRest;
}