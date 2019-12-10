
#include <iostream>
#pragma once


template <class T>
struct Node
{
	T data;
	Node* next, *prev;
};

template <class T>
class List
{
	Node<T>* Head, Tail;
	int Count;
public:
	List();
	List(List&);
	~List();
	int getCount() { return Count; };
	T getData(int);
	Node<T>* getNode(int);
	void Add(T);
	void Delete(int);
	void Show();
	List operator + (List<T>&);
	bool operator == (List<T>&);
	bool operator > (List<T>&);
	bool operator < (List<T>&);

};

