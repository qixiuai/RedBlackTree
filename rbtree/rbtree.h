
#include <iostream>

namespace dsa {

  // data structure that represents a node in the tree
  struct Node {
    int data; // holds the key
    Node *parent; // pointer to the parent
    Node *left; // pointer to left child
    Node *right; // pointer to right child
    int color; // 1 -> Red, 0 -> Black # TODO enum Color {RED, BLACK}
  };

  typedef Node* NodePtr;

  class RBTree {
  private:
    NodePtr root;
    NodePtr TNULL;

    void initializeNULLNode(NodePtr node, NodePtr parent);
    void preOrderHelper(NodePtr node);
    void inOrderHelper(NodePtr node);
    void postOrderHelper(NodePtr node);
    
    NodePtr searchTreeHelper(NodePtr node, int key);
    
    void fixDelete(NodePtr x);
    void rbTransplant(NodePtr u, NodePtr v);
    void deleteNodeHelper(NodePtr node, int key);
    void fixInsert(NodePtr k);

    void printHelper(NodePtr root, std::string indent, bool last);

  public:
    RBTree() {
      TNULL = new Node;
      TNULL->color = 0;
      TNULL->left = nullptr;
      TNULL->right = nullptr;
      root = TNULL;
    }

    void preorder() {
      preOrderHelper(this->root);
    }

    // In-Order traversal
    // Left Subtree -> Node -> Right Subtree
    void inorder() {
      inOrderHelper(this->root);
    }

    // Post-Order traversal
    // Left Subtree -> Right Subtree -> Node
    void postorder() {
      postOrderHelper(this->root);
    }

    // search the tree for the key k
    // and return the corresponding node
    NodePtr searchTree(int k) {
      return searchTreeHelper(this->root, k);
    }

    // find the node with the minimum key
    NodePtr minimum(NodePtr node) {
      while (node->left != TNULL) {
	node = node->left;
      }
      return node;
    }

    // find the node with the maximum key
    NodePtr maximum(NodePtr node) {
      while (node->right != TNULL) {
	node = node->right;
      }
      return node;
    }

    // find the successor of a given node
    NodePtr successor(NodePtr x);

    // find the predecessor of a given node
    NodePtr predecessor(NodePtr x);
    // rotate left at node x
    void leftRotate(NodePtr x);

    // rotate right at node x
    void rightRotate(NodePtr x);

    // insert the key to the tree in its appropriate position
    // and fix the tree
    void insert(int key);

    NodePtr getRoot(){
      return this->root;
    }

    // delete the node from the tree
    void deleteNode(int data) {
      deleteNodeHelper(this->root, data);
    }

    // print the tree structure on the screen
    void prettyPrint() {
      if (root) {
	printHelper(this->root, "", true);
      }
    }

  };

}
