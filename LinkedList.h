#pragma once
#include<iostream>
class Node
{
private:
	int data;
	Node* next;
public:
	Node() { data = 0; next = nullptr; }
	Node(int d) { data = d; next = nullptr; }
	friend class LinkedList;
};
class LinkedList
{
private:
	Node* head;
	Node* tail;
	int numele;
public:
	/*Deafualt constructor*/
	LinkedList() { head = tail = nullptr; numele = 0; }
	/*Constructor with one node*/
	LinkedList(Node* n) {
		Node* newNode = new Node;
		newNode->next = nullptr;
		newNode->data = n->data;
		head = tail = newNode;
		numele = 1;
	}  
	/*Copy Constructor does a deep copy*/
	LinkedList(const LinkedList& l);
	/*Insert at the front of the list*/
	void insertFront(int d);
	/*Insert at the back of the linked list*/
	void insertBack(int d);
	/*reverses a linked list in place*/
	void reverse();
	/*Prints the list from head to tail*/
	void printList()const;
	/*deletes the first occurrence of the node with value n*/
	void Remove(int n);
	/*returns the nymber of elements in the list O(1)*/
	int size()const;
	void delConsecutiveDuplicates();
	void removeAll(int n);

};
LinkedList::LinkedList(const LinkedList& l)
{
	if (l.head == nullptr)
		head = tail = nullptr;
	else
	{
		Node* current = l.head;
		Node* newNode = new Node;
		newNode->data = current->data;
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
		Node* p = head;
		current = current->next;
		while (current)
		{
			Node* newNode = new Node;
			newNode->data = current->data;
			newNode->next = nullptr;
			p->next = newNode;
			tail = newNode;
			current = current->next;
		}

	}
	numele = l.numele;
}
/* Insert an element at the the back of the linked List*/
void LinkedList::insertBack(int d)
{
	if (head == nullptr)
	{
		Node* newNode = new Node;
		newNode->data = d;
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node* newNode = new Node;
		newNode->data = d;
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
	}
	++numele;

}
void LinkedList::insertFront(int d)
{
	if (head == nullptr)
	{
		Node* newNode = new Node;
		newNode->data = d;
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node* newNode = new Node;
		newNode->data = d;
		newNode->next =head;
		head = newNode;
	}
	++numele;
}
void LinkedList::Remove(int n)
{
	if (head == nullptr)
		return;
	else if (head->data == n)
	{
		Node* todelete = head;
		head = head->next;
		delete todelete;
		--numele;
	}
	else {
		Node* previous = head;
		Node* following = head->next;
		while (following and following->data!=n)
		{
			previous = previous->next;
			following = following->next;

		}
		if (following)
		{
			previous->next = following->next;
			delete following;
			--numele;
		}
		else
			return;
	}
}

int LinkedList::size()const
{
	return numele;
}

void LinkedList::printList()const
{
	if (head == nullptr)
		return;
	else
	{
		Node* current = head;
		while (current)
		{
			std::cout << current->data << "\t";
			current = current->next;
		}
		std::cout << "\n";
	}
}

void LinkedList::reverse()
{
	if (head==nullptr)
		return;
	//else if (size()==2)

	else
	{
		Node* previous = nullptr; 
		Node* current = head;
		Node* temp = nullptr;
		while (current)
		{
			temp = current->next;
			current->next = previous;
			previous = current;
			current = temp;

		}
		
		 temp = head;
		head = tail;
		tail = temp;
	}
}

void LinkedList::delConsecutiveDuplicates()
{
	Node* nodeptr = head;
	Node* nextptr = head->next;
	while (nextptr and nodeptr) {
		int temp;
		
		if (nextptr->data == nodeptr->data) {
			nodeptr->next = nextptr->next;
			 delete nextptr;
			--numele;
			//std::cout << "in if nodep : " << nodeptr->data << "   nextptr  " << std::endl;
		}
		else {
			/*nodeptr = nextptr;*/
			nodeptr = nodeptr->next;
			nextptr = nextptr->next;
			//std::cout << " in else :" << nodeptr->data << "   nextptr  " << nextptr->data << std::endl;
		}
		nextptr = nodeptr->next;
	}
	//TODO
	
}
void LinkedList::removeAll(int n)
{
	if (head == nullptr)
		return;
	else {
		Node* previous = head;
		Node* following = head->next;
		while (following and previous)
		{
			if (head->data == n)
			{
				Node* todelete = head;
				head = head->next;
				delete todelete;
				--numele;
				previous = head;
				following = head->next;
			}
			else if (following->data == n)
			{
				previous->next = following->next;
				delete following;
				--numele;
				following = previous->next;
			}
			else {
				previous = previous->next;
				following = following->next;
			}
			
		
		}
		
		
	}
	//TODO
}