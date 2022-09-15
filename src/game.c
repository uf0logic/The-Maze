//clang main.c -std=c99 -lncurses -o main
#include <stdbool.h>
#include <ncurses.h>
#include <stdlib.h>
//#include <unistd.h>

//#define DELAY 30000

void setup();
void draw();
void controller();
void enemyLogic();

bool gameOver;
int HP;
int yPos,xPos;
int yEnemy, xEnemy;
int yMax,xMax;

int main() {
    setup();

    while (gameOver != true) {
        if (HP < 0) gameOver = true;
        controller();
        draw();
        enemyLogic();

    }

    clear();
    mvprintw(yMax/2,xMax/2- 10,"Thanks for playing!!!");
    for (int i = 0; i < yMax/2; i++) printw("\n");
    refresh();

    return 0;
}

void setup() {
    //ncurses window setup
    initscr(); // Initialize game window
    cbreak(); // Sets the terminal so that it reads characters from keyboard immediately as they are typed, without waiting for carriage return
    noecho(); // don't echo any key presses
    curs_set(FALSE); // Don't display a cursor
    keypad(stdscr,TRUE); // Make keypad work

    //in-game variables setup
    gameOver = false;
    yMax = getmaxy(stdscr), xMax = getmaxx(stdscr);
    xPos = xMax/2, yPos = yMax/2; //Spawn player at the center
    xEnemy = 4, yEnemy = 4;
    HP = 100;
}

void controller() {
    switch(getch()) {
        case 'w':
            if (yPos > 0) {
                yPos--;
            }
            else {
                break;
            }
            break;
        case 'a':
            if (xPos > 0) {
                xPos--;
            }
            else {
                break;
            }
            break;
        case 's':
            if (yPos < yMax -1) {
                yPos++;
            }
            else {
                break;
            }
            break;
        case 'd':
            if (xPos < xMax -1) {
                xPos++;
            }
            else {
                break;
            }
            break;
        case 'o':
            gameOver = true;
    }

}

void draw() {
    clear(); // Clear the screen

    mvprintw(yPos, xPos, "@");
    mvprintw(yEnemy, xEnemy, "E");

}

void enemyLogic() {
    if (abs(xEnemy-xPos) < 3 && abs(yEnemy-yPos) < 3) {HP -= 10; beep();}
    if (xEnemy < xPos) xEnemy += 1;
    if (xEnemy > xPos) xEnemy -= 1;
    if (yEnemy < yPos) yEnemy += 1;
    if (yEnemy > yPos) yEnemy -= 1;

}