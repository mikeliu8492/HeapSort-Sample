#include <iostream>
#include <iomanip>

#include "Heap.h"


using namespace std;

//function for heapSort
void heapSort(int * Array, int arraySize)
{
	Heap<int> yourHeap(arraySize);//make heap same size as your Array
	
	for (int i = 0; i < arraySize; i++)//enque each element onto heap
	{
		yourHeap.enqueue(&Array[i]);
	}

	for (int i = 0; i < arraySize; i++)//then deque back onto you array based on order (this is min-heap)
	{
		Array[i] = *yourHeap.dequeue();
	}

}

int main()
{
	int yourArray[36];

	yourArray[0] = 4;
	yourArray[1] = 17;
	yourArray[2] = 79;
	yourArray[3] = 52;
	yourArray[4] = 56;
	yourArray[5] = 19;
	yourArray[6] = 21;
	yourArray[7] = 22;
	yourArray[8] = 3;

	yourArray[9] = 12;
	yourArray[10] = 30;
	yourArray[11] = 33;
	yourArray[12] = 81;
	yourArray[13] = 99;
	yourArray[14] = 85;
	yourArray[15] = 28;
	yourArray[16] = 24;
	yourArray[17] = 25;

	yourArray[18] = 24;
	yourArray[19] = 26;
	yourArray[20] = 27;
	yourArray[21] = 20;
	yourArray[22] = 44;
	yourArray[23] = 32;
	yourArray[24] = 35;
	yourArray[25] = 24;
	yourArray[26] = 39;

	yourArray[27] = 43;
	yourArray[28] = 41;
	yourArray[29] = 46;
	yourArray[30] = 56;
	yourArray[31] = 62;
	yourArray[32] = 22;
	yourArray[33] = 20;
	yourArray[34] = 69;
	yourArray[35] = 18;

	cout << "Original Array:  " << endl << endl;
	for (int i = 0; i < 36; i++)
	{
		cout << setw(5) << right << yourArray[i];
	}

	cout << endl << endl;

	heapSort(yourArray, 36);

	cout << "New Ordered Array:  " << endl << endl;
	for (int i = 0; i < 36; i++)
	{
		cout << setw(5) << right << yourArray[i];
	}

	cout << endl << endl;

	system("PAUSE");
}