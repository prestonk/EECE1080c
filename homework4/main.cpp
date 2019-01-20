//Preston Knibbe
//October 1, 2015

#include <iostream>

using namespace std;


int *InputGrades(int* grade) {
  cout << "Enter Quiz 1 Grade:" << endl;
  cin >> grade[0];
  cout << "Enter Quiz 2 Grade:" << endl;
  cin >> grade[1];
  cout << "Enter Quiz 3 Grade:" << endl;
  cin >> grade[2];
  cout << "Enter Homework 1 Grade:" << endl;
  cin >> grade[3];
  cout << "Enter Homework 2 Grade:" << endl;
  cin >> grade[4];
  cout << "Enter Homework 3 Grade:" << endl;
  cin >> grade[5];
  cout << "Enter Exam 1 Grade:" << endl;
  cin >> grade[6];
  cout << "Enter Exam 2 Grade:" << endl;
  cin >> grade[7];
  cout << "Enter Final Exam Grade:" << endl;
  cin >> grade[8];
  return grade;

}

double CalculateWeightedAverage(int* grade) {
  double quizAvg = (grade[0] + grade[1] + grade[2]) / 3 * 0.25;
  double hwAvg = (grade[3] + grade[4] + grade[5]) / 3 * 0.2;
  double exam1Avg = grade[6] * 0.15;
  double exam2Avg = grade[7] * 0.15;
  double finalAvg = grade[8] * 0.15;
  double attendance = 10;
  double average = quizAvg + hwAvg + exam1Avg + exam2Avg + finalAvg + attendance;
  return average;
}

char DetermineLetterGrade(int avg) {
  if (avg >= 90) {
    return 'A';
  } else if (avg >= 80 && avg <= 89) {
    return 'B';
  } else if (avg >= 70 && avg <= 79) {
    return 'C';
  } else if (avg >= 60 && avg <= 69) {
    return 'D';
  } else if (avg < 60) {
    return 'F';
  }
}

void DisplayStudentResults(int avg, char grade) {
  cout << "Grade Weighted Average is " << avg << endl;
  cout << "Letter Grade: " << grade << endl;
}


int main()
{
  bool test = true;
  string tester;
  while (test) {
    int gradeBank[9];
    int *grade = InputGrades(gradeBank);
    double avg = CalculateWeightedAverage(grade);
    char letterGrade = DetermineLetterGrade(avg);
    DisplayStudentResults(avg, letterGrade);
    cout << "To calculate grades for another student type 'Next' to exit type 'Exit'" << endl;
    cin >> tester;
    if (tester == "Next") {
      test = true;
    } else if (tester == "Exit") {
      test = false;
    }
  }

  return 0;
}

