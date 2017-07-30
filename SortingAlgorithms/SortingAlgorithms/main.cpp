#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include "Sort.h"
#include "Timer.h"
using namespace std;

int main()
{	
	/*Quick sort seems to be the fastest no matter what the size of the vector,
	However as the size of the list gets smaller the difference in speed between quickSort and the other sorts isn't that big of a difference. 
	Quick sort and Merge sort are the fastest algortihms because of the way they "divide and conquer" the list
	*/
	//generate random doubles
	srand((unsigned)time(NULL));
	double range = 1000;//set the range of random nums (1 - 1000)
	std::vector<double> v(1000, 0.0);
	for (int i = 0; i<v.size(); i++) {
		v.at(i) = (rand() / (double)RAND_MAX)*range;
	}
	cout << "With a vector size of " << v.size() << ": \n\n";
	Sort<double> q;
	q.selectionSort(v);
	cout << "Sort time of selection sort: " << q.getSortTime() << endl;
	cout << "Iterations of selection sort: " << q.getIterations() << endl << endl;
	for (int i = 0; i<v.size(); i++) {
		v.at(i) = (rand() / (double)RAND_MAX)*range;
	}
	q.insertionSort(v);
	cout << "Sort time of inserstion sort: " << q.getSortTime() << endl;
	cout << "Iterations of Insertion sort: " << q.getIterations() << endl << endl;
	for (int i = 0; i<v.size(); i++) {
		v.at(i) = (rand() / (double)RAND_MAX)*range;
	}
	q.quickSort(v);
	cout << "Sort time of quick sort: " << q.getSortTime() << endl;
	cout << "Iterations of quick sort: " << q.getIterations() << endl << endl;
	for (int i = 0; i < v.size(); i++) {
		v.at(i) = (rand() / (double)RAND_MAX)*range;
	}
	q.mergeSort(v);
	cout << "Sort time of merge sort: " << q.getSortTime() << endl;
	cout << "Iterations of mergesort: " << q.getIterations() << endl;

	return 0;
}