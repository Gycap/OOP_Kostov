#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

template <class T> class Container
{
private:
	struct element
	{
		T data;
		element *next;
	};
	element *head, *iterator;
	int length = 0;

public:
	Container()
	{
		head = NULL;
		//cout << "The memory has been reserved\n";
	}

/*	void PrintC()				//Для классов неприменима
	{
		if (head)
		{
			if (head->next != NULL)
			{
				for (element *i = head; i != NULL; i = i->next)
					cout << i->data << " ";
				cout << endl;
			}
			else
				cout << head->data;
		}
		//else
			//throw "Invalid Request. Nothing to print, container is empty.\n";
	}
	*/
	void AddBegin(const T& newBegin)
	{
		element *vs;
		vs = new element;
		vs->next = head;
		vs->data = newBegin;
		head = vs;
		++length;
		//cout << "The result of adding to the end\n";
	}

	void AddEnd(const T& newEnd)
	{
		element *vs;
		vs = new element;
		vs->data = newEnd;
		vs->next = NULL;
		if (!head)
			head = vs;
		else
		{
			element *vs1;
			vs1 = head;
			while ((vs1->next) != NULL)
				vs1 = vs1->next;
			vs1->next = vs;
		}
		++length;
		//cout << "The result of adding to the end:\n";
	}

	void DelFirst()
	{
		if (head)
		{
			element *vs;
			vs = head;
			head = head->next;
			delete vs;
			--length;
			//cout << "The result of deleting first element:\n";
		}
		//else
			//throw "Invalid request. Nothing to delete\n";
	}

	void DelLast()
	{
		if (head)
		{
			element *vs, *vs_prev;
			if (head->next != NULL)
			{
				vs_prev = head;
				vs = head->next;
				while (vs->next != NULL)
				{
					vs = vs->next;
					vs_prev = vs_prev->next;
				}
				delete vs;
				vs_prev->next = NULL;
				--length;
			}
			else
			{
				vs = head;
				delete vs;
				head = NULL;
				--length;
			}
			//cout << "The result of deleting last element:\n";
		}
		//else
			//throw "Invalid request. Nothing to delete\n";
	}

	const T& GetFirst()
	{
		if (head)
			return head->data;
		//else
			//throw "Invalid request. Container is empty.\n";
	}

	const T& GetLast()
	{
		if (head)
		{
			element *vs;
			vs = head;
			while (vs->next != NULL)
				vs = vs->next;
			return vs->data;
		}
		//else
			//throw "Invalid request. Container is empty.\n"
	}

	int GetLength()			//Number of elements in container
	{
		return length;
	}

	bool IsEmpty()
	{
		if (length != 0)
		{
			//cout << "Container isn't empty\n";
			return 0;
		}
		else
		{
			//cout << "Container is empty\n";
			return 1;
		}
	}

	void StartIteration()
	{
		iterator = head;
	}

	const T* Iteration()
	{
		if (iterator->next != NULL)
		{
			iterator = iterator->next;
			return &iterator->data;
		}
		else return NULL;
	}

	~Container()
	{
		if (head) 
		{
			while (head != NULL)
			{
				element *vs;
				vs = head;
				head = head->next;
				delete vs;
			}
		}
		length = 0;
		//cout << "The memory has been cleared\n";
	}
};
