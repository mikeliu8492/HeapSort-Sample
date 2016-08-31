#include <assert.h>

template<typename E>
class Heap
{
private:
	E * Items;
	int number_elements;
	int max_elements;
public:
	Heap(int yourSize)
	{
		// Create heap of given size

		number_elements = 0;
		max_elements = yourSize;
		Items = new E[max_elements];
	}

	~Heap()
	{
		delete[] Items;
	}

	void removeHelp(int root, int last)
	{
		int minKid;
		int rightKid;
		int leftKid;
		E temp;

		leftKid = root * 2 + 1;
		rightKid = root * 2 + 2;

		if (leftKid <= last)
		{
			if (leftKid == last)          // If this root has no right child then 
			{
				minKid = leftKid;     //     the left must hold max key
			}
			else
			{     // Get the one lowest in the tree (highest index in the array)
				if (Items[leftKid] > Items[rightKid])
					minKid = rightKid;
				else
					minKid = leftKid;
			}


			if (Items[root] > Items[minKid])
			{
				// Swap these two elements
				temp = Items[root];
				Items[root] = Items[minKid];
				Items[minKid] = temp;
				removeHelp(minKid, last);
			}

			// Move down
		}

	}
		void insertHelp(int root, int last)
		{
			int parent;
			E temp;

			if (last > root)
			{
				parent = (last - 1) / 2;

				if (Items[parent] > Items[last])
				{
					// Swap these two elements
					temp = Items[parent];
					Items[parent] = Items[last];
					Items[last] = temp;
					insertHelp(root, parent);
				}

			}
		}

		bool enqueue(E * curr_item)
		{
			if (number_elements < max_elements)
			{
			
				{
					Items[number_elements] = *curr_item; // Copy item into array
					insertHelp(0, number_elements);
					number_elements++;
					return true;
				}
				
			}
			return false;
		}

		E * dequeue()
		{
			if (number_elements > 0)
			{
				E * temp = new E(Items[0]);
				--number_elements;
				// Copy last item into root
				Items[0] = Items[number_elements];
				// Reheap the tree
				removeHelp(0, number_elements - 1);
				return temp;
			}
			
		}

		int getNumberElements()
		{
			return number_elements;
		}

		void printHeapItems()
		{
			for (int i = 0; i < number_elements; i++)
				cout << "Heap element " << i << "is valued @:  " << Items[i] << endl;
		}


};