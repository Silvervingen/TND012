// Dugga 3
//TND012 
// Antonio Tällberg Ilestad

#include <iostream>
#include <iomanip>
#include<tuple>

using namespace std;

const int SIZE = 100;

struct Line
{
	double m[SIZE];
	double b[SIZE];
};

//FUNCTIONS

//Read the wamted lines
int read_lines(double m[], double b[], int n)
{
	cout << "Enter a line L (m followed by b)";
	cin >> m[0] >> b[0];
	
	do
	{

		cout << "Enter how many lines you want ";
		cin >> n;
		if (n < 0 || n > 100)
		{
			cout << "Invalid number of lines !!" << endl << endl;
		}
	} while (n < 0 || n > 100);
	cout << "Enter " << n << " lines" << endl;
	for (int i = 1; i <= n; ++i)
		cin >> m[i] >> b[i];
	return n;
}

//Display the line
void display_line(double m[], double b[], int i, int n)
{
		if (b[i] > 0)
			cout << "y = " << m[i] << " x + " << b[i];
		if (b[i] < 0)
			cout << "y = " << m[i] << " x " << b[i];
			
}

bool is_parallel(double m[], int i)
{
	//for (int i = 1; i <= n; ++i)
	{
		if (m[i] == m[0])
		{
			return true;
		}
		else (m[i] != m[0]);
		{
			return false;
		}
	}
}

tuple<double, double> find_intersect_point(double m[], double b[], int n)
{
	for (int j = 1; j <= n; ++j)
	{
		double P_x = (b[j] * b[0]) / (m[j] - m[0]);
		double P_y = m[0] * P_x + b[0];
		return{ P_x,P_y };
	}
}


//Test if the line is parallel or has a intersection point
void Display_parallel(double m[], double b[], int i, int n)
{
	int counter = 0;
	for (int k = 1; k <= n; ++k)
	{
		if (is_parallel(m, i) == true)
		{
			display_line(m, b, n, i);
			cout << endl;
			counter++;
		}
	}
		if (counter < 1) {
			cout << "No parallel lines found!!" << endl;
		}
}
void Display_intersect(double m[], double b[], int i, int n)
{
	int counter_1 = 0;
	for (int k = 1; k <= n; ++k) 
	{
		display_line(m, b, n, i);
		cout << "( ";
		find_intersect_point(m, b, n);
		cout << ") " << endl;
		counter_1++;
	}
	
		if (counter_1 < 1) {
			cout << "No intersect lines found!!" << endl;
		}
}


int main()
{
	struct Line l;
	int n = 0;
	int i = 0;

	//Get the lines
	int number = read_lines(l.m, l.b, n);

	cout << "Lines parallel with line ";
	display_line(l.m, l.b, n, i);
	cout << endl;

	//Display_parallel
	Display_parallel(l.m, l.b, i, n);

	cout << "Lines intersect with line ";
	display_line(l.m, l.b, n, i);
	cout << endl;

	//Display_intersect
	Display_intersect(l.m, l.b, i, n);
}