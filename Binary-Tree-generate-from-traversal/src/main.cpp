#include <iomanip>
#include "BinaryTree.h"
using namespace std;




int main()
{
	/*BinaryTree Bt;
	Bt.create();
	Bt.inOrder();
	cout<<endl;
	Bt.preOrder();
	cout<<endl;
	Bt.postOrder();
	cout<<endl;
	Bt.levelOrder();
	cout <<endl;*/

	//BinaryTree Bt1(4);
	//Bt1.create();
	//Bt1.preOrder();
	//cout<<endl<<"-----------------------" <<endl;
	//Bt1.Preorder();
	//Bt1.inOrder();
	//cout<<endl<<"-----------------------" <<endl;
	//Bt1.Inorder();
	//Bt1.postOrder();
	//cout<<endl<<"-----------------------" <<endl;
	//Bt1.Postorder();

	int VV[9] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
	vector<int> preorder(9);
	preorder.assign(&VV[0], &VV[0]+9);
	int VW[9] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
	vector<int> inorder(9) ;
	inorder.assign(&VW[0], &VW[0]+9);

	BinaryTree nBT;
	nBT.generatefromtraversal(inorder, preorder);
	cout<<"Post Order " ;
	nBT.Postorder();
	cout <<endl;
	cout<<"In Order ";
	nBT.inOrder();
	cout <<endl;
	cout<<"Pre Order ";
	nBT.Preorder();
	cout <<endl;
	cout <<nBT.count() <<endl;
	cout <<nBT.height() <<endl;
	return 0;
}