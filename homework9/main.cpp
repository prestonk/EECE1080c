// Preston Knibbe
// Version 1

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class TicTacToe {
  public:
    TicTacToe();
    void driver();
  private:
    char board[3][3] = {{'1', '4', '7'}, {'2', '5', '8'}, {'3', '6', '9'}};
    char whoStarted;
    char whoDidntStart;
    int turnCount;
    char winner;
    void printBoard();
    bool placeCheck(int, int);
    void whoStarts();
    bool winCheck();
    int randomNum(int,int);
    void turn(char);
    const int TOTAL_TURNS = 9;
};

TicTacToe::TicTacToe() {
  srand(time(0));
  whoStarts();
  turnCount = 0;
  cout << whoStarted << " goes first!" << endl;
}

int TicTacToe::randomNum(int startNum, int endNum) {
  startNum += 1;
  endNum += 1;
  int random = rand() % endNum + startNum;
  random -= 1;
  return random;
}

void TicTacToe::whoStarts() {
  if (randomNum(1,2)==1) {
    whoStarted = 'X';
    whoDidntStart = 'O';
  } else {
    whoStarted = 'O';
    whoDidntStart = 'X';
  }
}

void TicTacToe::turn(char player) {
  bool test = true;
  while (test) {
    int xCord = randomNum(0,2);
    int yCord = randomNum(0,2);
    if (placeCheck(xCord,yCord)) {
      cout << player << " marked " << board[xCord][yCord] << endl;
      board[xCord][yCord] = player;
      test = false;
    }
  }


}

bool TicTacToe::placeCheck(int x, int y) {
  if (board[x][y]=='O' || board[x][y]=='X') {
    return false;
  } else {
    return true;
  }
}

void TicTacToe::driver() {
  while (!winCheck() && turnCount < TOTAL_TURNS) {
    if ((turnCount%2)==0 || turnCount==0) {
      turn(whoStarted);
    } else {
      turn(whoDidntStart);
    }
    turnCount++;
  }
  if(turnCount == (TOTAL_TURNS) && !winCheck()) {
    cout << "Cats!" << endl;
    printBoard();
  } else if (winCheck()) {
    cout << "The winner is " << winner << endl;
    printBoard();
  }
}


bool TicTacToe::winCheck() {

  // Vertical Check
  for (int a = 0; a < 3; a++) {
    if (board[a][0]==board[a][1] &&
        board[a][1]==board[a][2]) {
      winner = board[a][0];
      return true;
    }
  }

  // Horizontal Check
  for (int b = 0; b < 3; b++) {
    if (board[0][b]==board[1][b] &&
        board[1][b]==board[2][b]) {
      winner = board[0][b];
      return true;
    }
  }

  // Diagonal Check
  if ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) ||
       (board[0][2]==board[1][1] && board[1][1]==board[2][0])) {
    winner = board[1][1];
    return true;
  }

  return false;


}


void TicTacToe::printBoard() {
  for (int a = 0; a < 3; a++) {
    cout << " " << board[0][a] << " | "
         << board[1][a] << " | "
         << board[2][a] << " "
          << endl;
    if (a<2) {
      cout << "-----------" << endl;
    }
  }
}


int main()
{
  TicTacToe Game1;
  Game1.driver();
  return 0;
}
