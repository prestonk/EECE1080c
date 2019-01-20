// Name: Preston Knibbe
// elevator controller (simulator)
// Finish functions marked with "Finish ME"

// Hints please finish the functions in the following order:

// int Elevator::Random(int StartRange, int EndRange)
// void Elevator::GetOnElevator()
// void Elevator::DetermineFloorAndDirection()
// void Elevator::ElevatorStatus()
// void Elevator::PrintStats()


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <vector>

using namespace std;

// CONSTANTS in C preprocessor language style (before the advent of the const keyword)
#define UP 0
#define DOWN 1
#define STOPPED 2

#define ON_ELEVATOR 3
#define WAITING 4
#define EMPTY 5

#define MAX_PEOPLE 10
#define TOP_FLOOR 10
#define BOTTOM_FLOOR 1

#define MAX_BUTTON_PUSHS 3

// Data type for a Elevator Passenger
struct Passenger
{
	int DestFloor;
	int SourceFloor;
	int State;		// ON_ELEVATOR, WAITING, or EMPTY
	int Number;
};

class Elevator
{
	public:
		Elevator();
		// The ElevatorControl function calls the other functions in a logical
		// Manner
		void ElevatorControl();
	private:
	  int totalPeople;
		int Random(int,int);	// Function to Generator Random #s in a specific range
		// Data
		int CurrentDirection;	// (UpOrDown): States: UP/DOWN/STOPPED
		int CurrentFloor;	// Which floor is the Elevator on
		int LastPassengerID;	//
		int stats[TOP_FLOOR+1][3];// Stats Counters for ON/OFF/TO FULL
		vector<Passenger> Queue;	// Queue to get on Elevator
		Passenger ElevatorContents[MAX_PEOPLE];	// Persons on the Elevator

		// Functions that do most of the work.
		void ButtonPushed();
		void GetOffElevator();
		void GetOnElevator();
		void ElevatorStatus();
		void DetermineFloorAndDirection();
		void PrintStats();
};

// Constructor for elevator class. It just initializes the state of the internal
// class variables.
Elevator::Elevator()
{
	srand(time(0));

	LastPassengerID = 0;
	CurrentFloor = (TOP_FLOOR-BOTTOM_FLOOR)/2;
	CurrentDirection = DOWN;
	totalPeople = 0;

	for( int i = 0; i < MAX_PEOPLE;  i++)
		ElevatorContents[i].State = EMPTY;

	for(int i = BOTTOM_FLOOR; i < TOP_FLOOR+1;i++)
	{
		stats[i][0] = 0;
		stats[i][1] = 0;
		stats[i][2] = 0;
	}
}

// This function controls the entire simulation and it calls the other functions in the proper order
void Elevator::ElevatorControl()
{
	for ( int i = 0; i <= 100; i++)
	{
		ButtonPushed();
		ElevatorStatus();
		GetOffElevator();
		GetOnElevator();
		DetermineFloorAndDirection();
		if( (i % 50) == 0 && (i != 0)) {
			PrintStats();
		}
		//sleep(2);
	}
}

