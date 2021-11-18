#include "../hdr/LinkedList.h"

class IndexOutOfBounds
		: public std::exception
{
public:
	const std::string exception() const throw();
};

const std::string IndexOutOfBounds::exception() const throw()
{
	return "Index out of bounds exception";
}

template<class T>
LinkedList<T>::LinkedList() :
		head(nullptr),
		size(0)
{
}

template<class T>
LinkedList<T>::~LinkedList()
{
	LinkedNode<T> *temp = head;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<class T>
void LinkedList<T>::add(T data)
{
	LinkedNode<T> *node = new LinkedNode<T>(data);
	if (head == nullptr)
	{
		head = node;
		goto done;
	}
	node->next = head;
	head->prior = node;
	head = node;
	done:
	size++;
}

template<typename T>
void LinkedList<T>::add(size_t index, T data)
{
	if (index >= size)
	{
		throw IndexOutOfBounds();
	}
	LinkedNode<T> *temp = head;
	size_t i = 0;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	LinkedNode<T> *node = new LinkedNode<T>(data);
	node->next = temp->next;
	node->next
			->prior = node;
	node->prior = temp;
	temp->next = node;
	size++;
}

template<class T>
void LinkedList<T>::remove(T data)
{
	LinkedNode<T> *temp = head;
	while (temp != nullptr)
	{
		if (temp->data == data)
		{
			if (temp->next != nullptr)
			{
				temp->next
						->prior = temp->prior;
			}
			temp->prior
					->next = temp->next;
			delete temp;
			size--;
			return;
		}
		temp = temp->next;
	}
}

template<typename T>
void LinkedList<T>::remove(size_t index)
{
	if (index >= size)
	{
		throw IndexOutOfBounds();
	}
	LinkedNode<T> *temp = head;
	if (index == 0)
	{
		head = head->next;
		delete temp;
		size--;
		return;
	}
	size_t i = 0;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	if (temp->next != nullptr)
	{
		temp->next
				->prior = temp->prior;
	}
	temp->prior
			->next = temp->next;
	delete temp;
	size--;
}

template<class T>
size_t LinkedList<T>::get_size()
{
	return size;
}

template<class T>
bool LinkedList<T>::contains(T data)
{
	if (head == nullptr)
	{
		return false;
	}
	LinkedNode<T> *temp = head;
	while (temp != nullptr)
	{
		if (temp->data == data)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<class T>
T &LinkedList<T>::get(size_t index)
{
	if (index >= size)
	{
		throw IndexOutOfBounds();
	}
	LinkedNode<T> *temp = head;
	size_t i = 0;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	return temp->data;
}


template<class T>
int LinkedList<T>::get_index_of(T data)
{
	LinkedNode<T> *temp = head;
	int i = 0;
	while (i < size)
	{
		if (temp->data == data)
		{
			return i;
		}
		temp = temp->next;
		i++;
	}
	return -1;
}

template<class T>
T LinkedList<T>::peek()
{
	return head->data;
}

template<class T>
T LinkedList<T>::pop()
{
	T data = head->data;
	LinkedNode<T> *temp = head;
	head = head->next;
	delete temp;
	size--;
	return data;
}

template<class T>
void LinkedList<T>::function(Function<T> &function)
{
	LinkedNode<T> *temp = head;
	while (temp != nullptr)
	{
		function.function(temp->data);
		temp = temp->next;
	}
}

template<class T>
bool LinkedList<T>::empty()
{
	return size == 0;
}

template<class T>
void LinkedList<T>::print()
{
	LinkedNode<T> *temp = head;
	while (temp != nullptr)
	{
		std::cout << "   " << temp->data << std::endl;
		temp = temp->next;
	}
}

template<class T>
LinkedNode<T>::LinkedNode(T data) :
		data(data),
		prior(nullptr),
		next(nullptr)
{
}

template<class T>
T LinkedNode<T>::get_data()
{
	return data;
}




