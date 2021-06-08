//---------------------------------------------------------------------------

#pragma hdrstop

#include "list.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

template <class T>
Queque<T>::Queque()
{
	head = nullptr;
	tail = nullptr;
	size_t = 0;
};

template <class T>
void Queque<T>::push_back(T data)
{
	if(head == nullptr)
	{
		tail = new Node<T>(data);
		head = tail;
	}
	else
	{
		tail->next = new Node<T>(data, nullptr, tail);
		tail = tail->next;
	}
	size_t++;
}

template <class T>
T Queque<T>::pop_front()
{
	if(size_t >= 0)
	{
		auto temp = head->data;
		auto asd = head;
		head = head->next;
		size_t--;
		delete asd;
		return temp;
	}
}

template <class T>
int Queque<T>::size()
{
	return size_t;
}

template <class T>
void Queque<T>::clear()
{
	while (size_t != 0)
	{
        pop_front();
    }
}

template <class T>
void Queque<T>::is_empty(TListBox* ListBox)
{
	if (size_t == 0)
	{
		ListBox -> Items -> Clear();
		ListBox -> Items -> Add("Очередь пуста");
	}
	else
	{
		ListBox -> Items -> Clear();
		ListBox -> Items -> Add("Очередь не пуста");
		ListBox -> Items -> Add("Количество элементов: " + IntToStr(size_t));
	}
}
Node<String> **List::find_indirect(List *l,Node<String> *target)
{
	Node<String> **p = &l->head;
	while((*p)&&(*p) != target)
	{
		p = &(*p)->next;
	}
	return p;
}
Node<String> *List::sort(Node<String> *item3)
{
	//Node<String> *item = GetItem(itemindex);
   //	Node<String> *item2 = GetItem(item2index);

   Node<String> *cur = head;
	Node<String> *item = head;
   //	Node<String> *item2 = head;

	while(cur!=NULL)
	{
		if(cur->data == item3->data)
			item = cur;
	   //	if(cur->data == item4->data)
	  //		item2 = cur;


		cur = cur->next;

	}
	delete cur;

   item->prev->next = item->next;
   item->next->prev = item->prev;

   return item;

}

void List::insertBefore(List *l, Node<String> *before, Node<String> *item)
{
	Node<String> **p = find_indirect(l,before);
	*p = item;
	item->next = before;
}
template <class T>
T Queque<T>::operator[](int num)
{
	auto h = head;
	int i = 0;
	while(i < num)
	{
		h = h->next;
		i++;
	}
	return h->data;
}


