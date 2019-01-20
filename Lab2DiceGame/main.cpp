/*
  Preston Knibbe
  September 15, 2015
  Lab 2 - Dice Game
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
  srand(time(NULL));
  int dice1Num = rand()%6 + 1;
  int dice2Num = rand()%6 + 1;
  int diceTotal = dice1Num + dice2Num;
  bool tester = true;

  //If - else loop
  while(tester) {
    if (diceTotal == 7 || diceTotal == 9 || diceTotal == 11) {
      cout << "You rolled a " << dice1Num << " and a "
      << dice2Num << " for a total of " << diceTotal << " which means you won!" << endl;
      tester = false;
    } else if (diceTotal == 2 || diceTotal == 3 || diceTotal == 5) {
      cout << "You rolled a " << dice1Num << " and a "
      << dice2Num << " for a total of " << diceTotal << " which means you lost." << endl;
      tester = false;
    } else {
      cout << "You rolled a " << dice1Num << " and a "
      << dice2Num << " for a total of " << diceTotal << " so you'll have to roll again." << endl;
      dice1Num = rand()%6 +1;
      dice2Num = rand()%6 + 1;
      diceTotal = dice1Num + dice2Num;
    }
  }

  //Switch - Case
  /*while(tester) {
    switch (diceTotal) {
      case 2:
        cout << "You rolled a " << dice1Num << " and a "
        << dice2Num << " for a total of " << diceTotal << " which means you lost." << endl;
        tester = false;
        break;
      case 3:
        cout << "You rolled a " << dice1Num << " and a "
        << dice2Num << " for a total of " << diceTotal << " which means you lost." << endl;
        tester = false;
        break;
      case 5:
        cout << "You rolled a " << dice1Num << " and a "
        << dice2Num << " for a total of " << diceTotal << " which means you lost." << endl;
        tester = false;
        break;
      case 7:
        cout << "You rolled a " << dice1Num << " and a "
        << dice2Num << " for a total of " << diceTotal << " which means you won." << endl;
        tester = false;
        break;
      case 9:
        cout << "You rolled a " << dice1Num << " and a "
        << dice2Num << " for a total of " << diceTotal << " which means you won." << endl;
        break;
      case 11:
        cout << "You rolled a " << dice1Num << " and a "
        << dice2Num << " for a total of " << diceTotal << " which means you won." << endl;
        tester = false;
        break;
      default:
        cout << "You rolled a " << dice1Num << " and a " << dice2Num << " for a total of " << diceTotal << " you'll have to roll again." << endl;
        dice1Num = rand()%6 +1;
        dice2Num = rand()%6 + 1;
        diceTotal = dice1Num + dice2Num;
        break;
    }
  }*/

  return 0;
}