// This function determines in what direction and to what floor the elevator will
// go to next. If the elevator as at the BOTTOM_FLOOR than it should go UP and if the elevator is at
// the TOP_FLOOR it should go down. In all other cases it should continue going in the same direction.
//
// Finish ME
void Elevator::DetermineFloorAndDirection()
{
  if(ElevatorContents[0].State==EMPTY) {
    for (int a = 0; a < Queue.size(); a++) {
      if (Queue[a].State == WAITING) {
        CurrentFloor = Queue[a].SourceFloor;
        if (Queue[a].SourceFloor > Queue[a].DestFloor) {
          CurrentDirection = DOWN;
        } else if (Queue[a].SourceFloor < Queue[a].DestFloor) {
          CurrentDirection = UP;
        }
      }
    }
  } else {
    if (CurrentDirection == UP) {
      int nextFloor = TOP_FLOOR;
      for (int c = 0; c < MAX_PEOPLE; c++) {
        if (ElevatorContents[c].DestFloor < nextFloor &&
            ElevatorContents[c].DestFloor > CurrentFloor) {
          nextFloor = ElevatorContents[c].DestFloor;
        }
      }
      for (int x = 0; x < Queue.size(); x++) {
        if (Queue[x].SourceFloor > CurrentFloor &&
            Queue[x].SourceFloor < nextFloor &&
            Queue[x].DestFloor > Queue[x].SourceFloor) {
          nextFloor = Queue[x].SourceFloor;
        }
      }
      CurrentFloor = nextFloor;
    } else if (CurrentDirection == DOWN) {
      int nextFloor = BOTTOM_FLOOR;
      for (int a = 0; a < MAX_PEOPLE; a++) {
        if (ElevatorContents[a].DestFloor > nextFloor &&
            ElevatorContents[a].DestFloor < CurrentFloor &&
            Queue[a].DestFloor < Queue[a].SourceFloor) {
          nextFloor = ElevatorContents[a].DestFloor;
        }
      }
      for (int b = 0; b < Queue.size(); b++) {
        if (Queue[b].SourceFloor < CurrentFloor &&
            Queue[b].SourceFloor > nextFloor) {
          nextFloor = Queue[b].SourceFloor;
        }
      }
      CurrentFloor = nextFloor;
    }

  }
  if (CurrentFloor == TOP_FLOOR) {
    CurrentDirection = DOWN;
  } else if (CurrentFloor == BOTTOM_FLOOR) {
    CurrentDirection = UP;
  }
}

// This function places passengers in a Queue waiting for the elevator. It sets
// the status to WAITING for these new passengers. It makes sure that the passenger
// is actually going to a different floor.

void Elevator::ButtonPushed()
{
	for( int i = 0; i < Random(0, MAX_BUTTON_PUSHS); i++)
	{
		Passenger NewPerson;

		int SourceFloor  = Random(BOTTOM_FLOOR, TOP_FLOOR);
		int DestFloor    = Random(BOTTOM_FLOOR, TOP_FLOOR);


		while(SourceFloor == DestFloor)
		 	DestFloor = Random(BOTTOM_FLOOR, TOP_FLOOR);

		NewPerson.SourceFloor	= SourceFloor;
		NewPerson.DestFloor     = DestFloor;
		NewPerson.State 	 	= WAITING;
		NewPerson.Number 	 	= LastPassengerID;
		Queue.push_back(NewPerson);
		LastPassengerID++;
	}
}

// This function allows the passenger to leave the elevator once the elevator is at the correct
// floor and than updates the stats
// It sets it ElevatorContents to EMPTY to free up room for the next passenger to get on.
void Elevator::GetOffElevator()
{
	for( int i = 0; i < MAX_PEOPLE; i++) {
		if (ElevatorContents[i].State != EMPTY &&
				ElevatorContents[i].DestFloor == CurrentFloor) {
			ElevatorContents[i].State = EMPTY;
			cout << "\tPerson# " << ElevatorContents[i].Number
			     << " OFF on floor: "   << CurrentFloor
			     << " From floor: "
			     << ElevatorContents[i].SourceFloor
		  	     << endl;
			stats[CurrentFloor-1][1] = stats[CurrentFloor-1][1]  + 1;
			break;
		}
	}
}

// This function determines if the passenger get on. It checks the direction of the elevator,
// if the elevator has room for a new passenger, and what floor the passenger is waiting on to see if
// the elevator is on the correct floor the passenger.
// It removes the passenger from the queue by setting the passenger QUEUE STATE to EMPTY

