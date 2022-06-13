#include <iostream>
#include<conio.h>
#include <string>

using namespace std;

class Node
{
private:
	Node* next;
	Node* prev;
	string data;

	friend class Queue;
};

class Queue
{
public:
	Queue(int tm = 100);
	~Queue();
	const string& front();
	void enqueue(const string& dt);
	void dequeue();
	bool empty() const;
	int size()const;

private:
	Node* header;
	Node* trailer;
	
	int tam;
	int tamMax;
};



int main()
{
	
	Queue q(5);

	q.enqueue("Pablo");
	q.enqueue("Sergio");
	q.enqueue("Elena");
	q.enqueue("Maria");
	q.enqueue("Alberto");
	q.dequeue();

	cout << q.front() << "\n";

	_getch();
}

Queue::Queue(int tm )
{
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
	header->prev = NULL;
	trailer->next = NULL;
	
	tam = 0;
	tamMax = tm;
}
Queue::~Queue()
{
	while (!empty())
		dequeue();

	delete header;
	delete trailer;
}
const string& Queue::front()
{
	return header->next->data;
}

void Queue::enqueue(const string& dt)
{
	if (tam < tamMax)
	{
		Node* nd = new Node;
		nd->data = dt;
		nd->next = trailer;
		nd->prev = trailer->prev;

		trailer->prev->next = nd;
		trailer->prev = nd;
		tam++;
	}
}
void Queue::dequeue()
{
	if (!empty())
	{
		Node* nd = header->next->next;

		delete header->next;
		header->next = nd;
		nd->prev = header;

		tam--;
	}
}
bool Queue::empty() const
{
	return(tam == 0);
}
int Queue::size()const
{
	return tam;
}
