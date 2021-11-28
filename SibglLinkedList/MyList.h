#pragma once

#include <iostream>

using namespace std;

class MyList {
public:
	MyList();
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
	friend bool contains(MyList& fList, MyList& sList);
	friend std::ostream& operator<< (std::ostream& out, const MyList& list);

private:
	struct Node {
		Node* pNext;
		int data;
		Node(int data = int(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node* head;


};


MyList::MyList() {

	size = 0;
	head = nullptr;

}

void MyList::push_back(int data)
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

int MyList::get_size()
{
	return size;
}

int MyList::at(int index)
{
	int currIndex = 0;
	Node* curr = this->head;
	while (curr != nullptr) {
		if (currIndex == index) {
			return curr->data;
		}
		curr = curr->pNext;
		currIndex++;
	}
	cout << "Your List contains only " << currIndex << " elements." << endl;
	return 0;
}

bool MyList::isEmpty()
{
	return head == nullptr;
}

void MyList::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

void MyList::clear()
{
	while (size != 0) {
		pop_front();
	}
}

void MyList::push_front(int data)
{
	head = new Node(data, head);
	size++;
}

void MyList::insert(int data, int index)
{
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

void MyList::remove(int index)
{
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

void MyList::set(int data, int index)
{
	Node* currNode = this->head;
	for (int i = 0; i < index; i++)
	{
		currNode = currNode->pNext;
	}
	currNode->data = data;
}

void MyList::pop_back()
{
	remove(size--);
}

bool contains(MyList& fList, MyList& sList)
{
	int fSize = fList.get_size();
	int sSize = sList.get_size();
	bool equalContinue = false;
	int equalCount = 0;
	if (fSize == 0 or sSize == 0) return false;
	if (fSize >= sSize) {
		for (int i = 0; i < fSize; i++)
		{
			for (int j = 0; j < sSize; j++)
			{
				if (fList.at(i) == sList.at(j)) {
					equalContinue = true;
					equalCount++;
					i++;
				}
				else
				{
					equalContinue = false;
					equalCount = 0;
				}
				if ((equalContinue == true) and (equalCount == sSize)) return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < sSize; i++)
		{
			for (int j = 0; j < fSize; j++)
			{
				if (fList.at(j) == sList.at(i)) {
					equalContinue = true;
					equalCount++;
					i++;
				}
				else
				{
					equalContinue = false;
					equalCount = 0;
				}
				if ((equalContinue == true) and (equalCount == fSize)) return true;
			}
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, MyList& list)
{
	int listSize = list.get_size();
	for (int i = 0; i < listSize; i++)
	{
		cout << list.at(i) << endl;
	}
	return out;
}


MyList::~MyList() {
	clear();
};