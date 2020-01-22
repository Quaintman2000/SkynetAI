#include <iostream>
#include <string>

using namespace std;

string myArray[63];
string disp;

int targetLocationPrediction;
int searchGridHighNumber = 64;
int searchGridLowNumber = 1;

bool solved = false;

inline string displayGrid() {
	string str = "";
	// displays grid
	for (int i = 0; i < 65; i++)
	{
		//Appropiately spaces & 0's for nums 1-8 for neatness then then skips to i=7 since it did them all.
		if ((i + 1) < 8)
		{
			str += " " + myArray[i] + "  " + myArray[i + 1] + "  " + myArray[i + 2] + "  "
				+ myArray[i + 3] + "  " + myArray[i + 4] + "  " + myArray[i + 5] + "  " + myArray[i + 6]
				+ "  ";
			i += 6;
		}
		//adds a space & a 0 infront of the 9
		else if ((i + 1) == 9) {
			str += " " + myArray[i] + " ";
		}
		//any number divisible by 8 makes a new line
		else if ((i + 1) % 8 == 0)
		{
			str += myArray[i] + "\n";
		}
		else
		{
			str += myArray[i] + " ";
		}
	}
	return str;
}

int main()
{
	//selects a random answer from 1 to 64
	int answer = rand() % 64;
	cout << "The answer is: " << answer << endl;
	//puts numbers 1-64 into the myArray array
	for (int i = 1; i <= 64; i++)
	{
		myArray[i - 1] = to_string(i);
	}
	//displays grid
	cout << disp << displayGrid() << endl;
	while (solved == false)
	{
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		if (targetLocationPrediction == answer) {
			cout << "found! " << targetLocationPrediction<< endl;
			solved = true;

			cout << disp << displayGrid() << endl;
		}
		else if (targetLocationPrediction > answer)
		{
			cout << "missed! " << targetLocationPrediction << endl;
			searchGridHighNumber = targetLocationPrediction;

			for (int i = targetLocationPrediction; i <= 64; i++)
			{
				myArray[i - 1] = " x";
			}

			cout << disp << displayGrid() << endl;
		}
		else if (targetLocationPrediction < answer)
		{
			cout << "missed! " << targetLocationPrediction << endl;
			searchGridLowNumber = targetLocationPrediction;

			for (int i = 1; i <= targetLocationPrediction; i++)
			{
				myArray[i - 1] = " x";
			}

			cout << disp << displayGrid() << endl;
		}
	}
}

// original grid display
	//for (int i = 0; i < 65; i++)
	//{
	//	//Appropiately spaces & 0's for nums 1-8 for neatness then then skips to i=7 since it did them all.
	//	if ((i+1) < 8) 
	//	{
	//		cout << "0" << myArray[i] << " 0" << myArray[i+1] << " 0" << myArray[i+2] << " 0" 
	//			<< myArray[i + 3] << " 0" << myArray[i+4] << " 0" << myArray[i + 5] << " 0" << myArray[i + 6]
	//			<< " 0" ;
	//		i += 6;
	//	}
	//	//adds a space & a 0 infront of the 9
	//	else if ((i + 1) == 9) {
	//		cout << "0" << myArray[i] << " ";
	//	}
	//	//any number divisible by 8 makes a new line
	//	else if ((i + 1) % 8 == 0)
	//	{
	//		cout << myArray[i] << endl;
	//	}
	//	else
	//	{
	//		cout << myArray[i] << " ";
	//	}
	//}
