//TND012
//Dugga 2
//Antonio Iletsad

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
	int radius = 0;
	int length = 0;


	constexpr int VALIDATE = 5;
	bool invalid_input = false;

	//To validate the input
	do
	{
		cout << "Enter radius here" << endl;
		cin >> radius;
		cout << "Enter length here" << endl;
		cin >> length;

		invalid_input = (radius < VALIDATE || length < VALIDATE);

		if (invalid_input)
		{
			cout << "Invalid input, try again" << endl << endl;
		}

	} while (invalid_input);

	constexpr int SIZE = 100;
	constexpr int STOP = -5;

	int x_coordinate[SIZE] = { 0 };
	int y_coordinate[SIZE] = { 0 };
	int howMany = 0;
	
	double place = 0.0;

	int x_value = 0;
	int y_value = 0;

	//Get the coordinates for the points
	cout << "Enter the points" << endl;
	cin >> x_value;
	
	while ((cin >> x_value >> y_value) && (x_value != STOP) && (howMany < SIZE))
	{
		x_coordinate[howMany] = x_value;  // store value in the array for x
		y_coordinate[howMany] = y_value;  // store value in the array for y
		++howMany;                        // increment sequence's size
	
		

		place = sqrt((x_value * x_value) + (y_value * x_value));
	}

	for (int i = 0; i < howMany; i++)
	{
		

		if (place < radius)
		{
			cout << "The point (" << x_coordinate[i] << "," << y_coordinate[i] << ") is inside the circle " << endl;
		}

		else if (place > radius);
		{
			cout << "The point (" << x_coordinate[i] << "," << y_coordinate[i] << ") is outside the circle " << endl;
			
		}
		
	}

	


	return 0;
}






