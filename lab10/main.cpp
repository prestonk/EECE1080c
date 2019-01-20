// Preston Knibbe

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


class Dictionary {
  public:
    Dictionary();
    Dictionary(string);
    string wordChooser(int, int);
  private:
    vector<string> wordBank;
    string fileName;
    void readFile();
    void printStats();
    int wordCount();
    int characterCount();
    double wordLength();
    void alphaWordCount();
    string longestWord();

};
Dictionary::Dictionary() {
  cout << "Filename to read: " << endl;
  cin >> fileName;
  readFile();
  printStats();
}
Dictionary::Dictionary(string file) {
  fileName = file;
  readFile();
  printStats();
}
void Dictionary::readFile() {
  fstream wordList(fileName.c_str());
  if (!wordList) {
    cout << "Error in reading file" << endl;
  }
  string temp;
  while (wordList >> temp) {
    wordBank.push_back(temp);
  }
}
string Dictionary::wordChooser(int startRange, int endRange) {
  srand(time(0));
  vector<string> tempList;
  for (int a = 0; a < wordBank.size(); a++) {
    if (wordBank[a].length() > startRange &&
        wordBank[a].length() < endRange) {
      tempList.push_back(wordBank[a]);
    }
  }
  int random = rand() % tempList.size() + 0;
  return tempList[random];
}

int Dictionary::wordCount() {
  return wordBank.size();
}

int Dictionary::characterCount() {
  int charCount = 0;
  string temp;
  for (int a = 0; a < wordBank.size(); a++) {
    temp = wordBank[a];
    for (int b = 0; b < temp.length(); b++) {
      charCount++;
    }
  }
  return charCount;
}

double Dictionary::wordLength() {
  double avg = characterCount() / wordCount();
  return avg;
}

void Dictionary::alphaWordCount() {
  cout << "Words in dictionary by letter" << endl;
  for (int a = 97; a <= 122; a++) {
    cout << (char) a << ": ";
    int counter;
    for (int b = 0; b < wordBank.size(); b++) {
      if (wordBank[b].at(0) == (char) a) {
        counter++;
      }
    }
    for (int c = 0; c <= (counter/2000); c++) {
      cout << "*";
    }
    cout << endl;
  }
}

string Dictionary::longestWord() {
  string longest;
  int length = 0;
  for (int a = 0; a < wordBank.size(); a++) {
    if (wordBank[a].length() > length) {
      longest = wordBank[a];
    }
  }
  return longest;
}


void Dictionary::printStats() {
  cout << "Total number of words: " << wordCount() << endl;
  cout << "\n";
  cout << "Total characters: " << characterCount() << endl;
  cout << "\n";
  cout << "Average characters per word: "
        << wordLength()
         << endl;
  alphaWordCount();
  cout << "\n";
  cout << "Longest word: " << longestWord() << endl;

}


class Hangman {
  public:
    Hangman();
    void gameDriver();
    void setWord(string);
  private:
    const int STRIKES = 6;
    int strikeCounter;
    string secretWord;
    string missedLetters;
    char guess;
    string correctLetters;
};

Hangman::Hangman() {
  strikeCounter = 0;
  missedLetters = "";
  correctLetters = "";
}

void Hangman::setWord(string word) {
  secretWord = word;
}


void Hangman::gameDriver() {
  cout << "Welcome to Hangman" << endl;
  while(strikeCounter < STRIKES) {
    char tempLetter;
    cout << "Guess:";
    for (int a = 0; a < secretWord.length(); a++) {
      bool tester = false;
      for (int c = 0; c < correctLetters.length(); c++) {
        if (secretWord[a]==correctLetters[c]) {
          tempLetter = correctLetters[c];
          tester = true;
        }
      }
      if (tester) {
        cout << tempLetter;
      } else {
        cout << "_";
      }
    }
    cout << " misses remaining: "
          << (STRIKES - strikeCounter)
          << " missed letters: "
          << missedLetters
           << endl;
    cin >> guess;
    bool guessTest = false;
    for (int b = 0; b < secretWord.length(); b++) {
      if (guess == secretWord.at(b)) {
        guessTest = true;
      }
    }
    if (guessTest) {
      correctLetters += guess;
    } else {
      missedLetters += guess;
      strikeCounter++;
    }
    if (correctLetters.length() == secretWord.length()) {
      break;
    }
  }
  if (strikeCounter < STRIKES) {
    cout << "You won!" << endl;
  } else {
    cout << "You lose, the word was " << secretWord << endl;
  }



}

int main()
{
  Dictionary Test("dictionary2.txt");
  /*bool playAgain = true;
  do {
    string word = Test.wordChooser(4,8);
    Hangman Game1;
    Game1.setWord(word);
    Game1.gameDriver();
    char play;
    cout << "Do you want to play again? (Y/N)" << endl;
    cin >> play;
    if (play=='N') {
      playAgain = false;
    }
  } while (playAgain);
  */
  return 0;
}
