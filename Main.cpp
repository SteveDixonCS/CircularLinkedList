#include <iostream>
#include "DataType.h"
#include "CircularLinkedList.h"


using namespace std;

int main() {

	CircularLinkedList CLL;
	DataType DT,DT2,DT3,DT4,DT5;

	DT.initialize(5);
	CLL.insertItem(DT);
	CLL.print();

	CLL.deleteItem(DT);
	CLL.print();


	DT2.initialize(60);
	CLL.insertItem(DT2);
	CLL.print();

	DT3.initialize(20);
	CLL.insertItem(DT3);
	CLL.print();

	DT4.initialize(85);
	CLL.insertItem(DT4);
	CLL.print();

	DT5.initialize(3);
	CLL.insertItem(DT5);
	CLL.print();

	CLL.deleteItem(DT4);
	CLL.print();

	CLL.deleteItem(DT3);
	CLL.print();

}
