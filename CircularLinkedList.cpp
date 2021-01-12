#include "CircularLinkedList.h"
#include <cstddef>
#include <iostream>

CircularLinkedList::CircularLinkedList() {
	length = 0;
	head = NULL;
	std::cout<<"list has been initialized"<<std::endl;
}

CircularLinkedList::~CircularLinkedList()
{
	delete head;
}

void CircularLinkedList::insertItem(DataType &item)
{
	//CIRCULAR LINKED LIST IMPLEMENTATION

	NodeType* newNode;
	NodeType* predLoc;
	NodeType* location;
	bool moreToSearch;
	bool isEqual= false;

	newNode = new NodeType;//create new node
	newNode->data = item;//assign data

	//std::cout<<"in insert item method"<<std::endl;

	if(length == 0)//if empty list
	{
		newNode->next = newNode;//set next to itself
		head = newNode;
		length++;
	}
	else if(head->next == head)//if one variable in list
	{
		//std::cout<<"adding second variable"<<std::endl;

		switch(item.compareTo(head->data))
				{
					case GREATER:
						newNode->next = head;
						head->next = newNode;
						head = newNode;
						length++;
						break;
					case LESS:
						newNode->next = head;
						head->next = newNode;
						length++;
						break;
					case EQUAL:
						break;
				}
	}
	else//if two or more variables in list
	{
	location = head-> next;
	predLoc = head;

	moreToSearch = location != head;

		while(moreToSearch)
		{
		//std::cout<<"finding location"<<std::endl;

			switch(item.compareTo(location->data))
			{
			case GREATER:
				predLoc = location;
				location = location->next;
				moreToSearch = (location != head->next);
				break;
			case LESS:
				moreToSearch = false;
				break;
			case EQUAL:
				moreToSearch = false;
				isEqual = true;
				break;
			}
		}

		if(!isEqual)
		{
			//std::cout<<"is equal if statement"<<std::endl;

			if(location == head->next)//insert first or last position
				{
					if(newNode->data.compareTo(head->data)==GREATER)
					{
						newNode->next = location;
						predLoc->next = newNode;
						head = newNode;
						length++;
					}
					else
					{
						newNode->next = location;
						predLoc->next = newNode;
						head->next = newNode;
						length++;
					}
				}
			else//insert other positions
				{
					newNode->next = location;
					predLoc->next = newNode;
					length++;
				}
		}//is equal
		else
		{
			std::cout<<"item is already in list"<<std::endl;
		}
	}
}
void CircularLinkedList::deleteItem(DataType &item)
{
	NodeType* predLoc;
	NodeType* location;
	bool moreToSearch;
	bool isEqual= false;

	if(lengthIs() != 0)//list is not empty
	{
		if(lengthIs() == 1 && item.compareTo(head->data)== EQUAL)//deleting only element
		{
			delete head;
			head = NULL;
			length--;
		}
		else//list contains 2 or more elements
		{
			location = head-> next;
			predLoc = head;
			moreToSearch = location != head;

			while(moreToSearch)
			{
				switch(item.compareTo(location->data))
				{
					case GREATER:
					predLoc = location;
					location = location->next;
					moreToSearch = (location != head->next);
					break;
					case LESS:
					moreToSearch = false;
					break;
					case EQUAL:
					moreToSearch = false;
					isEqual = true;
					break;
				}//switch
			}//while

			if(isEqual)//element found
			{
				if(location == head)//delete largest element
				{
					predLoc->next = location->next;
					head = predLoc;
				}//if
				else//general case
				{
					predLoc->next = location->next;
				}//else
			length--;
			}// if (isEqual)
		}//else two or more elements
	}//if list is not empty
}//delete item

int CircularLinkedList::lengthIs() const
{
	return length;
}//lengthIs

void CircularLinkedList::print()
{
	NodeType* printPointer = head;
	int i = 0;

	if(printPointer == NULL)
	{
		std::cout<<"LIST IS EMPTY";
	}
	else
	{
		printPointer = head->next;

		while(printPointer != NULL && i < lengthIs())
		{
			std::cout<<printPointer->data.getValue()<<" ";
			if(printPointer == head)
			{
				//std::cout<<"<- head is: "<< head->data.getValue();
			}
			printPointer = printPointer->next;
			i++;
		}
	}
	std::cout<<std::endl;
}//print
