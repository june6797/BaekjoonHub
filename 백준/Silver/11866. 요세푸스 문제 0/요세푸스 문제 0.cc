#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* pre;
	Node(int X) {
		this->data = X;
		this->next = NULL;
		this->pre = NULL;
	}
};
class Queue
{
public:
	int size;
	Node* head;
	Node* tail;
	Node* now;
	int nodenum = 1;
	int nnum;
	Queue(int N, int K) {
		this->head = NULL;
		this->tail = NULL;
		this->now = NULL;
		this->size = 0;
		this->nnum = N;
	}

	void inqueue() {
		if (size == 0)
		{
			Node* v = new Node(nodenum);
			head = v;
			tail = v;
			v->next = head;
			v->pre = tail;
			now = tail;
			nodenum++;
		}
		else
		{
			Node* v = new Node(nodenum);
			tail->next = v;
			v->pre = tail;
			tail = v;
			v->next = head;
			head->pre = v;
			now = tail;
			nodenum++;
		}
		size++;

	}
	int dequeue(int K) {
		for (int i = 0; i < K; i++)
		{

			now = now->next;
		}
		Node* x = now->pre;
		Node* y = now;
		Node* z = now->next;
		int a = now->data;
		if (now == head)
		{
			head = z;
			x->next = z;
			z->pre = x;
			delete y;
			now = x;
		}
		else if (now == tail)
		{
			tail = x;
			x->next = z;
			z->pre = x;
			delete y;
			now = x;
		}
		else
		{
			x->next = z;
			z->pre = x;
			delete y;
			now = x;

		}
		return a;
	}
	void set() {
		for (int i = 0; i < nnum; i++)
		{
			inqueue();
		}
	}
};


int main() {
	int N;
	int K;
	cin >> N >> K;
	Queue q1(N, K);
	q1.set();
	cout << "<";
	for (int i = 0; i < N - 1; i++)
	{
		cout << q1.dequeue(K);
		cout << ", ";
	}
	cout << q1.dequeue(K);
	cout << ">";

}