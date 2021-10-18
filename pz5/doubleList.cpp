#include <iostream>

using namespace std;

template <class T>
struct Elem
{
	Elem* next;
	Elem* prev;
	T data;
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
		cout << "{ " << head->data << " } ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	List<int>* datalist = new List<int>();

	for (int i = 0; i < 10; i++)
		datalist->pushBack(i);
	datalist->show();
}
