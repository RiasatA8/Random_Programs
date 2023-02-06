#include <bits/stdc++.h>
using namespace std;

int main() {
	int input; cin >> input;
	int leftoverI = input % 5;
	int id = input - leftoverI;
	int idstore = id;
	int counter = 0;
	int divisor;
	//cout << "Input - " << input << "\n"
	  //   << "Leftover - " << leftoverI << "\n"
		//<< "Dividend to be converted - " << id << "\n";

	string ConvertedNumber;
	int NumberLength = 1;
	for (int i = id; i >= 5; 1) {
		i /= 5;
		NumberLength++;
	}
	cout << "The final number will be " << NumberLength << " digits." << "\n"
		<< "-------" << "\n";
	while (ConvertedNumber.length() < NumberLength - 1) {
		counter++;
		divisor = pow(5, NumberLength - counter);
		id = (id - (id % divisor)) / divisor;
		ConvertedNumber += to_string(id);
		cout << divisor << "\n";
		cout << id << "\n";
		cout << divisor * id << "\n";
		idstore -= divisor * id;
		id = idstore;
		//counter = 0;
		cout << "-----" << "\n";
		if (id < 5 && ConvertedNumber.length() < NumberLength - 2) {
			ConvertedNumber += "0";
		}
	}
	ConvertedNumber += to_string(leftoverI);
	cout << ConvertedNumber << "\n";
}
