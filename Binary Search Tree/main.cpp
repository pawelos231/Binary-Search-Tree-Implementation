#include <iostream>
using namespace std;
#define LOG(x){cout<<x<<endl;}
class BST {
private:
	int data;
	BST* left; BST* right;
public:
	//constructor
	BST() {
		this->data = NULL;
		this->left = NULL;
		this->right = NULL;
	}
	BST(int dataGiven) {
		this->data = dataGiven;
		this->left = NULL;
		this->right = NULL;
	}
	BST* insertNode(BST* root, int data) {
		if (!root) {
			return new BST(data);
		}
		if (data > root->data) {
			root->right = insertNode(root->right, data);
		}
		else if (data < root->data) {
			root->left = insertNode(root->left, data);
		}
		return root;
	}
	void InorderTraversal(BST* root) {
		if (!root) {
			return;
		}
		InorderTraversal(root->left);
		LOG(root->data);
		InorderTraversal(root->right);
	}
};
int main() {
	BST b, * root = NULL;
	root = b.insertNode(root, 50);
	b.insertNode(root, 30);
	b.insertNode(root, 20);
	b.insertNode(root, 40);
	b.insertNode(root, 70);
	b.insertNode(root, 60);
	b.insertNode(root, 80);
	b.InorderTraversal(root);
}