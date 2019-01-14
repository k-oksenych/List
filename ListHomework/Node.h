#pragma once

template <typename T>
class Node
{
public:
	Node(T value) :
		value(value)
	{
	}

	Node* GetNext() const
	{
		return next;
	}

	T GetValue() const
	{
		return value;
	}

	void SetNext(Node* const next)
	{
		this->next = next;
	}
private:
	Node* next = nullptr;
	T value;
};