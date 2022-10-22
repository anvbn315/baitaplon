#include<iostream>

void BinaryTree::insertleft(Node * p, Item v){ 
if(p == NULL)
   cout<<"cannot insert to a NULL node.\n";
else if(p->left != NULL)
   cout<<"left chill existed.\n";
else
   p->left = createNode(v);
}
