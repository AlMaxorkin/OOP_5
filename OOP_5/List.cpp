#include "List.h"
using namespace std;

template <class T>
List<T>::~List()
{
	while (Head)                       
	{
		Tail = Head->Next;            
		delete Head;                  
		Head = Tail;                  
	}
}

template <class T>
List<T>::List()
{
	Head = Tail = NULL;
	Count = 0;
}

template <class T>
List<T>::List(List& L)
{
	Head = Tail = NULL;
	Count = 0;

	Node<T>* temp = L.Head;
	
	while (temp != NULL)
	{
		Add(temp->data);
		temp = temp->next;
	}
}

template <class T>
void  List<T>::Add(T val)
{
	Node<T>* temp = new Node<T>;

	temp->next = NULL;

	temp->data = val;
	temp->prev = Tail;

	if (Tail != NULL)
		Tail->next = temp;

	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;

		Count++;
}

template <class T>
void List<T>::Show()
{
	Node<T>* temp = Tail;

	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

template <class T>
void List<T>::Delete(int pos)
{

	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	int i = 1;

	Node<T>* Del = Head;

	while (i < pos)
	{
		Del = Del->next;
		i++;
	}

	Node<T>* PrevDel = Delete->prev;
	Node<T>* NextDel = Delete->next;

	if (PrevDel != NULL && Count != 1)
		PrevDel->next = NextDel;

	if (NextDel != NULL && Count != 1)
		NextDel->prev = PrevDel;

	if (pos == 1)
		Head = NextDel;
	if (pos == Count)
		Tail = PrevDel;

	delete Del;

	Count--;
}

template <class T>
T List<T>::getData(int pos)
{
	Node<T>* temp = Head;

	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return 0;
	}

	int i = 1;

	while (i < pos && temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return 0;
	else
		return temp->data;
}

template <class T>
Node<T>* List<T>::getNode(int pos)
{
	Node<T>* temp = Head;

	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return 0;
	}

	int i = 1;

	while (i < pos && temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return 0;
	else
		return temp;
}

template <class T>
List<T> List<T>::operator + (List& L)
{
	List<T> Result(*this);

	Node<T>* temp = L.Head;

	while (temp != NULL)
	{
		Result.Add(temp->data);
		temp = temp->next;
	}

	return Result;
}

template <class T>
bool List<T>::operator == (List& L)
{
	if (Count != L.Count)
		return false;

	Node<T>* temp1, * temp2;

	temp1 = Head;
	temp2 = L.Head;

	while (temp1 != 0)
	{
		if (temp1->data != temp2->data)
			return false;

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return true;
}

template <class T>
bool List<T>::operator < (List& L)
{
	return Count < L.Count;
}

template <class T>
bool List<T>::operator > (List& L)
{
	return Count > L.Count;
}
