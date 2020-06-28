# A class for performing operations on a Binary Tree

Public Methods Provided are as follows

Default Constructor creates a Binary tree with root as empty.

```c++
BinaryTree();
```

Parametrized Constructor creates a binary tree with root node as formal parameter

```c++
BinaryTree(int data);
```

Creating a binary tree. Fetches user input for left and right nodes and create binary tree accordingly. Input "-1" for empty sub children

```C++
Node* create();
```

Tree Traversal

```c++
void preOrder(); //Recursive Preorder Traversal
void Preorder(); //Iterative Preorder Traversal

void inOrder();  //Recursive Inorder Traversal 
void Inorder();  //Iterative Inorder Traversal

void postOrder(); // Recursive Postorder Traversal
void Postorder(); // Iterative Postorder Traversal

void levelOrder(); //Iterative Level Order Traversal
```
Number Of Elements in the tree

```c++
int count();
```

Height Of Binary Tree

```c++
int height();
```

Generate Binary Tree from inorder and preorder traversal outputs

```c++
void generatefromtraversal(vector<int>& inorder, vector<int>& preorder);
```

