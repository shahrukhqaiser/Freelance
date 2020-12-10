#include <iostream>
using namespace std;

template <class T> class CQueueElem
{
public:
	T value;
	CQueueElem<T>* next;

	CQueueElem(T val);
	
};

template <class T> CQueueElem<T>::CQueueElem(T val)
{
	value = val;
	next = nullptr;
}

template <class T> class CQueue
{
	CQueueElem<T>* head;

public:

	CQueue();
	void addElem(T value);
	bool getElem(T& value);
	bool inQueue(T value);
	~CQueue();
};

template <class T> CQueue<T>::CQueue()
	{
		head = nullptr;
	}

template <class T> void CQueue<T>:: addElem(T value)
	{
		if (head == nullptr)
		{
			head = new CQueueElem<T>(value);
		}
		else
		{
			CQueueElem<T> *ptr = head;
			while (ptr->next != nullptr)
			{
				ptr = ptr->next;
			}
			ptr->next = new CQueueElem<T>(value);
		}
	}

template <class T> bool CQueue<T>:: getElem(T& value)
	{
		if (head != nullptr)
		{
			value = head->value;

			return true;
		}

		return false;
	}

template <class T> bool CQueue<T>::inQueue(T value)
	{
		if (head != nullptr)
		{
			CQueueElem<T>* ptr = head;

			while (ptr->next != nullptr)
			{
				if (ptr->value == value)
				{
					return true;
				}
				ptr = ptr->next;
			}
		}
		
		return false;
	}

template <class T> CQueue<T>::~CQueue()
	{
		CQueueElem<T> *current = head;
		CQueueElem<T>* next;

		while (current != nullptr)
		{
			next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}
	


int main()
{
	CQueue<int> queue;
	queue.addElem(5);
	queue.addElem(3);
	queue.addElem(2);
	int value;
	queue.getElem(value);
	cout << value;
	if (queue.inQueue(3))
	{
		cout << "Found";
	}
	else
	{
		cout << "Not found";
	}
	return 0;
}