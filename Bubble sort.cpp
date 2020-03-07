#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> test_data = {1, 4, 1, 2, 7, 4 , 5 , 2};
	int temp;

	for (int i = 0; i < test_data.size(); i++) {
		for (int j = 0; j < test_data.size() - 1; j++ ) {
			if (test_data[i] < test_data[j]) {
				temp = test_data[i];
				test_data[i] = test_data[j];
				test_data[j] = temp;
			}
		}
	}

	for (int i = 0; i < test_data.size(); i++) {
		cout << test_data[i] << " ";
	}
	return 0;
}
