#include <iostream>
using namespace std;
template <class type>
class list
{
    // node inner class
	class node
	{
	public:
		type data;
		node* next;
		node* prev;
		node(type data)
		{
			next = NULL;
			prev = NULL;
			this->data = data;
		}
		node() {
			next = NULL;
			prev = NULL;
		}
	};

	node* head;
	node* tail;
	node*dummy=new node;
	int size;
public:
	list(){
		size = 0;
	}
	list(type val, int Size)
	{
		size = Size;

		// first node insertion
		node* temp = new node; temp->data = val;
		dummy->prev = temp;
		temp->next = dummy;
		tail = temp;
		head = temp;

		//rest of nodes insertion
		for (int i = 1; i < size; i++)
		{
			node* temp = new node; temp->data = val;
			temp->next = tail->next;
			temp->prev = tail;
			tail->next->prev = temp;
			tail->next = temp;
			tail = temp;
		}
	}
	void push_back(type val)
	{
		if (size == 0)
		{
			node* temp = new node; temp->data = val;
			dummy->prev = temp;
			temp->next = dummy;
			tail = temp;
			head = temp;
		}
		else {
			node* temp = new node; temp->data = val;
			temp->next = tail->next;
			temp->prev = tail;
			tail->next->prev = temp;
			tail->next = temp;
			tail = temp;
		}
		size++;
	}
	void pop_back()
	{
		if (size == 1){ delete tail;
		tail = NULL;
		}
		else
		{
			tail->prev->next = dummy;
			dummy->prev = tail->prev;
			delete tail;
			tail = dummy->prev;
		}
		size--;
	}
	bool empty()
	{
		if (size == 0)return true;
		else return false;
	}
	int Size()
	{
		return this->size;
	}

	// iterator code
	class iterator {
		friend class list<type>;
		node*iter;
	public:
		iterator() {};
		void operator=( iterator it)
		{
			iter = it.iter;
		}
		void operator++()
		{
			if (iter->next == NULL)throw"Invalid";
			iter=iter->next;
		}
		void operator--()
		{
			if (iter->prev == NULL)throw"Invalid";
			iter = iter->prev;
		}
		type& operator*()
		{
			return iter->data;
		}
		bool operator == (const iterator& it)
		{
			if (iter == it.iter)
				return true;
			else
                return false;
		}
	};

	void insert(type value, iterator &position)
	{
		node*newnode=new node(value);
		if (position.iter == head)
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
			position.iter = newnode;
		}
		else {
			newnode->next = position.iter;
			newnode->prev = position.iter->prev;
			position.iter->prev->next = newnode;
			position.iter->prev = newnode;
			position.iter = newnode;
		}
		size++;
	}

	iterator erase(iterator position)
	{
		if (position.iter == head)
		{
			head = head->next;
			delete position.iter;
			position.iter = head;
		}
		else {
			node* n;
			n = position.iter;
			position.iter->prev->next = position.iter->next;
			position.iter->next->prev = position.iter->prev;
			position.iter = position.iter->next;

			if(n==tail)
			tail = tail->prev;

			delete n;
		}
		size--;
		return position;
	}
	list<type>& operator=(list<type>& l)
	{
		//clearing the old list
		clearList();

		iterator it=l.begin();
		for (int i = 0; i < l.size; i++)
		{
			push_back(*it);
			++it;
		}
		size = l.size;

		return l;
	}
	iterator begin()
	{
		iterator it;
		it.iter = head;
		return it;
	}
	iterator end()
	{
		iterator it; it.iter = tail;
		return it;
	}

	void print()
	{
		node* n;
		n = head;
		while(n!=tail->next)
		{
			cout << n->data << " ";
			n = n->next;
		}
		cout << endl;
	}

	void clearList()
	{
		while (size!=0){
			pop_back();
		}
	}
	~list()
	{
		clearList();
		delete dummy;
	}
};

int main() {
	cout << "Testing..." << endl;
	cout << "creating list(list1) with initial size(7) and default value(4): ";
	list<int>list1(4,7);
	list1.print();
	list<int>::iterator it = list1.begin();
	++it;
	list1.insert(15,it);
	cout << "inserting 15 in the second position using iterator: ";
	list1.print();
	cout << "erasing the last node using iterator: ";
	it = list1.end();
	list1.erase(it);
	list1.print();
	cout << "testing the assignment operator: " << endl;
	list<int>list2;
	cout << "creating list2.." << endl << "pushing back-> 5 7 8 9" << endl;
	list2.push_back(5);	list2.push_back(7);	list2.push_back(8);	list2.push_back(9);
	list1 = list2;
	cout << "list1: "; list1.print();
	cout << "list2: "; list2.print();
	cout << "poping back 2 times from list1.." << endl;
	list1.pop_back(); list1.pop_back();
	cout << "list1: "; list1.print();
	cout << "list2: "; list2.print();
}

