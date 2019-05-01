/**********
	Author: Jareth Dodson
	File Name: main.cpp
	Date created: 1-23-18
	Lab 2 Sorts
	Overview:
		The purpose of this program is too test 7 sorts.
		Brute Bubble, Flag Bubble, Insertion, Shell, Quick, Heap and Merge sort.
		The program will test all 7 algorithms with the c++ native array,
		my personal array class, and the vector stl class.

	Input:
		The only input is taken thru command line arguments.
		The input should only consist of any positive number.
		Input gets used for amount of items in each list

	Output:
		The output of this program conists the of the sorts name and the 
		data structure it is sorting with the time(in seconds) followed after that.
		Then every 1000th item is displayed to show that the list are in order.
		Ex.
			Bubble Sort c++ array: 0.999s
			2 1644 3424 5601 7840 
**********/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <crtdbg.h>
#include "Array.h"

using std::fstream;
using std::endl;
using std::swap;
//Brute Bubble
void BruteBubbleSort(int array[], int n);
void BruteBubbleSort1D(Array<int> & array, int n);
void BruteBubbleSortVect(vector<int> & varray, int n);

//Flag Bubble
void FlagBubbleSort(int array[], int n);
void FlagBubbleSort1D(Array<int> & array, int n);
void FlagBubbleSortVect(vector<int> & array, int n);

//Insertion sort
void InsertionSort(int array[], int n);
void InsertionSort1D(Array<int> & array, int n);
void InsertionSortVect(vector<int> & array, int n);

//Shell sort
void ShellSort(int array[], int n);
void ShellSort1D(Array<int> & array, int n);
void ShellSortVect(vector<int> & array, int n);

//Quick Sort
void QuickSort(int array[], int n);
void QuickSort(int array[], int first, int last);
void QuickSort1D(Array<int> & array, int n);
void QuickSort1D(Array<int> & array, int first, int last);
void QuickSortVect(vector<int> & array, int n);
void QuickSortVect(vector<int> & array, int first, int last);

//Heap Sort
void HeapSort(int array[], int n);
void HeapSort1D(Array<int> & array, int n);
void HeadSortVect(vector<int> & array, int n);

void MoveDown(int array[], int first, int last);
void MoveDown1D(Array<int> & array, int first, int last);
void MoveDownVect(vector<int> & array, int first, int last);

//Merge Sort
void MergeSort(int array[], int n);
void MergeSort(int array[], int left, int right);
void Merge(int array[], int left, int mid, int right);
void MergeSort1D(Array<int> & array, int n);
void MergeSort(Array<int> & array, int left, int right);
void Merge(Array<int> & array, int left, int mid, int right);
void MergeSortVect(vector<int> & array, int n);
void MergeSort(vector<int> & array, int left, int right);
void Merge(vector<int> & array, int left, int mid, int right);

const int MAX = 50;

