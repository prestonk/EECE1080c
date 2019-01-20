// Preston Knibbe
// Version 2

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
    void Rules();
    void printMove(char, int, int);
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
      printMove(player, xCord, yCord);
      board[xCord][yCord] = player;
      test = false;
    }
  }
}

void TicTacToe::printMove(char player, int x, int y) {
  cout << player << " marked " << board[y][x] << endl;
}

void TicTacToe::Rules(char player) {
  // First player chooses middle of board
  if (turnCount==0) {
    board[1][1] = player;
    printMove(player, 1, 1);
    break;
  }

  // Makes the second turn a corner pick
  if (turnCount==2) {
    int rand = randomNum(1,4);
    if (rand==1 && placeCheck(0,0)) {
      board[0][0] = player;
      printMove(player, 0, 0);
      break;
    } else if (rand==2 && placeCheck(2, 0)) {
      board[2][0] = player;
      printMove(player, 0, 2);
      break;
    } else if (rand==3 && placeCheck(0, 2)) {
      board[0][2] = player;
      printMove(player, 2, 0);
      break;
    } else if (rand==4 && placeCheck(2, 2)) {
      board[2][2] = player;
      printMove(player, 2, 2);
      break;
    }
  }

  // Winning move block

  //Vertical Block
  for (int a = 0; a < 3; a++) {
    if (board[a][0] == board[a][1] &&
        board[a][0] != player &&
        placeCheck(a, 2)) {
      board[a][2] = player;
      printMove(player, 2, a);
      break;
    } else if (board[a][1] == board[a][2] &&
               board[a][1] != player &&
               placeCheck(a, 0)) {
      board[a][0] = player;
      printMove(player, 0, a);
      break;
    } else if (board[a][0] == board[a][2] &&
               board[a][0] != player &&
               placeCheck(a, 1)) {
      board[a][1] = player;
      printMove(player, 1, a);
      break;
    }
  }
  //Horizontal Block
  for (int a = 0; a < 3; a++) {
    if (board[0][a] == board[1][a] &&
        board[0][a] != player &&
        placeCheck(2, a)) {
      board[2][a] = player;
      printMove(player, a, 2);
      break;
    } else if (board[1][a] == board[2][a] &&
               board[1][a] != player &&
               placeCheck(0, a)) {
      board[0][a] = player;
      printMove(player, a, 0);
      break;
    } else if (board[0][a] == board[2][a] &&
               board[0][a] != player &&
               placeCheck(1, a)) {
      board[1][a] = player;
      printMove(player, a, 1);
      break;
    }
  }
  //Diagonal Blocks
  if (board[0][0] == board[1][1] &&
      board[0][0] != player &&
      placeCheck(2, 2)) {
    board[2][2] = player;
    printMove(player, 2, 2);
    break;
  } else if (board[2][2] == board [1][1] &&
             board[2][2] != player &&
             placeCheck(0, 0)) {
    board[0][0] = player;
    printMove(player, 0, 0);
    break;
  } else if (board[0][2] == board [1][1] &&
             board[0][2] != player &&
             placeCheck(2, 0)) {
    board[2][0] = player;
    printMove(player, 0, 2);
    break;
  } else if (board[2][0] == board [1][1] &&
             board[2][0] != player &&
             placeCheck(0, 2)) {
    board[0][2] = player;
    printMove(player, 0, 2);
    break;
  }



  // Win set up

  // Attempt at vertical win
  for (int a = 0; a < 3; a++) {
    if (board[a][0] == board[a][1] &&
        board[a][0] == player &&
        placeCheck(a, 2)) {
      board[a][2] = player;
      printMove(player, 2, a);
      break;
    } else if (board[a][1] == board[a][2] &&
               board[a][1] == player &&
               placeCheck(a, 0)) {
      board[a][0] = player;
      printMove(player, 0, a);
      break;
    } else if (board[a][0] == board[a][2] &&
               board[a][0] == player &&
               placeCheck(a, 1)) {
      board[a][1] = player;
      printMove(player, 1, a);
      break;
    }
  }
  // Attempt at horizontal win
  for (int a = 0; a < 3; a++) {
    if (board[0][a] == board[1][a] &&
        board[0][a] == player &&
        placeCheck(2, a)) {
      board[2][a] = player;
      printMove(player, 2, a);
      break;
    } else if (board[1][a] == board[2][a] &&
               board[1][a] == player &&
               placeCheck(0, a)) {
      board[0][a] = player;
      printMove(player, 0, a);
      break;
    } else if (board[0][a] == board[2][a] &&
               board[0][a] == player &&
               placeCheck(1, a)) {
      board[1][a] = player;
      printMove(player, a, 1);
      break;
    }
  }
  // Attempt at diagonal win
  if (board[0][0] == board[1][1] &&
      board[0][0] == player &&
      placeCheck(2, 2)) {
    board[2][2] = player;
    printMove(player, 2, 2);
    break;
  } else if (board[2][2] == board [1][1] &&
             board[2][2] == player &&
             placeCheck(0, 0)) {
    board[0][0] = player;
    printMove(player, 0, 0);
    break;
  } else if (board[0][2] == board [1][1] &&
             board[0][2] == player &&
             placeCheck(2, 0)) {
    board[2][0] = player;
    printMove(player, 0, 2);
    break;
  } else if (board[2][0] == board [1][1] &&
             board[2][0] == player &&
             placeCheck(0, 2)) {
    board[0][2] = player;
    printMove(player, 2, 0);
    break;
  }

  turn(player);


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
      Rules(whoStarted);
    } else {
      Rules(whoDidntStart);
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
