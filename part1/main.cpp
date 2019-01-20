// Preston Knibbe
// Final Exam Part 1

#include <iostream>

using namespace std;

class Animal {
  public:
    Animal();
    Animal(string, string, string);
    void setLatinName(string);
    void setCommonName(string);
    void setSize(string);
    string getLatinName();
    string getCommonName();
    string getSize();
    // Prints animal data
    void printData();
  private:
    string latinName;
    string commonName;
    string Size;
};

Animal::Animal() {
}

Animal::Animal(string latin, string common, string Size2) {
  latinName = latin;
  commonName = common;
  if (Size2 == "Large" || Size2 == "Medium" || Size2 == "Small") {
    Size = Size2;
  } else {
    cout << "Size parameter must be either Large, Medium, or Small" << endl;
  }
}

void Animal::setLatinName(string latin) {
  latinName = latin;
}

void Animal::setCommonName(string common) {
  commonName = common;
}

void Animal::setSize(string Size2) {
  if (Size2 == "Large" || Size2 == "Medium" || Size2 == "Small") {
    Size = Size2;
  } else {
    cout << "Size parameter must be either Large, Medium, or Small" << endl;
  }
}

string Animal::getLatinName() {
  return latinName;
}

string Animal::getCommonName() {
  return commonName;
}

string Animal::getSize() {
  return Size;
}

void Animal::printData() {
  cout << "Common Name: " << commonName << endl;
  cout << "Latin Name: " << latinName << endl;
  cout << "Size of Animal: " << Size << endl;
  cout << "\n";
}


int main()
{
    Animal Parakeet("parakeetusmaximus", "Parakeet", "Small");
    Parakeet.printData();

    Animal Tiger;
    Tiger.setLatinName("tigris");
    Tiger.setCommonName("Tiger");
    Tiger.setSize("Large");
    Tiger.printData();
    return 0;
}
