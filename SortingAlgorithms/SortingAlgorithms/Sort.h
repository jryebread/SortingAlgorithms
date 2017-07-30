#ifndef SORT_H
#define SORT_H
#include <vector>
#include "Timer.h"
template<class T>
class Sort
{
public:
	void insertionSort(std::vector<T> &a);
	void selectionSort(std::vector<T> &a);
	void quickSort(std::vector<T> &a);
	void mergeSort(std::vector<T> &a);
	int partition(std::vector<T>& a, int p, int q);
	double getSortTime();
	unsigned getIterations();

private:
	void mergeSort(std::vector<T>& a, std::vector<T>& tempArray, int left, int right);
	void merge(std::vector<T> &a, std::vector<T> & tempArray, int leftPos, int rightPos, int rightEnd);
	void quickSort(std::vector<T> &a,int left, int right);

	//holds the # of iterations of the last completed sort algorithm
	unsigned mCount;
	double sortTime = 0;
};


/*Function: insertionSort
Author:	James Riback
Description: performs insertion sort algorithm on a vector
Input: vector reference
*/
template<class T>
void Sort<T>::insertionSort(std::vector<T> &a)
{
	Timer t;
	t.startTimer(); //start timer
	unsigned count = 0;
	for (int p = 1; p < a.size(); ++p)
	{
		//number moving into sorted portion
		T tmp = a[p];

		int j; //index in unsorted portion
			   // itering through sorted portion right to left
			   // STOP iterating when our element to insert
			   // is less than the number to the left
		for (j = p; j > 0 && tmp < a[j - 1]; --j)
		{
			++count;
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
	t.stopTimer();  //end timer after sort
	sortTime = t.getSeconds();
	this->mCount = count;
}

/*Function: selectionSort
Author:	James Riback
Description: performs selection sort algorithm on a vector
Input: vector reference
*/
template<class T>
void Sort<T>::selectionSort(std::vector<T>& a)
{
	Timer t;
	t.startTimer(); //start timer
	unsigned count = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		int min = i; //min index
		for (int j = i + 1; j < a.size(); ++j)
		{
			++count;
			if (a[j] < a[min])
				min = j;
		}
		if (min != i) //swap if new min
			std::swap(a[min], a[i]);
	}
	t.stopTimer();  //end timer after sort
	sortTime = t.getSeconds();
	this->mCount = count;
}

/*Function: quickSort (public)
Author:	James Riback
Description: performs quick sort algorithm on a vector 
Input: vector reference
*/
template<class T>
void Sort<T>::quickSort(std::vector<T>& a)
{
	Timer t;
	t.startTimer(); //start timer
	this->mCount = 0;

	quickSort(a, 0, a.size());

	t.stopTimer();  //end timer after sort
	sortTime = t.getSeconds();
}

/*Function: quickSort(private)
Author:	James Riback
Description: performs quick sort algorithm on a vector
Input: vector reference, indexes to beggining and end
*/
template<class T>
void Sort<T>::quickSort(std::vector<T>& A, int p, int q)
{
	int r;
	if (p<q)
	{
		mCount++;
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}

/*Function: partition
Author:	James Riback
Description: partitions the vector
Output: returns an index integer
Input: vector reference, indexes to begin and end
*/
template<class T>
int Sort<T>::partition(std::vector<T>& A, int p, int q)
{
	int x = A[p];
	int i = p;
	for (int j = p + 1; j < q; j++)
	{
		if (A[j] <= x)
		{
			++i;
			swap(A[i], A[j]);
		}

	}
	std::swap(A[i], A[p]);
	return i;
}

/*Function: mergeSort (public)
Author:	James Riback
Description: performs merge sort algorithm on a vector
Input: vector reference
*/
template<class T>
void Sort<T>::mergeSort(std::vector<T>& a)
{
	//declare a temp array
	std::vector<T> tempArray(a.size());

	Timer t;
	t.startTimer(); //start timer
	this->mCount = 0;

	mergeSort(a, tempArray, 0, a.size() - 1);
	
	t.stopTimer();  //end timer after sort
	sortTime = t.getSeconds();
}

/*Function: mergeSort (private)
Author:	James Riback
Description: performs merge sort algorithm on a vector
Input: vector reference, a temp vector, and indexes to left and right of the list
*/
template<class T>
void Sort<T>::mergeSort(std::vector<T>& a, std::vector<T>& tempArray, int left, int right)
{
	if (left < right)
	{
		mCount++;
		int center = (left + right) / 2;
		mergeSort(a, tempArray, left, center);
		mergeSort(a, tempArray, center + 1, right);
		merge(a, tempArray, left, center + 1, right);
	}
}

/*Function: merge (private)
Author:	James Riback
Description: merge algorithm for use of mergeSort
Input: vector reference, vector temp, left pos, rightPos, rightEnd
*/
template<class T>
void Sort<T>::merge(std::vector<T>& a, std::vector<T>& tempArray, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tempPos = leftPos;
	int numElements = rightEnd - leftPos + 1;
	//Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] <= a[rightPos])
			tempArray[tempPos++] = std::move(a[leftPos++]);
		else 
			tempArray[tempPos++] = std::move(a[rightPos++]);
	}
	while (leftPos <= leftEnd) // Copy rest of first half
		tempArray[tempPos++] = std::move(a[leftPos++]);

	while (rightPos <= rightEnd) // Copy rest of right half
		tempArray[tempPos++] = std::move(a[rightPos++]);

	//Copy tempArray back!
	for (int i = 0; i < numElements; ++i, --rightEnd)
		a[rightEnd] = std::move(tempArray[rightEnd]);
}

//returns the sort time of the last algorithm used
template<class T>
double Sort<T>::getSortTime()
{
	return sortTime;
}
//returns the number of iterations of the last algorithm used
template<class T>
unsigned Sort<T>::getIterations()
{
	return mCount;
}
#endif