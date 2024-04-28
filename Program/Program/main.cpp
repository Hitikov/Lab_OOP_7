#include "List.h"
#include "Pair.h"
#include <iostream>
using namespace std;
 
int main()
{
	int count, index;
	double in_value;
	List<double> list1;
	ListIterator <double> iter;

	cout << "Enter number of elements: ";
	cin >> count;
	cout << endl;

	cout << "Enter elements of list:" << endl;
	for (int i = 0; i < count; ++i)
	{
		cin >> in_value;
		list1.PushBack(in_value);
	}
	cout << endl;
	iter = list1.first();
	
	cout << "Enter index of element in list to call: ";
	cin >> index;
	cout << list1[index] << endl;
	cout << endl;

	cout << "Enter number of elements to move for from first: ";
	cin >> index;
	iter + index;
	cout << *iter << endl;
	cout << endl;


	List<Pair> list2;
	Pair new_in_value;
	
	cout << "Enter number of elements of new list: ";
	cin >> count;
	cout << endl;

	cout << "Enter elements of list:" << endl;
	for (int i = 0; i < count; ++i)
	{
		cin >> new_in_value;
		list2.PushBack(new_in_value);
	}

	cout << "Enter index of element in list to call: ";
	cin >> index;
	cout << list2[index] << endl;
	cout << endl;

}