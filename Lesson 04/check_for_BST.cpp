/* PROBLEM
 * Given a binary tree, return true if it is BST, else false.
 * Input:
 * The task is to complete the method which takes one argument, root of Binary Tree.
 * The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
 * There are multiple test cases. For each test case, this method will be called individually.
 * Output:
 * The function should return 1 if BST else return 0.
 * SOURCE: https://practice.geeksforgeeks.org/problems/check-for-bst/1
 *
 * SOLUTION
 * Il problema richiede solo di scrivere la funzione isBST.
 * L'algoritmo visita l'albero ricordandosi il massimo e il minimo visti fino a quel punto.
 * Se il nodo in questione rispetta le regole del BST allora itera la ricerca sui figli, altrimenti ritorna 0.
 * Diciamo che n=numero di nodi.
 * COMPLEXITY: O(n)
 */

#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}



const int MIN = 0;
const int MAX = 1001;
   
int isBSTUtil(struct Node* node, int min, int max) {
	if (node==NULL) return 1;
	if (node->data < min || node->data > max) return 0;
	bool isLeftBST = isBSTUtil(node->left,min,node->data);
	bool isRightBST = isBSTUtil(node->right,node->data,max);
	return isLeftBST * isRightBST;
}
   
bool isBST(Node* root) {
	return isBSTUtil(root,MIN,MAX);
}