// Finish ME
void Elevator::GetOnElevator()
{
	// The following for loop is for testing only
/*cout << Queue.size() << endl;
	for( int i = 0; i < Queue.size(); i++) {
		if(Queue[i].State == WAITING)
			cout << "Passenger Waiting on : " << Queue[i].SourceFloor <<
			 	" To go to floor: " << Queue[i].DestFloor << endl;
	}*/
	for(int i = 0; i < Queue.size(); i++) {
    if (Queue[i].SourceFloor == CurrentFloor) {
      if (Queue[i].DestFloor>Queue[i].SourceFloor && CurrentDirection == UP) {
        for (int b = 0; b < MAX_PEOPLE; b++) {
          if (ElevatorContents[b].State == EMPTY) {
            ElevatorContents[b] = Queue[i];
            ElevatorContents[b].State = ON_ELEVATOR;
            totalPeople ++;
            Queue[i].State = EMPTY;
            cout << "\tPerson# " << ElevatorContents[b].Number
                 << " ON at floor: "   << CurrentFloor
                 << " to go to: "
                 << ElevatorContents[b].DestFloor
                   << endl;
            break;
          } else {
            stats[CurrentFloor-1][2] = stats[CurrentFloor-1][2]  + 1;
          }
        }
      } else if (Queue[i].DestFloor<Queue[i].SourceFloor && CurrentDirection == DOWN) {
        for (int b = 0; b < MAX_PEOPLE; b++) {
          if (ElevatorContents[b].State == EMPTY) {
            ElevatorContents[b] = Queue[i];
            ElevatorContents[b].State = ON_ELEVATOR;
            totalPeople ++;
            Queue[i].State = EMPTY;
            cout << "\tPerson# " << ElevatorContents[b].Number
                 << " ON at floor: "   << CurrentFloor
                 << " to go to: "
                 << ElevatorContents[b].DestFloor
                   << endl;
            break;
          } else {
            stats[CurrentFloor-1][2] = stats[CurrentFloor-1][2]  + 1;
          }
        }
      }
    }
	}



  stats[CurrentFloor-1][0] = stats[CurrentFloor-1][0]  + 1;

	// This bit of code is used to clean the queue after someone gets on the elevator
	for( int i = 0; i < Queue.size(); i++) {
		if(Queue[i].State == EMPTY)
			Queue.erase(Queue.begin()+i);
	}
}

// Displays the Elevator Direction, Number of Passengers, Current Floor, and
// Sim Time (you will need to add Sim Time to your class (if you want to use it))

// Finish ME
void Elevator::ElevatorStatus()
{
  int people = 0;
  for (int a = 0; a < MAX_PEOPLE; a++) {
    if (ElevatorContents[a].State == ON_ELEVATOR) {
      people++;
    }
  }
  string direction;
  if (CurrentDirection == 0) {
    direction = "UP";
  } else if (CurrentDirection == 1) {
    direction = "DOWN";
  }
  cout << "Elevator Status: "
       << "  Floor: " << CurrentFloor
       << "  Number of Passengers: " << people
       << "  Direction: " << direction
        << endl;
}

// Displays the stats for number of passengers getting on and off at particular floor, total passengers
// Handled by the elevator, and if no room was on the elevator for new passengers.
// It mainly uses the stats[][] array.

// Finish ME
void Elevator::PrintStats()
{
  cout << "Floor\t" << "Src\t" << "Dstn\t" << "Full" << endl;
  for (int a = 0; a < TOP_FLOOR; a++) {
    cout << a+1 << "\t";
    for (int b = 0; b < 3; b++) {
      cout << stats[a][b] << "\t";
    }
    cout << endl;
  }
  cout << "Total passengers: " << totalPeople << endl;
}

// Returns a random number between StartRange and EndRange
// Finish ME
int Elevator::Random(int StartRange, int EndRange)
{
  int random = rand() % EndRange + StartRange;
  return random;
}

// Creates the class and runs the simulation
int main()
{
	Elevator Elevator1;

	Elevator1.ElevatorControl();

	return 0;
}
