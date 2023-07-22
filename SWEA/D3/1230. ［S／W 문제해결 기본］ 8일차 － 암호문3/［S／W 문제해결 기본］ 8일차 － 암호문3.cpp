#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};

class SLL
{
public:
	Node* head;
	Node* tail;
	SLL() {
		head = NULL;
		tail = NULL;
	}
	void addBack(int X);
	void add(Node* temp, int X);
	void remove(Node* temp);
	bool empty();
	void show();
};
void SLL::addBack(int X) {
	Node* v = new Node(X);
	if (empty())
	{
		head = v;
		tail = v;
	}
	else
	{
		tail->next = v;
		tail = v;
	}
}

void SLL::add(Node* temp, int X) {
	Node* cur = new Node(X);
	temp->next = cur;
}

void SLL::remove(Node* temp)
{
	Node* old = temp->next->next;
	delete temp->next;
	temp->next = old;
}

bool SLL::empty()
{
	if (head != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void SLL::show() {
	Node* temp = head->next;
	for (int i = 0; i < 10; i++)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main() {
	for (int t = 1; t <= 10; t++)
	{
		int N, num, cnum, x, y, s;
		char c;
		SLL sll;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			sll.addBack(num);
		}
		cin >> cnum;
		for (int i = 0; i < cnum; i++)
		{
			cin >> c;
			if (c == 'I')
			{
				Node* temp = sll.head;
				cin >> x;
				for (int i = 0; i < x; i++)
				{
					temp = temp->next;
				}
				Node* old = temp->next;
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					cin >> s;
					sll.add(temp, s);
					temp = temp->next;
				}
				temp->next = old;
			}
			else if (c == 'D')
			{
				Node* temp = sll.head;
				cin >> x;
				for (int i = 0; i < x; i++)
				{
					temp = temp->next;
				}
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					sll.remove(temp);
				}
			}
			else if (c == 'A')
			{
				cin >> y;
				for (int j = 0; j < y; j++)
				{
					cin >> s;
					sll.addBack(s);
				}
			}
		}
		cout << "#" << t << " ";
		sll.show();
		cout << "\n";
	}
}