#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> test_data = {3,2,1,4,5,7,6,10, 9};
	int temp, index;

	for (int i = 1; i < test_data.size(); i++) {
		temp = test_data[i];
		index = i - 1;

		while (temp < test_data[index] && index >= 0) {
			test_data[index+1] = test_data[index];
			index--;
		}

		test_data[index + 1] = temp;
	}

	// Print array
	for (int i = 0; i < test_data.size(); i++) {
			cout << test_data[i] << " ";
		}
	return 0;
}
