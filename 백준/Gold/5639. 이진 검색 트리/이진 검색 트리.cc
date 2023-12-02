#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int key) {
	if (node == NULL)
	{
		node = new Node();
		node->key = key;
		node->left = NULL;
		node->right = NULL;
	}
	else if (node->key > key)
	{
		node->left = insert(node->left, key);
	}
	else
	{
		node->right = insert(node->right, key);
	}
	return node;
}

void postorder(Node* node) {

	if (node->left != NULL) {
		postorder(node->left);
	}
	if (node->right != NULL) {
		postorder(node->right);
	}
	cout << node->key << "\n";
}

int main() {
	Node* root = NULL;
	int n;
	while (cin >> n) {
		if (n == EOF) break;
		root = insert(root, n);
	}
	postorder(root);
}