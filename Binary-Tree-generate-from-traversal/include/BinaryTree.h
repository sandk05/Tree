#ifndef _BINARYTREE_
#define _BINARYTREE_
#include <iostream>
#include <vector>
using namespace std;
class Node {
private:

public:
	Node* left;
	int data;
	Node* right;
	Node(int k);
};
class BinaryTree
{
private:
	Node* root;
public:
	BinaryTree();
	BinaryTree(int data);
	

	Node* create();
	
	void preOrder(); //Recursive Preorder Traversal
	void Preorder(); //Iterative Preorder Traversal
	
	void inOrder();  //Recursive Inorder Traversal 
	void Inorder();  //Iterative Inorder Traversal

	void postOrder(); // Recursive Postorder Traversal
	void Postorder(); // Iterative Postorder Traversal
	
	void levelOrder(); //Iterative Level Order Traversal
	
	void generatefromtraversal(vector<int>& inorder, vector<int>& preorder);
	int count();
	int height();

private:
	void preorder(Node* node);
	void inorder(Node* node);
	void postorder(Node* node);
	void levelorder(Node* node);

	int height(Node* current);
	int count(Node* current);
	int splitIndex(vector<int>& inorder, int start, int end, int key);
	Node* generatefromtraversal(vector<int>& inorder, vector<int>& preorder, int start, int end);
};
#endif