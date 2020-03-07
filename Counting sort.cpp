#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MIN_VAL = 1;
const int MAX_VAL = 9;

int main() {
	vector<int> test_data = {1, 4, 1, 2, 7, 4 , 5 , 2};
	vector<int> myVect;
	vector<int> sortedVect;
	int val, frequency;

	myVect.resize(MAX_VAL);
	sortedVect.resize(test_data.size());

	// Generate frequency vector
	for (int i = 0; i < test_data.size(); i++) {
		myVect[test_data[i] - 1]++;
	}

	// Sum of previous indexes
	for (int i = 1; i <= myVect.size(); i++) {
		myVect[i] += myVect[i-1];
	}

	// Check sum and sort the array
	for (int i = 0; i < test_data.size(); i++) {
		val = test_data[i];
		frequency = myVect[val-1];

		sortedVect[frequency - 1] = val;
		myVect[val-1]--;
	}

	// Print array
	for (int i = 0; i < sortedVect.size(); i++) {
			cout << sortedVect[i] << " ";
		}
	return 0;
}
