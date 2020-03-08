#include <iostream>
#include <vector>

using namespace std;

void printVect(vector<int> vect) {
	cout << "----------------------------\n";
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
	cout << "\n";
}

void merge(vector<int>& vect, int startIndex, int middleIndex, int endIndex) {
	vector<int> leftVect, rightVect;
	int leftIndex = 0;
	int rightIndex = 0;
	int index = startIndex;

	int leftSize = middleIndex - startIndex + 1;
	int rightSize = endIndex - middleIndex;

	// Add left vector
	for (int i = 0; i < leftSize; i++) {
		leftVect.push_back(vect[startIndex + i]);
	}

	// Add right vector
	for (int i = 0; i < rightSize; i++) {
		rightVect.push_back(vect[middleIndex + i + 1]);
	}


	// Merge 2 vector to original vect
	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (leftVect[leftIndex] <= rightVect[rightIndex]) {
			// If left value is smaller than right value, add to vect
			int a = leftVect[leftIndex];
			vect[index] = a;
			leftIndex++;
		} else {
			// If right value is smaller than left value, add to vect
			int b = rightVect[rightIndex];
			vect[index] = b;
			rightIndex++;
		}
		index++;
	}

	// Copy remaining left vect
	while (leftIndex < leftSize) {
		vect[index] = leftVect[leftIndex];
		leftIndex++;
		index++;
	}

	// Copy remaining right vect
	while (rightIndex < rightSize) {
		vect[index] = rightVect[rightIndex];
		rightIndex++;
		index++;
	}
}

void mergeSort(vector<int>& vect, int leftIndex, int rightIndex) {
	if (leftIndex < rightIndex) {
		// Get middle index
		int middleIndex =	leftIndex + (rightIndex - leftIndex)/2;

		// Split left vect
		mergeSort(vect, leftIndex, middleIndex);

		// Split right vect
		mergeSort(vect, middleIndex + 1, rightIndex);

		// Merge 2 vectors together (not sorting yet)
		merge(vect, leftIndex, middleIndex, rightIndex);
	}
}

int main() {
	vector<int> test_data = { 3, 1,2,5,4};
	mergeSort(test_data, 0, test_data.size() - 1);
	printVect(test_data);
	return 0;
}
