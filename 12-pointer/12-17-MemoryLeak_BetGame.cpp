/*
    *  Betting game
    ->  "Jack Queen King" - computer suffles these cards
    ->  player has to guess te position of queen.
    ->  if he wins, he takes 3*bet
    ->  if he looses, he losses the bet amount.
    ->  player has $100 initially
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

int cash = 100;

void play(int bet)
{
    /* here we allocate memroy in stack so it never change while we run this program */

    // char c[3] = {'J','Q','K'}

    /* 
        here we allocate memory in heap everytime on executing play function.
        so if we don't free heap memory then it uses more memory everytime while we calling play function and it turns into memory leak.
        but here we free that used memory at end of play function so this program not increasing used memory in ram it remains constant. 
    */

    char *c = (char *)malloc(3 * sizeof(char));

    c[0] = 'J', c[1] = 'Q', c[2] = 'K';
    cout << "shuffling...." << endl;

    srand(time(NULL)); // seeding random number generator

    int i;
    for (i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = c[x];
        c[x] = c[y];
        c[y] = temp;
    }
    int playersGuess;
    cout << "what's the position of queen 1,2 or 3 ? " << endl;
    cin >> playersGuess;
    if (c[playersGuess - 1] == 'Q')
    {
        cash += 3 * bet;
        cout << "you won and result is \" " << c[0] << " " << c[1] << " " << c[2] << " \" "
             << "and your cash is " << cash << endl;
    }
    else
    {
        cash -= bet;
        cout << "you loss and result is \" " << c[0] << " " << c[1] << " " << c[2] << " \" "
             << "and your cash is " << cash << endl;
    }
    free(c);
}

int main()
{
    int bet;
    cout << "welcome to virtual casino" << endl;
    cout << "total cash = " << cash << endl;
    while (cash > 0)
    {
        cout << "bet something" << endl;
        cin >> bet;
        if (bet == 0 || bet > cash)
            break;
        play(bet);
        cout << "------------------------------------" << endl;
    }

    return 0;
}