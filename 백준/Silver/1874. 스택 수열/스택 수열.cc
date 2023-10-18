#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

	Node(int X) {
		this->data = X;
		this->next = NULL;
	};

};

class Stack {
public:
	Node* head;
	int sizen = 0;
	int nodenum;
	int pushnum = 0;
	Stack() {
		this->head = NULL;
		this->nodenum = 1;
	}

	int topnum() {
		return head->data;
	}
	void push() {
		if (sizen == 0)
		{
			Node* v = new Node(nodenum);
			head = v;
			cout << "+\n";
			nodenum++;
			pushnum++;
		}
		else
		{
			Node* v = new Node(nodenum);
			v->next = head;
			head = v;
			cout << "+\n";
			nodenum++;
			pushnum++;
		}
		sizen++;
	}
	void pop() {
		if (sizen == 0)
		{

		}
		else
		{
			cout << "-\n";
			Node* v = head;
			head = v->next;
			delete v;
		}
		sizen--;
	}

	void hidepush() {
		if (sizen == 0)
		{
			Node* v = new Node(nodenum);
			head = v;
			nodenum++;
			pushnum++;
		}
		else
		{
			Node* v = new Node(nodenum);
			v->next = head;
			head = v;

			nodenum++;
			pushnum++;
		}
		sizen++;
	}
	void hidepop() {
		if (sizen == 0)
		{

		}
		else
		{
			Node* v = head;
			head = v->next;
			delete v;
		}
		sizen--;
	}
};


int main() {
	int N;
	cin >> N;
	int X;
	Stack s1;
	int yn = 0;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> X;
		arr[i] = X;
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i] >= s1.nodenum)
		{
			while (arr[i] != s1.pushnum)
			{
				s1.hidepush();
			}
			s1.hidepop();

		}
		else
		{
			if (arr[i] != s1.topnum())
			{
				yn = 1;
				break;
			}
			else
			{
				s1.hidepop();
			}

		}
	}
	if (yn == 1)
	{
		cout << "NO";
	}
	else
	{
		s1.sizen = 0;
		s1.nodenum = 1;
		s1.pushnum = 0;
		s1.head = NULL;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] >= s1.nodenum)
			{
				while (arr[i] != s1.pushnum)
				{
					s1.push();
				}
				s1.pop();

			}
			else
			{

				s1.pop();

			}
		}
	}


	delete[]arr;
}