// ============================================================
// TND012: Dugga 1
// Name: Antonio
// Personal number: 9902268334
// LiU-id: Antta839
// ============================================================

/*What does the program compute ?
The program computes the likelihood of an 2D point within [-1,1] is to be in an unit circle compared to unit square
or in other words how many times will the 2D point be in the circle which has ´bigger area compared to the square 

Test: samples 20 => ratio = 3.8
Test: samples 200 => ratio =  2.8214286
Test: samples 2000 => ratio = 3.2964509
*/
#include <iostream>
#include <cstdlib> // rand
#include <vector> // vectors
#include <cmath> // sqrt, abs
#include <iomanip>  //setprecision, fixed
#include <ctime> // used for seeding the random generator

using namespace std;

struct Point {
	double x_coord = 0.0;
	double y_coord = 0.0;
};


/****************************************
 * Function declarations (prototypes)    *
 *****************************************/

int getNumberOfSamples();     // gets the users input from how many samples they want to be tested
double getRandomNumber();      // gets a random number within [-1,1]
Point getRandomPoint();        // gives a point a random number 
bool insideSquare(Point p);    // checks if point is in square
bool insideCircle(Point p);    // checks if point is in circle
void printRatio(int a, int b); // prints out the ratio between points in circle and square


/**************************
 * 3. MAIN                *
 **************************/


int main() {
	//use current time as seed for random generator
	srand((unsigned)time(0));

	int counterSquare = 0.0;
	int counterCircle = 0.0;
	int quantity = getNumberOfSamples(); // number of samples user wants

	vector<Point> collection; // creates a list of point according on how many the user want to look at
	for (int i = 0; i < quantity; ++i) {
		Point p = getRandomPoint();
		collection.push_back(p);
	}
	
	for (int i = 0; i < quantity; ++i) {
		if (insideSquare(collection[i])) {
			++counterSquare;
		}
		if (insideCircle(collection[i])) {
			++counterCircle;
		}
	}
	printRatio(counterSquare, counterCircle);
}


/*************************************
 * Function definitions               *
 **************************************/


int getNumberOfSamples(){
	int number = 0;
	cout << "Number of samples: ";
	cin >> number;
	return number;
}

double getRandomNumber() {
	// create a random number between 0 and 1 (range [0, 1])
	constexpr double Max = RAND_MAX;
	double r = rand() / Max; // random number r is within [0, 1]
	// the range can be adjusted by scaling and offset
	double r2 = 2.0 * r - 1.0; // now the random number r2 is within [-1, 1]
	return r2;
}

Point getRandomPoint() {
	// Gives random number within [-1,1] to both x and y coordinate.
	Point p;
	p = { getRandomNumber() ,getRandomNumber() };
	return p;
}

bool insideSquare(Point p) {
	const double side = 0.5;
	
	if (abs(p.x_coord) <= side && abs(p.y_coord) < side) {
		return true;
	}
	else {
		return false;
	}
}

bool insideCircle(Point p) {
	const int radius = 1;
	double x_point = p.x_coord;
	double y_point = p.y_coord;
	if(sqrt((x_point*x_point)+(y_point*y_point)) < radius) {
		
		return true;
	}
	else {
		return false;
	}
}

void printRatio(int counterSquare, int counterCircle) {
	if (counterSquare > 0 && counterCircle > 0) {
		double ratio = (double)counterCircle / (double)counterSquare;
		if (ratio > 0) {
			cout << "Ratio: " << fixed <<setprecision(7) << ratio << endl;
		}
	}
	else {
		cout << "There was no point in circle or it was no point in square so ratio can't be determined" << endl;
	}
}

