//---------------------------------------------------------------------------

#ifndef listH
#define listH
#include <vcl.h>

#include <tuple>
//---------------------------------------------------------------------------

template <class T>
class Node
{
	public:
	T data;
	Node *next;
	Node *prev;
	public:
	Node(T data) : data(data)
	{ }
	Node(T data, Node* next, Node* prev) : data(data), next(next), prev(prev)
	{ }
};

template <class T>
class Queque
{
	protected:
	Node<T> *head, *tail;
	int size_t;
	public:
	Queque();
	void push_back(T data);
	T pop_front();
	int size();
	void clear();
    void display(TListBox* ListBox);
	void is_empty(TListBox* ListBox);
	T operator[](int num);
};

class List : public Queque<String>
{
	public:
	Node<String> *sort(Node<String> *item);
	Node<String> **find_indirect(List *l, Node<String> *target);
	void insertBefore(List *l,Node<String> *before, Node<String> *item);
	void Show(TListBox* ListBox)
	{

		Node<String> *cur = head;
	   //	UnicodeString answer = "";
		while(cur!=NULL)
		{
			ListBox->Items->Add(cur->data);
			cur = cur->next;

		}
		delete cur;

	}
	Node<String> * GetItem(int n)
	{
		Node<String> *cur = head;
		if(n<0)
		   {return NULL;}
		//while(n-- && cur)
	   //	{
	   //		cur=cur->next;
	   //	}
		for(int i = 0; i < n && (cur != NULL); i++)
		{
			cur = cur->next ;
		}
		return cur;
	};
	Node<String> operator[](int num)
	{
		Node<String> *h = head;
		int i = 0;
		while(i < num)
		{
			h = h->next;
			i++;
		}
		return h->data;
	};
};

#endif