int main(int argc, char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	fstream fs;
	fs.open("Sorts.txt", ios::out);

	srand(time(NULL));
	int n = atoi(argv[1]); //Number of items in each array
	int * m_array = new int[n]; //Create main array
	int * temp = new int[n]; // Create temp array to hold original values
	int count = 0; //Used for outputing every 1000th element of each array
	vector<int> v_array(n); //Create vector
	Array<int> a_array(n); //Instantiate Array object
	double duration; //Duration each 
	std::clock_t start; //Start for timer
	
	
	for (int i = 0; i < n; ++i)
	{
		m_array[i] = rand() % 10000 + 1;
		temp[i] = m_array[i];
	}

	//Copy array to vector
	for (int i = 0; i < n; ++i)
		v_array[i] = m_array[i];
	//Copy array to array object
	for (int i = 0; i < n; ++i)
		a_array[i] = m_array[i];

	//Brute Bubble Sort
	start = std::clock();
	BruteBubbleSort(m_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Bubble Sort c++ array: " << duration << 's' << endl;

	//Display every 1000th item in the array
	while (count < n)
	{
		fs << m_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	BruteBubbleSortVect(v_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Bubble Sort array class: " << duration << 's' << endl;
	//Display every 1000th item in the array
	while (count < n)
	{
		fs << v_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	BruteBubbleSort1D(a_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Bubble Sort Vector: " << duration << 's' << endl;
	//Display every 1000th item in the array
	while (count < n)
	{
		fs << a_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	//Reset Array
	for (int i = 0; i < n; ++i)
	{
		m_array[i] = temp[i];
		a_array[i] = temp[i];
		v_array[i] = temp[i];
	}

	//Flag Bubble
	start = std::clock();
	FlagBubbleSort(m_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Flag Bubble Sort c++ array: " << duration << 's' << endl;
	while (count < n)
	{
		fs << m_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;
	
	start = std::clock();
	FlagBubbleSort1D(a_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Flag Bubble Sort array class: " << duration << 's' << endl;
	while (count < n)
	{
		fs << a_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	FlagBubbleSortVect(v_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Flag Bubble Sort Vector: " << duration << 's' << endl;
	while (count < n)
	{
		fs << v_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	//Reset Array
	for (int i = 0; i < n; ++i)
	{
		m_array[i] = temp[i];
		a_array[i] = temp[i];
		v_array[i] = temp[i];
	}

	//Insertion Sort
	start = std::clock();
	InsertionSort(m_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Insertion Sort c++ array: " << duration << 's' << endl;
	while (count < n)
	{
		fs << m_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	InsertionSort1D(a_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Insertion array class: " << duration << 's' << endl;
	while (count < n)
	{
		fs << a_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	InsertionSortVect(v_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Insertion Sort Vector: " << duration << 's' << endl;
	while (count < n)
	{
		fs << v_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	for (int i = 0; i < n; ++i)
	{
		m_array[i] = temp[i];
		a_array[i] = temp[i];
		v_array[i] = temp[i];
	}

	//Shell Sort
	start = std::clock();
	ShellSort(m_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Shell Sort c++ array: " << duration << 's' << endl;
	while (count < n)
	{
		fs << m_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	ShellSort1D(a_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Shell Sort array class: " << duration << 's' << endl;
	while (count < n)
	{
		fs << a_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	ShellSortVect(v_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Shell Sort Vector: " << duration << 's' << endl;
	while (count < n)
	{
		fs << v_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	for (int i = 0; i < n; ++i)
	{
		m_array[i] = temp[i];
		a_array[i] = temp[i];
		v_array[i] = temp[i];
	}

	//Quick Sort
	start = std::clock();
	QuickSort(m_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Quick Sort c++ array: " << duration << 's' << endl;
	while (count < n)
	{
		fs << m_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	QuickSort1D(a_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Quick Sort array class: " << duration << 's' << endl;
	while (count < n)
	{
		fs << a_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	QuickSortVect(v_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Quick Sort Vector: " << duration << 's' << endl;
	while (count < n)
	{
		fs << v_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	//Reset Arrays
	for (int i = 0; i < n; ++i)
	{
		m_array[i] = temp[i];
		a_array[i] = temp[i];
		v_array[i] = temp[i];
	}

	//Heap Sort
	start = std::clock();
	HeapSort(m_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Heap Sort c++ array: " << duration << 's' << endl;
	while (count < n)
	{
		fs << m_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	HeapSort1D(a_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Heap Sort array class: " << duration << 's' << endl;
	while (count < n)
	{
		fs << a_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	HeadSortVect(v_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Heap Sort Vector: " << duration << 's' << endl;
	while (count < n)
	{
		fs << v_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;
	//Reset Arrays
	for (int i = 0; i < n; ++i)
	{
		m_array[i] = temp[i];
		a_array[i] = temp[i];
		v_array[i] = temp[i];
	}

	//Merge Sort
	start = std::clock();
	MergeSort(m_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Merge Sort c++ array: " << duration << 's' << endl;
	while (count < n)
	{
		fs << m_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	MergeSort1D(a_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Merge Sort array class: " << duration << 's' << endl;
	while (count < n)
	{
		fs << a_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	start = std::clock();
	MergeSortVect(v_array, n);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fs << "Merge Sort Vector: " << duration << 's' << endl;
	while (count < n)
	{
		fs << v_array[count] << ' ';
		count += 1000;
	}
	fs << endl;
	count = 0;

	fs.close();
	delete[] temp;
	delete[] m_array;
}
/*
	Purpose: This function will sort the c++ native array
		using a brute bubble force algorithm

	Precondition:
		array[] - An integer array with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void BruteBubbleSort(int array[], int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int x = n - 1; x > i; --x)
			if (array[x] < array[x - 1])
			{
				swap(array[x], array[x - 1]);
			}
}
/*
	Purpose: This function will sort the Array class object
		using a brute bubble force algorithm

	Precondition:
		array - An integer array object with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void BruteBubbleSort1D(Array<int> & array, int n)
{
	for (int i = 0; i < n -1; ++i)
		for (int x = n - 1; x > i; --x)
			if (array[x] < array[x - 1])
			{
				swap(array[x], array[x - 1]);
			}
}
/*
	Purpose: This function will sort the stl vector class
		using a brute bubble force algorithm

	Precondition:
		varray - An integer vector with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void BruteBubbleSortVect(vector<int> & varray, int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int x = n - 1; x > i; --x)
			if (varray[x] < varray[x - 1])
			{
				swap(varray[x], varray[x - 1]);
			}
}
/*
	Purpose: This function will sort the c++ native array
		using a flag bubble force algorithm

	Precondition:
		array[] - An integer array with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void FlagBubbleSort(int array[], int n)
{
	bool sorted = true;
	for (int i = 0; i < n && sorted; ++i)
	{
		for(int x = n - 1, sorted = false; x > i; --x)
			if (array[x] < array[x - 1])
			{
				swap(array[x], array[x - 1]);
				sorted = true;
			}
	}
}
/*
	Purpose: This function will sort the array class object
		using a flag bubble force algorithm

	Precondition:
		array - An integer array object with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void FlagBubbleSort1D(Array<int>& array, int n)
{
	bool sorted = true;
	for (int i = 0; i < n && sorted; ++i)
	{
		for (int x = n - 1, sorted = false; x > i; --x)
			if (array[x] < array[x - 1])
			{
				swap(array[x], array[x - 1]);
				sorted = true;
			}
	}
}
/*
	Purpose: This function will sort the stl vector class object
		using a flag bubble force algorithm

	Precondition:
		array - An integer vector with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void FlagBubbleSortVect(vector<int>& array, int n)
{
	bool sorted = true;
	for (int i = 0; i < n && sorted; ++i)
	{
		for (int x = n - 1, sorted = false; x > i; --x)
			if (array[x] < array[x - 1])
			{
				swap(array[x], array[x - 1]);
				sorted = true;
			}
	}
}

/*
	Purpose: This function will sort the c++ native array
		using an insertion sort

	Precondition:
		array - an integer array with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void InsertionSort(int array[], int n)
{
	int x = 0;
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		temp = array[i];
		for (x = i; x > 0 && temp < array[x - 1]; --x)
		{
			array[x] = array[x - 1];
		}
		array[x] = temp;
	}
}
/*
	Purpose: This function will sort the array class object
		using an insertion sort

	Precondition:
		array - an integer array object with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void InsertionSort1D(Array<int>& array, int n)
{
	int x = 0;
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		temp = array[i];
		for (x = i; x > 0 && temp < array[x - 1]; --x)
		{
			array[x] = array[x - 1];
		}
		array[x] = temp;
	}
}
/*
	Purpose: This function will sort the stl vector object
		using an insertion sort

	Precondition:
		array - an integer vector with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void InsertionSortVect(vector<int>& array, int n)
{
	int x = 0;
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		temp = array[i];
		for (x = i; x > 0 && temp < array[x - 1]; --x)
		{
			array[x] = array[x - 1];
		}
		array[x] = temp;
	}
}
/*
	Purpose: This function will sort the c++ native array
		using a shell sort

	Precondition:
		array - an integer array with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void ShellSort(int array[], int n)
{
	int i, x, h, hCnt;
	int increments[MAX], k;
	for (h = 1, i = 0; h < n; ++i)
	{
		increments[i] = h; 
		h = 3 * h + 1;
	}
	for (i--; i >= 0; i--)
	{
		h = increments[i];
		for (hCnt = h; hCnt < 2 * h; ++hCnt)
		{
			for (x = hCnt; x < n;)
			{
				int temp = array[x];
				k = x; 
				while (k - h >= 0 && temp < array[k - h])
				{
					array[k] = array[k - h];
					k -= h;
				}
				array[k] = temp;
				x += h;
			}
		}
	}
}
/*
	Purpose: This function will sort the array class object
		using a shell sort

	Precondition:
		array - an integer arry object with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void ShellSort1D(Array<int>& array, int n)
{
	int i, x, h, hCnt;
	int increments[MAX], k;
	for (h = 1, i = 0; h < n; ++i)
	{
		increments[i] = h;
		h = 3 * h + 1;
	}
	for (i--; i >= 0; i--)
	{
		h = increments[i];
		for (hCnt = h; hCnt < 2 * h; ++hCnt)
		{
			for (x = hCnt; x < n;)
			{
				int temp = array[x];
				k = x;
				while (k - h >= 0 && temp < array[k - h])
				{
					array[k] = array[k - h];
					k -= h;
				}
				array[k] = temp;
				x += h;
			}
		}
	}
}
/*
	Purpose: This function will sort the stl vector object
		using a shell sort

	Precondition:
		array - an integer vector with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void ShellSortVect(vector<int>& array, int n)
{
	int i, x, h, hCnt;
	int increments[MAX], k;
	for (h = 1, i = 0; h < n; ++i)
	{
		increments[i] = h;
		h = 3 * h + 1;
	}
	for (i--; i >= 0; i--)
	{
		h = increments[i];
		for (hCnt = h; hCnt < 2 * h; ++hCnt)
		{
			for (x = hCnt; x < n;)
			{
				int temp = array[x];
				k = x;
				while (k - h >= 0 && temp < array[k - h])
				{
					array[k] = array[k - h];
					k -= h;
				}
				array[k] = temp;
				x += h;
			}
		}
	}
}
/*
	Purpose: This function will sort the c++ native array
		using a quick sort

	Precondition:
		array - an integer array with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void QuickSort(int array[], int n)
{
	int maxx = 0;
	if (n >= 2)
	{
		for (int i = 1, maxx = 0; i < n; ++i)
		{
			if (array[maxx] < array[i])
				maxx = i;
		}
		swap(array[n - 1], array[maxx]);
		QuickSort(array, 0, n - 2);
	}
}
/*
	Purpose: This function will put pivot in it's correct position
		while everything to the left of pivot is on the correct side and 
		everthing to the right of pivot is on the correct side

	Precondition:
		array - an integer array
		first - first element in array segment that it is currently sorting 
		last - last element in array segment that is currently being sorted
	Postcondition:
		array will be modified
*/
void QuickSort(int array[], int first, int last)
{
	int small = first + 1;
	int large = last;
	
	int pivot = array[first];
	while (small <= large)
	{
		while (array[small] < pivot)
			small++;
		while (array[large] > pivot)
			large--;
		if (small < large)
			swap(array[small++], array[large--]);
		else
			small++;
	}
	swap(array[large], array[first]);
	if (first < large - 1)
		QuickSort(array, first, large - 1);
	if (last > large + 1)
		QuickSort(array, large + 1, last);
}
/*
	Purpose: This function will sort the array class object
		using a quick sort

	Precondition:
		array - an integer array class object with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void QuickSort1D(Array<int>& array, int n)
{
	int maxx = 0;
	if (n >= 2)
	{
		for (int i = 1, maxx = 0; i < n; ++i)
		{
			if (array[maxx] < array[i])
				maxx = i;
		}
		swap(array[n - 1], array[maxx]);
		QuickSort1D(array, 0, n - 2);
	}
}
/*
	Purpose: This function will put pivot in it's correct position
		while everything to the left of pivot is on the correct side and
		everthing to the right of pivot is on the correct side

	Precondition:
		array - an array class object
		first - first element in array segment that it is currently sorting
		last - last element in array segment that is currently being sorted
	Postcondition:
		array will be modified
*/
void QuickSort1D(Array<int>& array, int first, int last)
{
	int small = first + 1;
	int large = last;
	
	int pivot = array[first];
	while (small <= large)
	{
		while (array[small] < pivot)
			small++;
		while (array[large] > pivot)
			large--;
		if (small < large)
		{
			swap(array[small], array[large]);
			small++;
			large--;
		}
		else
			small++;
	}
	swap(array[large], array[first]);
	if (first < large - 1)
		QuickSort1D(array, first, large - 1);
	if (last > large + 1)
		QuickSort1D(array, large + 1, last);

}
/*
	Purpose: This function will sort the stl vector object
		using a quick sort

	Precondition:
		array - an integer vector with size n
		n - declared size of the array
			Must be a non-negative number
	Postcondition:
		array will be sorted
*/
void QuickSortVect(vector<int>& array, int n)
{
	int maxx = 0;
	if (n >= 2)
	{
		for (int i = 1, maxx = 0; i < n; ++i)
		{
			if (array[maxx] < array[i])
				maxx = i;
		}
		swap(array[n - 1], array[maxx]);
		QuickSortVect(array, 0, n - 2);
	}
}
/*
	Purpose: This function will put pivot in it's correct position
		while everything to the left of pivot is on the correct side and
		everthing to the right of pivot is on the correct side

	Precondition:
		array - an integer vector
		first - first element in array segment that it is currently sorting
		last - last element in array segment that is currently being sorted
	Postcondition:
		array will be modified
*/
void QuickSortVect(vector<int>& array, int first, int last)
{
	int small = first + 1;
	int large = last;
	
	int pivot = array[first];
	while (small <= large)
	{
		while (array[small] < pivot)
			small++;
		while (array[large] > pivot)
			large--;
		if (small < large)
			swap(array[small++], array[large--]);
		else
			small++;
	}
	swap(array[large], array[first]);
	if (first < large - 1)
		QuickSortVect(array, first, large - 1);
	if (last > large + 1)
		QuickSortVect(array, large + 1, last);

}
/*
	Purpose: Build the heap

	Precondition:
		array - An integer array
		first - first point in array to start building off of
		last - last point in array
	Postcondition:
		array will be modified
*/
void MoveDown(int array[], int first, int last)
{
	int largest = first * 2 + 1;
	while (largest <= last)
	{
		if (largest < last && array[largest] < array[largest + 1])
			largest++;
		if (array[first] < array[largest])
		{
			swap(array[first], array[largest]);
			first = largest;
			largest = 2 * first + 1;
		}
		else
		{
			largest = last + 1;
		}
	}
}
/*
	Purpose: Build the heap

	Precondition:
		array - An integer array class object
		first - first point in array to start building off of
		last - last point in array
	Postcondition:
		array will be modified
*/
void MoveDown1D(Array<int> & array, int first, int last)
{
	int largest = first * 2 + 1;
	while (largest <= last)
	{
		if (largest < last && array[largest] < array[largest + 1])
			largest++;
		if (array[first] < array[largest])
		{
			swap(array[first], array[largest]);
			first = largest;
			largest = 2 * first + 1;
		}
		else
		{
			largest = last + 1;
		}
	}
}
/*
	Purpose: Build the heap

	Precondition:
		array - An integer vector
		first - first point in array to start building off of
		last - last point in array
	Postcondition:
		array will be modified
*/
void MoveDownVect(vector<int> & array, int first, int last)
{
	int largest = first * 2 + 1;
	while (largest <= last)
	{
		if (largest < last && array[largest] < array[largest + 1])
			largest++;
		if (array[first] < array[largest])
		{
			swap(array[first], array[largest]);
			first = largest;
			largest = 2 * first + 1;
		}
		else
		{
			largest = last + 1;
		}
	}
}
/*
	Purpose: This function will sort the c++ native array
		using the heap sort

	Precondition:
		array[] - An integer array with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondtion:
		array will be sorted
*/
void HeapSort(int array[], int n)
{
	int i = (n / 2) - 1;
	for (; i >= 0; --i)
	{
		MoveDown(array, i, n - 1);
	}
	for (int x = n - 1; x >= 0; --x)
	{
		swap(array[0], array[x]);
		MoveDown(array, 0, x - 1);
	}
}
/*
	Purpose: This function will sort the array class object
		using the heap sort

	Precondition:
		array[] - An integer array object with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondtion:
		array will be sorted
*/
void HeapSort1D(Array<int> & array, int n)
{
	int i = (n / 2) - 1;
	for (; i >= 0; --i)
	{
		MoveDown1D(array, i, n - 1);
	}
	for (int x = n - 1; x >= 0; --x)
	{
		swap(array[0], array[x]);
		MoveDown1D(array, 0, x - 1);
	}
}
/*
	Purpose: This function will sort the stl vector object
		using the heap sort

	Precondition:
		array[] - An integer vector with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondtion:
		array will be sorted
*/
void HeadSortVect(vector<int> & array, int n)
{
	int i = (n / 2) - 1;
	for (; i >= 0; --i)
	{
		MoveDownVect(array, i, n - 1);
	}
	for (int x = n - 1; x >= 0; --x)
	{
		swap(array[0], array[x]);
		MoveDownVect(array, 0, x - 1);
	}
}
/*
	Purpose: This function will sort the c++ native array
		using the merge sort

	Precondition:
		array[] - An integer array with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondtion:
		array will be sorted
*/
void MergeSort(int array[], int n)
{
	MergeSort(array, 0, n - 1);
}
/*
	Purpose: This function will take an array and split it into 2
		seperate array and sort those. Then in the end it will merge both
		of the sorted array together
	
	Precondition:
		array[] - An integer array
		left - The left side of the array segment to sort
		right - The right side of the array segment to sort
	Postcondition:
		Array will be modified
*/
void MergeSort(int array[], int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);
		Merge(array, left, mid, right);
	}
}
/*
	Purpose: This function will take an array and merge the array segments together

	Preconditon:
		array - An integer array 
		left - The left side of the array segment to merge
		right - The right side of the array segment to merge
		mid - The middle of the segment of the array
	Postcondition:
		array will be modified
*/
void Merge(int array[], int left, int mid, int right)
{
	int * temp = new int[right - left + 1];
	int num_elements = right - left + 1;
	//Left
	int leftside = left;
	//Right mid
	int right_mid = mid + 1;
	//temporary array position
	int temp_pos = 0;
	while (leftside <= mid && right_mid <= right) 
	{
		if (array[leftside] <= array[right_mid])
		{
			temp[temp_pos] = array[leftside];
			++temp_pos;
			++leftside;
		}
		else
		{
			temp[temp_pos] = array[right_mid];
			temp_pos++;
			right_mid++;
		}
	}
	while (leftside <= mid)
	{
		temp[temp_pos] = array[leftside];
		++temp_pos;
		++leftside;
	}
	while (right_mid <= right)
	{
		temp[temp_pos] = array[right_mid];
		++temp_pos;
		++right_mid;
	}
	for (temp_pos = 0, leftside = left; leftside <= right; ++leftside, ++temp_pos)
		array[leftside] = temp[temp_pos];

	delete[] temp;
}
/*
	Purpose: This function will sort the array class object
		using the merge sort

	Precondition:
		array[] - An integer array class object with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondtion:
		array will be sorted
*/
void MergeSort1D(Array<int> & array, int n)
{
	MergeSort(array, 0, n - 1);
}
/*
	Purpose: This function will take an array and split it into 2
		seperate array and sort those. Then in the end it will merge both
		of the sorted array together

	Precondition:
		array - An array class object
		left - The left side of the array segment to sort
		right - The right side of the array segment to sort
	Postcondition:
		Array will be modified
*/
void MergeSort(Array<int> & array, int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);
		Merge(array, left, mid, right);
	}
}
/*
	Purpose: This function will take an array and merge the array segments together

	Preconditon:
		array - An array class object
		left - The left side of the array segment to merge
		right - The right side of the array segment to merge 
		mid - The middle of the segment of the array
	Postcondition:
		array will be modified
*/
void Merge(Array<int> & array, int left, int mid, int right)
{
	Array<int> temp(right - left + 1);
	int num_elements = right - left + 1;
	//Left
	int leftside = left;
	//Right mid
	int right_mid = mid + 1;
	//temporary array position
	int temp_pos = 0;
	while (leftside <= mid && right_mid <= right)
	{
		if (array[leftside] <= array[right_mid])
		{
			temp[temp_pos] = array[leftside];
			++temp_pos;
			++leftside;
		}
		else
		{
			temp[temp_pos] = array[right_mid];
			temp_pos++;
			right_mid++;
		}
	}
	while (leftside <= mid)
	{
		temp[temp_pos] = array[leftside];
		++temp_pos;
		++leftside;
	}
	while (right_mid <= right)
	{
		temp[temp_pos] = array[right_mid];
		++temp_pos;
		++right_mid;
	}
	for (temp_pos = 0, leftside = left; leftside <= right; ++leftside, ++temp_pos)
		array[leftside] = temp[temp_pos];
}
/*
	Purpose: This function will sort the stl vector object
		using the merge sort

	Precondition:
		array[] - An integer vector with size n
		n - Declared size of the array
			Must be a non-negative number
	Postcondtion:
		array will be sorted
*/
void MergeSortVect(vector<int >& array, int n)
{
	MergeSort(array, 0, n - 1);
}
/*
	Purpose: This function will take an array and split it into 2
		seperate array and sort those. Then in the end it will merge both
		of the sorted array together

	Precondition:
		array - An integer vector
		left - The left side of the array segment to sort
		right - The right side of the array segment to sort
	Postcondition:
		Array will be modified
*/
void MergeSort(vector<int> & array, int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);
		Merge(array, left, mid, right);
	}
}
/*
	Purpose: This function will take an array and merge the array segments together

	Preconditon:
		array - An integer vector
		left - The left side of the array segment to merge
		right - The right side of the array segment to merge
		mid - The middle of the segment of the array
	Postcondition:
		array will be modified
*/
void Merge(vector<int> & array, int left, int mid, int right)
{
	int * temp = new int[right - left + 1];
	int num_elements = right - left + 1;
	//Left
	int leftside = left;
	//Right mid
	int right_mid = mid + 1;
	//temporary array position
	int temp_pos = 0;
	while (leftside <= mid && right_mid <= right)
	{
		if (array[leftside] <= array[right_mid])
		{
			temp[temp_pos] = array[leftside];
			++temp_pos;
			++leftside;
		}
		else
		{
			temp[temp_pos] = array[right_mid];
			temp_pos++;
			right_mid++;
		}
	}
	while (leftside <= mid)
	{
		temp[temp_pos] = array[leftside];
		++temp_pos;
		++leftside;
	}
	while (right_mid <= right)
	{
		temp[temp_pos] = array[right_mid];
		++temp_pos;
		++right_mid;
	}
	for (temp_pos = 0, leftside = left; leftside <= right; ++leftside, ++temp_pos)
		array[leftside] = temp[temp_pos];

	delete[] temp;
}