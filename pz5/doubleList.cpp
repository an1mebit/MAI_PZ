#include <iostream>

using namespace std;

template <class T>
struct Elem
{
	Elem<T>* next;
	Elem<T>* prev;
	T data;

	int uid;
	int calls = 0;

	Elem(int id)
	{
		uid = id;
	}
};

template <class T>
class List
{
	Elem<T>* head;
	Elem<T>* tail;
	size_t size;


public:
	List() : head(nullptr), tail(nullptr), size(0) {}
	~List() { clear(); }

	void pushBack(const T& data);
	void clear();
	void show();
	T get(int id);
	void swap(Elem<T>* l1, Elem<T>* l2);
	void sort(Elem<T>* lst);
};

template<class T>
void List<T>::pushBack(const T& data)
{
	if (!tail)
		head = tail = new Elem<T>{ nullptr, nullptr, data };
	else
	{
		Elem<T>* current = new Elem<T>{ nullptr, tail, data };
		tail->next = current;
		tail = current;
	}
	size++;
}

template<class T>
void List<T>::clear()
{
	while (head)
	{
		Elem<T> current = head;
		head = head->next;
		delete current;
	}
	tail = head;
	size = 0;
}

template<class T>
void List<T>::show()
{
	while (head)
	{
		Elem<T>* current = head;
		cout << head->uid << "{ " << head->data << " } ";
		head = head->next;
	}
	cout << endl;
}

template<class T>
T List<T>::get(int id)
{
	Elem<T>* current = head;
	while (head->uid != id && head->next != nullptr)
		head = head->next;

	if (head->uid == id)
	{
		head->calls++;

		sort(head);
		return head->data;
	}
	else
	{
		cout << "Getter error:";
		cout << "No matching records were found. Returned first element." << endl;
		return head->data;
	}
}

template<class T>
void List<T>::swap(Elem<T>* l1, Elem<T>* l2)
{
	Elem<T> tmp;
	tmp = l1;
	l1 = l2;
	l1->next = tmp.next;
	tmp->next = l2->next;
	l2->prev = l1->prev;
	l1->prev = tmp->prev;
	l2 = tmp;
}

template<class T>
void List<T>::sort(Elem<T>* lst)
{
	while (lst->prev != nullptr)
	{
		if (lst->prev->calls < lst->calls)
			swap(lst->prev, lst);
		else break;

		lst = lst->prev;
	}
}

int main()
{
	List<int>* datalist = new List<int>();

	for (int i = 0; i < 10; i++)
		datalist->pushBack(i);
	datalist->show();
	cout << "===============================" << endl;
	
	datalist->get(4);
	datalist->get(4);
	datalist->get(2);
	datalist->get(9);
	datalist->show();
}
