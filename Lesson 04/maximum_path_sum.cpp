/* Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
 * Input:
 * First line consists of T test cases. First line of every test case consists of N, denoting number of nodes. Second line of every test case consists of N Spaced 3 elements, Parent node data, child node data and position of child node( 'L'  or  'R' ).
 * Output:
 * Return the Maximum possible sum.
 * SOURCE: https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
 */

#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
};
Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int maxPathSum(struct Node *root);
void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return ;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
					break;
			case 'R':root->right=newNode(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right)
;}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
							break;
					case 'R':root->right=newNode(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		//inorder(root);
		//cout<<endl;
		cout<<maxPathSum(root)<<endl;		
	}
}

int maxPath;
int maxSon(struct Node *root) {
	if (root->left==NULL) {
		if (root->right==NULL) return root->data;
		else return root->data + maxSon(root->right);
	}
	else {
		if (root->right==NULL) return root->data + maxSon(root->left);
		else {
			int maxLeft = maxSon(root->left);
			int maxRight = maxSon(root->right);
			int newMaxPath = maxLeft+maxRight+root->data;
			if (newMaxPath > maxPath) maxPath = newMaxPath;
			return max(maxLeft,maxRight) + root->data;
		}
	}
}
int maxPathSum(struct Node *root) {
	maxPath=-1000000;
	maxSon(root);
	return maxPath;
}
