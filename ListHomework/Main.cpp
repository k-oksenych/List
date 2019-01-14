#include <iostream>

#include "List.h"

using namespace std;

int main()
{
	List<int> list;
	list.AddLast(3);
	list.AddLast(7);
	list.AddLast(1);
	list.AddLast(4);
	list.AddLast(7);
	list.AddLast(5);

	list.Print();

	List<int> list2(list);
	list2.Print();

	list.RemoveLast(7);
	list.Print();
}