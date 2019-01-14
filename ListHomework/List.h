#pragma once

#include <iostream>

#include "Node.h"

using namespace std;

template <typename T>
class List
{
public:
	List();
	List(const List& source);
	List(List&& source);
	~List();

	List& operator=(const List& right);
	List& operator=(List&& right);

	void AddFirst(const T item);
	void AddLast(const T item);
	void Clear();
	unsigned int GetSize() const;
	void Print() const;
	bool RemoveFirst(const T item);
	bool RemoveLast(const T item);

private:
	Node<T>* head = nullptr;
	void Copy(const List& source);
	void Move(List&& source);
};

template <typename T>
List<T>::List()
{
}

template <typename T>
void List<T>::Copy(const List& source)
{
	if (source.head != nullptr)
	{
		Node<T>* head = new Node<T>(source.head->GetValue());
		this->head = head;
	}

	Node<T>* new_node = this->head;
	Node<T>* old_node = source.head;

	while ((old_node = old_node->GetNext()) != nullptr)
	{
		Node<T>* node = new Node<T>(old_node->GetValue());
		new_node->SetNext(node);
		new_node = node;
	}
}

template <typename T>
void List<T>::Move(List&& source)
{
	if (source.head != nullptr)
	{
		Node<T>* head = new Node<T>(source.head->GetValue());
		head->SetNext(source.head->GetNext());
		this.head = head;
	}

	source.head = nullptr;
}

template <typename T>
List<T>::List(const List& source)
{
	Copy(source);
}

template <typename T>
List<T>::List(List&& source)
{
	Move(source);
}

template <typename T>
List<T>::~List()
{
	if (head != nullptr)
	{
		Clear();
	}
}

template <typename T>
List<T>& List<T>::operator=(const List& right)
{
	Copy(right);

	return *this;
}

template <typename T>
List<T>& List<T>::operator=(List&& right)
{
	Move(right);

	return *this;
}

template <typename T>
void List<T>::AddFirst(const T item)
{
	Node<T>* node = new Node<T>(item);

	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		node->SetNext(head);
		head = node;
	}
}

template <typename T>
void List<T>::AddLast(const T item)
{
	Node<T>* node = new Node<T>(item);

	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		Node<T>* last = head;
		while (last->GetNext() != nullptr)
		{
			last = last->GetNext();
		}

		last->SetNext(node);
	}
}

template <typename T>
void List<T>::Clear()
{
	if (head != nullptr)
	{
		Node<T>* current = head;

		if (current->GetNext() != nullptr)
		{
			Node<T>* next = current->GetNext();

			while (next != nullptr)
			{
				delete current;
				current = next;
				next = current->GetNext();
			}
		}
		delete current;
		head = nullptr;
	}
}

template <typename T>
unsigned int List<T>::GetSize() const
{
	unsigned int size = 0;

	if (head != nullptr)
	{
		Node<T>* node = head;
		while (node != nullptr)
		{
			++size;
			node = node->GetNext();
		}
	}

	return size;
}

template <typename T>
void List<T>::Print() const
{
	Node<T>* node = head;
	while (node != nullptr)
	{
		cout << node->GetValue() << ' ';

		node = node->GetNext();
	}
	cout << endl;
}

template <typename T>
bool List<T>::RemoveFirst(const T item)
{
	Node<T>* previous = nullptr;
	Node<T>* current = head;

	while (current != nullptr && current->GetValue() != item)
	{
		previous = current;
		current = current->GetNext();
	}

	bool removed = current != nullptr;
	if (removed)
	{
		if (previous == nullptr)
		{
			head = current->GetNext();
		}
		else
		{
			previous->SetNext(current->GetNext());
		}
		delete current;
	}

	return removed;
}

template <typename T>
bool List<T>::RemoveLast(const T item)
{
	Node<T>* previous = nullptr;
	Node<T>* current = head;
	Node<T>* key = nullptr;
	Node<T>* key_previous = nullptr;

	while (current != nullptr)
	{
		if (current->GetValue() == item)
		{
			key = current;
			key_previous = previous;
		}
		previous = current;
		current = current->GetNext();
	}

	bool removed = key != nullptr;

	if (removed)
	{
		if (previous == nullptr)
		{
			head = key->GetNext();
		}
		else
		{
			key_previous->SetNext(key->GetNext());
		}

		delete key;
	}

	return removed;
}