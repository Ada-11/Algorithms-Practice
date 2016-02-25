#include <iostream>

using namespace std;

void printNth(int[], int);

int main() {

	/*
	 * Prompt:
	 * 		Given any lines:
	 * 			1 0 1 1 1 0 0 1
	 *			1 1 1 0 3 1 2 0 1 1
	 *			3 1 1 0 1 3 1 1 1 2 1 0 2 1
	 *
	 * 		Output:
	 * 			The following line
	 *
	 * Explanation: Line 2 is generated by line 1.
	 * 		Line 1: "1"
	 * 		Line 2: "11" (one 1)
	 * 			line 1: "0"
	 * 			Line 2: "10" (one 0)
	 * 				Line 1: "111"
	 * 				Line 2: "31" (three 1s)
	 * 					etc.
	 *
	 */

	int arr1[] = {1, 0, 1, 1, 1, 0, 0, 1};
	int arr2[] = {1, 1, 1, 0, 3, 1, 2, 0, 1, 1};

	printNth(arr1, 8);
	cout << "\n";
	printNth(arr2, 10);

}

void printNth(int arr[], int size) {

	int j, count = 0;
	for (int i = 0; i < size; i++) {

		//Check for duplicate sequences
		for (j = i; j < size ; j++) {
			if (arr[j] == arr[i]) {
				count++;
			} else {
				break;
			}
		}

		//Print-outs and modify i
		if (count > 0) {
			cout << count << arr[i];
			count = 0;
			i = j - 1;
		} else {
			cout << "1" << arr[i];
		}
	}
}
