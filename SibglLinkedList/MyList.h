#pragma once

#include <iostream>

using namespace std;

class MyList {								//list class
public:
	MyList();								//constructor, destructor, methods declaration
	~MyList();
	void push_back(int data);
	int get_size();
	int at(int index);
	bool isEmpty();
	void pop_front();
	void clear();
	void push_front(int data);
	void insert(int data, int index);
	void remove(int index);
	void set(int data, int index);
	void pop_back();
	bool contains(MyList& List);
	friend std::ostream& operator<< (std::ostream& out, const MyList& list);

private:									//struct node, which contains data and reference to next element 
	struct Node {
		Node* pNext;
		int data;
		Node(int data = int(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;								//size of the list
	Node* head;								//reference on the first element of the list


};


MyList::MyList() {							//list creator      O(1)

	size = 0;
	head = nullptr;

}

void MyList::push_back(int data)			//function that adds element to the end of the list			O(n)
{
	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		Node* curr = this->head;
		while ((curr->pNext) != nullptr)
		{
			curr = curr->pNext;
		}
		curr->pNext = new Node(data);
	}
	size++;
};

int MyList::get_size()						//function that returns size of the list		O(1)
{
	return size;
}

int MyList::at(int index)					//function that returns data of the element with assigned index		O(n)
{
	if ((index >= 0) && (index < size)) {
		int currIndex = 0;
		Node* curr = this->head;
		while (curr != nullptr) {
			if (currIndex == index) {
				return curr->data;
			}
			curr = curr->pNext;
			currIndex++;
		}
	}
	else
	{
		throw invalid_argument("Out of List range, index must be in range 0 <= index < size");
	}

}

bool MyList::isEmpty()						//function returns 1 if the list is empty and 0 if it has at least one element		O(1)
{
	return head == nullptr;
}

void MyList::pop_front()					//function that delete the first element		O(1)
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

void MyList::clear()						//function that delete all elements			O(n)
{
	while (size != 0) {
		pop_front();
	}
}

void MyList::push_front(int data)			//function that add new element at the first position	O(1)
{
	head = new Node(data, head);
	size++;
}

void MyList::insert(int data, int index)	//function that add new element at assigned position	O(n)
{
	if ((index >= 0) && (index <= size)) {
		if (index == 0)
		{
			push_front(data);
		}
		else {
			Node* prevNode = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prevNode = prevNode->pNext;
			}
			prevNode->pNext = new Node(data, prevNode->pNext);
			size++;
		}
	}
	else
	{
		throw invalid_argument("Out of List range, index must be in range 0 <= index <= size");
	}
}

void MyList::remove(int index)			//function that delete element with assigned position	O(n)
{
	if ((index >= 0) && (index < size)) {
		if (index == 0) {
			pop_front();
		}
		else {
			Node* prevNode = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prevNode = prevNode->pNext;
			}
			Node* removedNode = prevNode->pNext;
			prevNode->pNext = removedNode->pNext;
			delete removedNode;
			size--;
		}
	}
	else
	{
		throw invalid_argument("Out of List range, index must be in range 0 <= index < size");
	}
}

void MyList::set(int data, int index)		//function that change data of the element with assigned position	O(n)
{
	if ((index >= 0) && (index < size)) {
		Node* currNode = this->head;
		for (int i = 0; i < index; i++)
		{
			currNode = currNode->pNext;
		}
		currNode->data = data;
	}
	else
	{
		throw invalid_argument("Out of List range, index must be in range 0 <= index < size");
	}
}

void MyList::pop_back()						//function that delete the last element of the list		O(n)
{
	int toRemove = size - 1;
	remove(toRemove);
}

bool MyList::contains(MyList& List)			//function that check if the list contains another list		O(n)
{
	int fSize = this->size;
	int sSize = List.get_size();
	bool equalContinue = false;
	int equalCount = 0;
	Node* curr = this->head;
	if (fSize == 0 || sSize == 0) return false;
	if (fSize >= sSize) {
		for (int j = 0; j < sSize; j++)
		{
			if (curr->data == List.at(j)) {
				equalContinue = true;
				equalCount++;
				curr = curr->pNext;
			}
			else
			{
				equalContinue = false;
				equalCount = 0;
			}
			if ((equalContinue == true) && (equalCount == sSize)) return true;
		}
	}
	else
	{
		for (int i = 0; i < sSize; i++)
		{
			if (curr->data == List.at(i)) {
				equalContinue = true;
				equalCount++;
				i++;
			}
			else
			{
				equalContinue = false;
				equalCount = 0;
			}
			if ((equalContinue == true) && (equalCount == fSize)) return true;
			if (curr->pNext != nullptr) curr = curr->pNext; else
			{
				break;
			}
		}
	}
	return false;

}

std::ostream& operator<<(std::ostream& out, MyList& list)      //override of "<<"		O(n)
{
	int listSize = list.get_size();
	for (int i = 0; i < listSize; i++)
	{
		cout << list.at(i) << endl;
	}
	return out;
}


MyList::~MyList() {					//list destructor			O(n)
	clear();
};
