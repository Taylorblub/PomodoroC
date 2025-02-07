void displayHeader();

struct Time{
    int minutes;
    int seconds;
};

void pomodoro(struct Time timeWork, struct Time timeRest);
void getTimes(struct Time* timeWork, struct Time* timeRest);