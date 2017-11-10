#ifndef LIST_342_H
#define LIST_342_H

#pragma once

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

#include "Bird.h"
#include "Child.h"

using namespace std;

class Child;
class Bird;


template <class ItemType>
class List342
{
	template <class ItemType>
	friend ostream &operator<<(ostream &output, const List342<ItemType> &rightObj);

private:
	struct Node
	{
		ItemType* data;
		Node* next;
	};

	Node* head;

public:
	List342();
	List342(string fileName);
	List342(List342<ItemType> &sourceObj);
	~List342();

	bool BuildList(string fileName);
	bool Insert(ItemType* obj);
	bool Remove(ItemType target, ItemType &result);
	bool Peek(ItemType target, ItemType &result);
	bool isEmpty() const;
	void DeleteList();
	bool Merge(List342 &rightObj);


	List342<ItemType> operator +(const List342 &rightObj) const;
	List342<ItemType> &operator += (const List342 &rightObj);

	bool operator ==(const List342 &rightObj) const;
	bool operator !=(const List342 &rightObj) const;

	List342<ItemType> &operator =(const List342 &rightObj);



};

template <class ItemType>
ostream &operator <<(ostream &output, const List342<ItemType> &rightObj)
{
	if (rightObj.isEmpty())
	{
		output << "The list is empty!";
		return output;
	}

	List342<ItemType>::Node* current = rightObj.head;

	while (current != NULL)
	{
		output << *current->data;
		current = current->next;
	}


	current = NULL;

	return output;
}

template <class ItemType>
List342<ItemType>::List342()
{
	head = NULL;
}

template <class ItemType>
List342<ItemType>::List342(string fileName)
{
	BuildList(fileName);
}

template <class ItemType>
List342<ItemType>::List342(List342 &sourceObj)
{
	*this = sourceObj;
}

template <class ItemType>
List342<ItemType>::~List342()
{
	DeleteList();
}


template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
	head = NULL;

	fstream inputFile(fileName);

	if (inputFile)
	{
		ItemType temp;

		while (inputFile >> temp)
		{	
			Insert(&temp);
		}

		inputFile.close();

		return true;
	}

	return false;
}

template <class ItemType>
bool List342<ItemType>::Insert(ItemType* obj)
{
	if (obj == NULL)
	{
		return false;
	}

	if (head != NULL && *obj == *head->data)
	{
		return false;
	}

	Node* temp = new Node;
	temp->next = NULL;
	temp->data = new ItemType(*obj);

	if (head == NULL || *temp->data < *head->data)
	{
		temp->next = head;
		head = temp;

		temp = NULL;

		return true;
	}

	Node* current = head->next;
	Node* previous = head;

	while (current != NULL && *current->data <= *temp->data)
	{
		previous = current;
		current = current->next;
	}

	if (*previous->data == *temp->data)
	{
		delete temp;
		temp = NULL;

		return false;
	}

	temp->next = current;
	previous->next = temp;

	temp = NULL;
	current = NULL;
	previous = NULL;


	return true;

}

template <class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType &result)
{
	if (head == NULL)
	{
		return false;
	}

	Node* temp;

	if (*head->data == target)
	{
		temp = head;
		result = target;
		head = head->next;

		delete temp;
		temp = NULL;

		return true;
	}

	Node* current = head;

	while (current->next != NULL && *current->next->data != target)
	{
		current = current->next;
	}

	if (current->next == NULL)
	{
		return false;
	}


	temp = current->next;
	current->next = current->next->next;
	result = target;

	delete temp;
	temp = NULL;


	current = NULL;

	return true;
}

template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType &result)
{
	if (head == NULL)
	{
		return false;
	}

	if (*head->data == target)
	{
		result = target;

		return true;
	}


	Node* current = head;

	while (current->next != NULL && *current->data != target)
	{
		current = current->next;
	}

	if (*current->data == target)
	{
		result = target;

		return true;

	}


	current = NULL;

	return false;
}

template <class ItemType>
bool List342<ItemType>::isEmpty() const
{
	return head == NULL;
}

template <class ItemType>
void List342<ItemType>::DeleteList()
{
	if (isEmpty())
	{
		return;
	}


	while (head != NULL)
	{
		Node* temp = head;

		head = head->next;

		delete temp->data;
		temp->data = NULL;
		delete temp;
		temp = NULL;
	}


	head = NULL;
}

