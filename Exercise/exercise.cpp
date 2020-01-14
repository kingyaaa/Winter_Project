#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#define ARRAY_SIZE 20

#define SELECTSORT_TEST
//#define BUBBLESORT_TEST
//#define INSERTSORT_TEST
//#define MERGESORT_TEST
//#define QUICKSORT_TEST

void print(int *MyArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << MyArray[i] << "\t";
	}
	cout << endl;
}

void Init(int *MyArray, int size) {
	srand((int)time(0));  
	for (int i = 0; i < size; i++)
	{
		MyArray[i] = rand() % 100;
	}
}


void SelectSort(int *MyArray, int size) {
	// TODO 
	int min;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (MyArray[min] > MyArray[j])
				min = j;
		}
		if (min != i) {
			int temp = MyArray[i];
			MyArray[i] = MyArray[min];
			MyArray[min] = temp;
		}
	}
}

void BubbleSort(int *MyArray, int size) {
	// TODO
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (MyArray[j] < MyArray[j + 1]) {
				int temp = MyArray[j];
				MyArray[j] = MyArray[j + 1];
				MyArray[j + 1] = temp;
			}
		}
	}
}

void InsertSort(int *MyArray, int size) {
	// TODO 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (MyArray[i] < MyArray[j]) {
				int temp = MyArray[i], k;
				for (k = i; k > j; k--) {
					MyArray[k] = MyArray[k-1];
				}
				MyArray[k] = temp;
			}
		}
	}
}

void MergeSort(int *MyArray, int size) {
	// U do not have to do this
	// If U want to learn more, U can finish it 
	// If U find it difficult, U can contact me via QQ 
}

void QuickSort(int *MyArray, int size) {
	// U do not have to do this 
	// If U want to learn more, U can finish it 
	// If U find it difficult, U can contact me via QQ 
}

int main()
{
	int *MyArray = new int[ARRAY_SIZE];

	// Init
	Init(MyArray, ARRAY_SIZE);
	cout << "Before Sort:"; print(MyArray, ARRAY_SIZE);

#ifdef SELECTSORT_TEST
	SelectSort(MyArray, ARRAY_SIZE);
	cout << "After SelectSort:"; print(MyArray, ARRAY_SIZE);
#endif // SELECTSORT_TEST

#ifdef BUBBLESORT_TEST
	BubbleSort(MyArray, ARRAY_SIZE);
	cout << "After BubbleSort:"; print(MyArray, ARRAY_SIZE);
#endif // BUBBLESORT_TEST

#ifdef INSERTSORT_TEST
	InsertSort(MyArray, ARRAY_SIZE);
	cout << "After InsertSort:"; print(MyArray, ARRAY_SIZE);
#endif // INSERTSORT_TEST

#ifdef MERGESORT_TEST
	MergeSort(MyArray, ARRAY_SIZE);
	cout << "After MergeSort:"; print(MyArray, ARRAY_SIZE);
#endif // MERGESORT_TEST

#ifdef QUICKSORT_TEST
	QuickSort(MyArray, ARRAY_SIZE);
	cout << "After QuickSort:"; print(MyArray, ARRAY_SIZE);
#endif // QUICKESORT_TEST
	delete []MyArray;
}i

// Q1: What is the time complexity of your sorting algorithm？ 
// It would be better if U can write down the process how you calculate
//BubbleSort:总的比较次数为 n+n-1+n-2+...+1=n*(n+1)/2,时间复杂度为O(n^2);
//SelectSort:总的比较次数为 n+n-1+n-2+...+1=n*(n+1)/2,时间复杂度为O(n^2);
//InsertSort:最好情况：n-1,时间复杂度为O(n);最坏情况：1+2+3+...+n-1=n*(n-1)/2，时间复杂度为O(n^2);vs

// Q2: What is the loop invariant of your sorting algorithm?
// I kown U must Know!! 
//BubbleSort:MyArray[size-1-i],...MyArray[size-1]是有序的；
//SelectSort:MyArray[0],...MyArray[i]是有序的；
//InsertSort:MyArray[0],...MyArray[i]是有序的；

// Q3: What difficulties did you encounter when writing the code?
// I will read this carefully!
//插入排序的最坏情况的计算公式，是否要考虑元素移位时的运算次数？
//不会快排和归并排列；
