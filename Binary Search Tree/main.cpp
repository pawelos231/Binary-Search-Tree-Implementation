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
	BST* deleteNode(BST* root, int nodeToDelete) {
		if (!root) {
			return NULL;
		}
		if (nodeToDelete < root->data) {
			root->left = deleteNode(root->left, nodeToDelete);
		}
		else if (nodeToDelete > root->data) {
			root->right = deleteNode(root->right, nodeToDelete);
		}
		else {
			if (root->left == NULL && root->right == NULL) {
				return NULL;
			}
			else if (root->left == NULL) {
				BST* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == NULL) {
				BST* temp = root->left;
				delete root;
				return temp;
			}

			//implement case where node has both childs
		}
		return root;

	}

	

	void InorderTraversal(BST* root) {
		if (root == NULL) {
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

	b.deleteNode(root, 60);
	b.InorderTraversal(root);
}