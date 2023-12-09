// ============================================================
// TND012: Dugga 1
// Name: Antonio
// Personal number: 9902268334
// LiU-id: Antta839
// ============================================================


/* Test data of example 1
80  3 87 62 30 90 10 21 46 27
12 49 83  9 39 88 95 59 20 37
80 40 87 67 31 90 11 24 56 77
*/

/* Test data of example 2
80  3 87 62 30 90 10 21 46 27
12 49 83  9 39 88 95 59 20 37
80 40 87 67 31 90 11 24 56 77
11 48 51 42  8 74 64 41 36 53
52 82 16 72 19 70 44 56 29 33
54  1 99 14 23 22 94 79 55  2
60 86 34  4 31 63 84 89  7 78
43 93 97 45 25 38 28 26 85 49
47 65 57 67 73 69 32 71 24 66
92 98 96 77  6 75 17 61 58 13
35 81 18 15  5 68 91 50 76 12
*/

/* Test data of example 3
80  3 87 62 30 90 10 21 46 27
12 40 83  9 39 88 95 59 20 37
80 40 87 67 31 90 11 24 56 77
*/
/*
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int number_1 = 0;
	int number_2 = 0;
	int number_3 = 0;
	int number_4 = 0;
	int number_5 = 0;
	int number_6 = 0;
	int number_7 = 0;
	int number_8 = 0;
	int number_9 = 0;
	int number_10 = 0;
	int lucky = 0;
	int answer = 0;
	int winning = 0;
	
	const int prize = 2000;
	const int award = 1000;
	const int hundred = 100;
	const int more_ticket = 1;
	const int k = 10;

	bool state = false;
	bool all_numbers = false;

	vector<int> number;
	vector<int> lucky_numbers;
	vector<int> prize_numbers;

	do {
		// ask for tickets numbers
		cout << "Enter your ticket numbers: ";
		cin >> number_1 >> number_2 >> number_3 >> number_4 >> number_5 >> number_6 >> number_7 >> number_8 >> number_9 >> number_10;

		// skapa en array som samlar numren
		number.push_back(number_1);
		number.push_back(number_2);
		number.push_back(number_3);
		number.push_back(number_4);
		number.push_back(number_5);
		number.push_back(number_6);
		number.push_back(number_7);
		number.push_back(number_8);
		number.push_back(number_9);
		number.push_back(number_10);

		// ask if you want another ticket
		cout << "One more ticket ? ";
		cin >> answer;
		cout << endl;

		// Create an lucky number based on the values of number 1 and 10 from the ticket.
		lucky = number_1 + number_10;
		// puts the lucky numbers in an vector.
		lucky_numbers.push_back(lucky);
		//if an lucky number exists in a ticket than add it to the winnings
		if (lucky == number_2 || lucky == number_3 || lucky == number_4 || lucky == number_5 || lucky == number_6 || lucky == number_7 || lucky == number_8 || lucky == number_9) {
			winning = winning + prize;
		}

	} while (more_ticket == answer);

	// if an lucky number exists in a ticket then put it in the write out lucky number vector
	for (int i = 0; i < number.size()/k; ++i) {
		for (int j = 0; j < k; ++j) {
			if (lucky_numbers[i] == number[j + i * k]) {
				prize_numbers.push_back(number[j + i * k]);
			}
		}
	}

	// looks through the vector to see if 1-99 exists in the tickets numbers
	for (int i = 1; i < hundred; ++i) {
		state = false;
		for (int j = 0; j < number.size(); ++j) {
			if (i == number[j]) {
				state = true;
				break;
			}
		}
		if (state) {
			all_numbers = true;
			continue; // if true move on to next i-value
		}
		else {
			all_numbers = false;
			break; // if i-value dont exist then break and let all_number be false
		}
	}

	// if all 99 numbers exists in the combined tickets than add the award to the winning
	if (all_numbers == true) {
		winning = winning + award;
	}
	// printing out the winning amount
	cout << "Winning amount: " << winning << endl;

	// printing the lucky numbers
	if(prize_numbers.size() > 0)
	cout << "Your lucky numbers: ";
	for (int b = 0; b < prize_numbers.size(); ++b) {
		cout << prize_numbers[b] << " ";
	}
	cout << endl << endl;
}


*/