template <class ItemType>
bool List342<ItemType>::Merge(List342 &rightObj)
{
	if (this == &rightObj || rightObj.head == NULL)
	{
		return false;
	}

	if (head == NULL && rightObj.head == NULL)
	{
		head = rightObj.head;
		rightObj.head = NULL;

		return true;
	}

	Node* currentLeft = head;
	Node* currentRight = rightObj.head;
	head = NULL;
	rightObj.head = NULL;

	Node tempList;
	Node* current = &tempList;

	while (currentLeft != NULL && currentRight != NULL)
	{
		if (*currentLeft->data == *currentRight->data)
		{
			current->next = currentLeft;
			currentLeft = currentLeft->next;

			Node* duplicatesToDelete = currentRight;
			currentRight = currentRight->next;

			delete duplicatesToDelete->data;
			duplicatesToDelete->data = NULL;
			delete duplicatesToDelete;
			duplicatesToDelete = NULL;
		}
		else if (*currentLeft->data < *currentRight->data)
		{
			current->next = currentLeft;
			currentLeft = currentLeft->next;
		}
		else
		{
			current->next = currentRight;
			currentRight = currentRight->next;
		}

		current = current->next;
	}

	if (currentLeft != NULL)
	{
		current->next = currentLeft;
	}

	if (currentRight != NULL)
	{
		current->next = currentRight;
	}

	head = tempList.next;


	currentLeft = NULL;
	currentRight = NULL;

	return true;
}


template <class ItemType>
List342<ItemType> List342<ItemType>::operator +(const List342 &rightObj) const
{
	List342<ItemType> tempList;

	Node* current;

	while (current != NULL)
	{
		tempList.Insert(current->data);
		current = current->next;
	}

	current = rightObj.head;

	while (current != NULL)
	{
		tempList.Insert(current->data);
		current = current->next;
	}


	current = NULL;

	return tempList;
}

template <class ItemType>
List342<ItemType> &List342<ItemType>::operator +=(const List342 &rightObj)
{
	if (rightObj.head == NULL)
	{
		return *this;
	}

	Node* current = rightObj.head;

	while (current != NULL)
	{
		Insert(current->data);
		current = current->next;
	}


	current = NULL;

	return *this;
}

template <class ItemType>
bool List342<ItemType>::operator ==(const List342 &rightObj) const
{
	if (head == NULL && rightObj.head == NULL)
	{
		return true;
	}

	if ((head == NULL && rightObj.head != NULL) ||
		(head != NULL && rightObj.head == NULL))
	{
		return false;
	}

	Node* currentLeft = head;
	Node* currentRight = rightObj.head;

	if (*currentLeft->data != *currentRight->data)
	{
		return false;
	}

	while (currentLeft->next != NULL && currentRight->next != NULL)
	{
		if (*currentLeft->data != *currentRight->data)
		{
			return false;
		}
		else
		{
			currentLeft = currentLeft->next;
			currentRight = currentRight->next;
		}
	}

	if (currentLeft->next != NULL || currentRight->next != NULL)
	{
		return false;
	}

	currentLeft = NULL;
	currentRight = NULL;

	return true;
}

template <class ItemType>
bool List342<ItemType>::operator !=(const List342 &rightObj) const
{
	Node* currentLeft = head;
	Node* currentRight = rightObj.head;

	while (currentLeft != NULL)
	{
		if (currentLeft->data == currentRight->data)
		{
			return true;
		}

		currentLeft = currentLeft->next;
		currentRight = currentRight->next;
	}


	currentLeft = NULL;
	currentRight = NULL;

	return false;
}

template <class ItemType>
List342<ItemType> &List342<ItemType>::operator =(const List342 &rightObj)
{
	head = NULL;

	if (this != &rightObj)
	{
		if (!rightObj.isEmpty())
		{
			DeleteList();		// Used to cleanup Dynamically Allocated memory, if this object is being reused.

			Node* currentRight = rightObj.head;
			Node* currentLeft = new Node;
			currentLeft->next = NULL;
			currentLeft->data = new ItemType;
			*currentLeft->data = *currentRight->data;
			
			head = currentLeft;

			while (currentRight->next != NULL)
			{
				currentLeft->next = new Node;
				currentLeft->next->next = NULL;
				currentLeft->next->data = new ItemType;
				*currentLeft->next->data = *currentRight->next->data;

				currentRight = currentRight->next;
				currentLeft = currentLeft->next;
			}

			currentLeft = NULL;
			currentRight = NULL;

		}

	}

	return *this;
}

#endif

