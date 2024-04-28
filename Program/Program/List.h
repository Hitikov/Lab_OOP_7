#pragma once
const int MAX_SIZE = 25;

template <typename TT>
class Elem{
public:
	TT data;
	Elem* next = nullptr;
	Elem* prev = nullptr;
};

template <typename TT>
class ListIterator
{
public:
	Elem<TT>* elem;
	ListIterator();
	ListIterator(const ListIterator<TT>& it);
	ListIterator& operator=(const ListIterator<TT>& a);
	TT& operator*() const;
	ListIterator& operator+ (const int& a);
};

template <typename TT>
class List
{
	int size;
	Elem<TT>* head = nullptr;
	Elem<TT>* tail = nullptr;
	ListIterator<TT> beg;
	ListIterator<TT> end;

public:
	List() { size = 0; head = nullptr; tail = nullptr;};
	List(int s);
	List(const List<TT>& l);
	~List();

	ListIterator<TT> first();
	ListIterator<TT> last();
	void PushBack(TT a);
	void PopBack();

	List& operator= (const List<TT>& l);
	TT& operator[] (int i);
	int& operator()();
	List operator*(List<TT>& l);
	
};

template <typename TT>
List<TT>::List(int s)
{
	size = s;
	Elem<TT>* new_elem = new Elem<TT>;
	head = new_elem;
	tail = new_elem;

	for (int i = 0; i < size - 1; i++)
	{
		Elem<TT>* new_elem = new Elem<TT>;
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
	}
	beg.elem = head;
	end.elem = tail;
}

template <typename TT>
List<TT>::List(const List<TT>& l)
{
	Elem<TT>* elem = l.head;
	while (elem != nullptr) {
		PushBack(elem->data);
		elem = elem->next;
	}
	beg.elem = head;
	end.elem = tail;
}

template <typename TT>
List<TT>::~List()
{
	Elem<TT>* curr = head;
	while (curr != nullptr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

template <typename TT>
List<TT>& List<TT>::operator= (const List<TT>& l)
{
	if (this == &l)return *this;

	if (head != nullptr)
	{
		Elem<TT>* curr = head;
		while (curr != nullptr)
		{
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

	Elem<TT>* elem = l.head;
	while (elem != nullptr) {
		PushBack(elem->data);
		elem = elem->next;
	}
	beg.elem = head;
	end.elem = tail;
	return *this;
}

template <typename TT>
TT& List<TT>::operator[] (int i)
{
	Elem<TT>* curr = head;
	for (int j = 0; j < i; j++) {
		curr = curr->next;
	}
	return curr->data;
}

template <typename TT>
List<TT> List<TT>::operator*(List<TT>& l)
{
	List base = *this;
	int s = this->size;
	List temp;

	for (int i = 0; i < s; i++)
	{
		temp.PushBack(base[i] * l[i]);
	}

	return temp;
}

template <typename TT>
int& List<TT>::operator()() {
	return size;
}


template <typename TT>
ListIterator<TT> List<TT>::first()
{
	return beg;
}

template <typename TT>
ListIterator<TT> List<TT>::last()
{
	return end;
}

template <typename TT>
void List<TT>::PushBack(TT a)
{
	Elem<TT>* new_elem = new Elem<TT>;
	new_elem->data = a;

	if (size == 0)
	{
		head = new_elem;
		tail = new_elem;
		size++;
		beg.elem = head;
		end.elem = tail;
	}
	else
	{
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
		size++;
		end.elem = tail;
	}

}

template <typename TT>
void List<TT>::PopBack()
{
	Elem<TT>* curr = tail;
	tail = curr->prev;
	delete curr;
	tail->next = nullptr;
	size--;
	end.elem = tail;
}


template <typename TT>
ListIterator<TT>::ListIterator() {
	elem = nullptr;
}

template <typename TT>
ListIterator<TT>::ListIterator(const ListIterator& it) {
	elem = it.elem;
}

template <typename TT>
ListIterator<TT>& ListIterator<TT>::operator=(const ListIterator<TT>& a)
{
	elem = a.elem;
	return *this;
}

template <typename TT>
TT& ListIterator<TT>::operator*() const
{
	return elem->data;
}

template <typename TT>
ListIterator<TT>& ListIterator<TT>::operator+ (const int& a)
{
	for (int i = 0; i < a; ++i) {
		elem = elem->next;
	}
	return *this;
}