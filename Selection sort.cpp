#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> test_data = {1, 4, 1, 2, 7, 4 , 5 , 2};
	int index, temp, min;

	for (int i = 0; i < test_data.size() - 1; i++) {
		min = test_data[i];
		index = i;
		// find min
		for (int j = i+1; j < test_data.size(); j++) {
			if (test_data[j] <= min) {
				min = test_data[j];
				index = j;
			}
		}
		// Swap min with current position
		temp = test_data[i];
		test_data[i] = test_data[index];
		test_data[index] = temp;
	}

	// Print array
	for (int i = 0; i < test_data.size(); i++) {
			cout << test_data[i] << " ";
		}
	return 0;
}
