#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void populate_array(int *arr, int num_elements) {
	for (int i=0; i < num_elements; i++) {
		*(arr + i) = rand();
	}
}

void print_array(int *arr, int num_elements) {
	for (int i=0; i < num_elements; i++) {
		cout << *(arr + i);
		if (i < num_elements - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

void bubble_sort(int *arr, int num_elements) {
	for (int i=0; i < num_elements; i++) {
		for (int j=i+1; j < num_elements; j++) {
			if (*(arr+i) > *(arr+j)) {
				int temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
}

void insertion_sort(int *arr, int num_elements) {
	  for (int i=1; i < num_elements; i++) {
	    int val = *(arr+i);
	    int j;
	    for (j=i; j > 1; j++) { // descending
	      if (*(arr + j-1) > val) {
	        *(arr + j) = *(arr + j - 1);
	      }
	      else {
	        break;
	      }
	    }
	    *(arr + j) = val;
	  }
	}


int main() {

	int num;
	cout << "How many integers would you like to sort? ";
	cin >> num;

	srand(time(NULL));

	int *num_array = new int[num];
	populate_array(num_array, num);
	//print_array(num_array, num);
	int before = time(NULL);
	bubble_sort(num_array, num);
	int after = time(NULL);
	cout << "Bubble Sort run time: " << (after - before) << " seconds" << endl;
	//print_array(num_array, num);
	insertion_sort(num_array, num);
	//print_array(num_array, num);
	int after1 = time(NULL);
	cout << "Insertion Sort run time: " << (after1 - after) << " seconds" << endl;

	delete [] num_array; // deallocate num_array
	return 1;
}

