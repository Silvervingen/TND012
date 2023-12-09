// TND012
// dugga 1
// Author: Antonio Ilestad, Antta839


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	constexpr double PROCENT = 0.5;
	constexpr double DELIVERY = 120;

	int Services = 0.0;
	int Amount_of_tree = 0.0;
	
	double Price_d = 0.0;
	double Price_h1 = 0.0;
	double Price_h2 = 0.0;
	double Price_h3 = 0.0;
	double Price_p = 0.0;
	double Height = 0.0;
	double Price_h4 = 0.0;
	double Final_price = 0.0;
	double Price_h = 0.0;
	double Price_t = 0.0;
	double Price_H = 0.0;
	double Price_b = 0.0;

	bool invalid_input = false;
	bool invalid_input_2 = false;

	cout << fixed << setprecision(2);
	do
	{
		//Enter the amount of trees to be purchased
		cout << "Enter the amount of trees you want to buy" << endl;
		cin >> Amount_of_tree;

		// Enter the hight of the trees
		cout << "Enter the hight of the trees in meters" << endl;
		cin >> Height;

		// Prices for the trees

		if (Height < 1)
		{
			Price_h1 = 50;
		}
		if (1 <= Height && Height < 2)
		{
			Price_h2 = 109;
		}
		if (2 <= Height && Height < 3)
		{
			Price_h3 = 199;
		}
		if (Height >= 3)
		{
			Price_h4 = 299.50;
		}
	
	// Extra services 
		cout << setw(30) << setfill('-') << "-" << endl;
		cout << "Press 0 for no added services" << endl;
		cout << "Press 1 for Delivery" << endl;
		cout << "Press 2 for Planting help" << endl;
		cout << "Press 3 for both services" << endl;
		cout << setw(30) << setfill('-') << "-" << endl;

	// Read user option
	cin >> Services;
	Price_h = Price_h1 + Price_h2 + Price_h3 + Price_h4;
	Price_p = PROCENT * Price_h * Amount_of_tree;
	Price_b = Price_d + Price_p;

	//Decide the outcome from user choice
	switch (Services)
	{
	case 0: // no services
		cout << endl;

		break;
	case 1: // Delivery cost
 
		if (Amount_of_tree <= 5)
		{
			Price_d = Amount_of_tree * DELIVERY;
		}

		else
		{
			Price_d = 600;
		}

		   break;
	case 2: // planting cost
		Price_p;
		   break;
	case 3:
		if (Amount_of_tree <= 5)
		{
			Price_d = Amount_of_tree * DELIVERY;
		}

		else
		{
			Price_d = 600;
		}
		Price_b;
		   break;
	}

	// if they type in a negative number
	invalid_input = (0 > Height || 0 > Amount_of_tree);
	invalid_input_2 = (0 > Services || 3 < Services);
	

	if (invalid_input || invalid_input_2 )                                    // next kommande rader så har || lags till. 
	{
		cout << "invalid input, try again" << endl << endl;
	}

	} while (invalid_input || invalid_input_2 );
	
	//the final price
	Price_H = Price_h1 + Price_h2 + Price_h3 + Price_h4;
	Price_t = Price_h * Amount_of_tree;
	Final_price = Price_d + Price_p + Price_t;


	cout << "====================================" << endl;
	cout << "              Invoice               " << endl;
	cout << "====================================" << endl;
	cout << Amount_of_tree << "trees * " << Price_H << " each ........... " << Price_t << endl;
	cout << "Delivery cost        ........... " << Price_d << endl;
	cout << "Planting cost        ........... " << Price_p << endl;
	cout << "Total cost           ........... " << Final_price << endl;

	return 0;
}