#include <iostream>
#include <cstddef>
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  
    void preOrder(Node *root) {

          if( root == NULL )
              return;

          std::cout << root->data << " ";

          preOrder(root->left);
          preOrder(root->right);
      }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/



    Node * insert(Node * root, int data) {
Node *node2 = (Node*)(malloc(sizeof(Node)));
            node2 = root;
            if(root==nullptr)
        {
            Node *node1 = (Node*)(malloc(sizeof(Node)));
            node1->data = data;
            root=node1;
        }
        else
        {
            if(node2->data>data)
            {
                if(node2->left==nullptr)
                {
                    Node *node1 = (Node*)(malloc(sizeof(Node)));
            node1->data = data;
            node2->left=node1;
                }
                else
                insert(node2->left,data);
            }
            else if(node2->data<data)
            {
                if(node2->right==nullptr)
                {
                   Node *node1 = (Node*)(malloc(sizeof(Node)));
            node1->data = data;
            node2->right=node1; 
                }
                else
                insert(node2->right,data);
            }
        }
        return root;
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
	myTree.preOrder(root);
    return 0;
}
