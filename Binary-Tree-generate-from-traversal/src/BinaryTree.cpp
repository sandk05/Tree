#include <iomanip>
#include <queue>
#include <stack>
#include "BinaryTree.h"
using namespace std;
Node::Node(int k) 
{
	data = k;
	right = nullptr;
	left = nullptr;
}

BinaryTree::BinaryTree():root(nullptr) { }

BinaryTree::BinaryTree(int data)
{
	root = new Node(data);
}

Node* BinaryTree::create()
{
	queue<Node*> myqueue;
	Node* current, * newNode;
	if (root == nullptr)
	{
		int data;
		cout << "Enter Data For Root" << endl;
		cin >> data;
		root = new Node(data);
	}
	myqueue.push(root);
	while (!myqueue.empty())
	{
		current = myqueue.front();
		myqueue.pop();
		int ldata, rdata;
		cout << "Enter Data For Left and Right Child of " << current->data << endl;
		cin >> ldata >> rdata;
		if (ldata != -1)
		{
			newNode = new Node(ldata);
			current->left = newNode;
			myqueue.push(newNode);
		}
		if (rdata != -1)
		{
			newNode = new Node(rdata);
			current->right = newNode;
			myqueue.push(newNode);
		}
	}
	return root;
}


void BinaryTree::preOrder()
{
	return preorder(root);
}

void BinaryTree::Preorder()
{
	stack<Node*> mystack;
	Node* current = root;
	while (!mystack.empty() || current != nullptr)
	{
		if (current != nullptr)
		{
			cout << current->data << " ";
			mystack.push(current);
			current = current->left;
		}
		else {
			current = mystack.top(); mystack.pop();
			current = current->right;
		}
	}
}

void BinaryTree::Inorder()
{
	stack<Node*> mystack;
	Node* current = root;
	while (!mystack.empty() || current != nullptr)
	{
		if (current != nullptr)
		{
			mystack.push(current);
			current = current->left;
		}
		else {
			current = mystack.top(); mystack.pop();
			cout << current->data << " ";
			current = current->right;
		}
	}
}

void BinaryTree::inOrder()
{
	return inorder(root);
}

void BinaryTree::Postorder()
{
	stack<Node*> mystack, second;
	Node* current = root;
	mystack.push(current);
	while (!mystack.empty())
	{
		current = mystack.top(); mystack.pop();
		second.push(current);
		if (current->left)
		{
			mystack.push(current->left);
		}
		if (current->right)
		{
			mystack.push(current->right);
		}
	}
	while (!second.empty())
	{
		current = second.top(); second.pop();
		cout << current->data << " ";
	}
}

void BinaryTree::postOrder()
{
	return postorder(root);
}

void BinaryTree::levelOrder()
{
	return levelorder(root);
}

void BinaryTree::generatefromtraversal(vector<int>& inorder, vector<int>& preorder)
{
	root = generatefromtraversal(inorder, preorder, 0, inorder.size() - 1);
}

int BinaryTree::count()
{
	return count(root);
}

int BinaryTree::height()
{
	return height(root);
}

int BinaryTree::height(Node* current)
{
	if (current)
	{
		return max(height(current->left), height(current->right)) + 1;
	}
	return 0;
}

int BinaryTree::count(Node* current)
{
	int x, y;
	if (current)
	{
		x = count(current->left);
		y = count(current->right);
		return x + y + 1;
	}
	return 0;
}

void BinaryTree::preorder(Node* node)
{
	if (node)
	{
		cout << node->data << " ";
		if (node->left)  preorder(node->left);
		if (node->right) preorder(node->right);
	}
	return;
}

void BinaryTree::inorder(Node* node)
{
	if (node)
	{
		if (node->left)  inorder(node->left);
		cout << node->data << " ";
		if (node->right) inorder(node->right);
	}
	return;
}

void BinaryTree::postorder(Node* node)
{
	if (node)
	{
		if (node->left)  postorder(node->left);
		if (node->right) postorder(node->right);
		cout << node->data << " ";
	}
	return;
}

void BinaryTree::levelorder(Node* node)
{
	queue<Node*> myqueue;
	Node* current;
	myqueue.push(node);
	while (!myqueue.empty())
	{
		current = myqueue.front();
		myqueue.pop();
		cout << current->data << " ";
		if (current->left)
			myqueue.push(current->left);
		if (current->right)
			myqueue.push(current->right);
	}
	return;
}

int BinaryTree::splitIndex(vector<int>& inorder, int start, int end, int key)
{
	for (int i = start; i <= end; i++)
	{
		if (inorder[i] == key)
		{
			return i;
		}
	}
	return -1;
}

Node* BinaryTree::generatefromtraversal(vector<int>& inorder, vector<int>& preorder, int start, int end)
{
	static int preIndex = 0;
	int kIndex;
	if (start > end)
		return nullptr;
	Node* node = new Node(preorder[preIndex++]);

	if (start == end)
		return node;

	kIndex = splitIndex(inorder, start, end, node->data);
	node->left = generatefromtraversal(inorder, preorder, start, kIndex - 1);
	node->right = generatefromtraversal(inorder, preorder, kIndex + 1, end);
	return node;
}
