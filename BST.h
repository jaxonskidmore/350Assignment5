#include <iostream>
#include <stdexcept>
#include "TreeNode.h"
#include "Student.h"
using namespace std;

template <class X>
class BST{
  public:
    BST();
    ~BST();
    //virtual ~BST() when working with template classes

    void insert(int key, X value); // also our key
    bool search(int key);
    bool deleteNode(int k);


    bool isEmpty();
    TreeNode<X>* getMin();
    TreeNode<X>* getMax();

    TreeNode<X>* getSuccessor(TreeNode<X> *d);
    void printTree(TreeNode<X> *node);

    void printSingleNode(int key);

    TreeNode<X> *root;
};

template <class X>
BST<X>::BST(){
  root = NULL; //empty tree
}

template <class X>
BST<X>::~BST(){

}
template <class X>
void BST<X>::printTree(TreeNode<X> *node){
  if(node == NULL)
    return;
  printTree(node->left);
  node->value.printInfo();
  //cout << node.printInfo() << endl;
  printTree(node->right);
}

template <class X>
TreeNode<X>* BST<X>::getMax(){
  TreeNode<X> *curr = root;

  if(root == NULL){
    return NULL;
  }
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}

template <class X>
bool BST<X>::isEmpty(){
  return (root == NULL);
}

template <class X>
void BST<X>::insert(int key, X value){
  TreeNode<X> *node = new TreeNode<X>(key, value);

  if(isEmpty()){
    //empty TreeNode
    root = node;
  }
  else{
    //not empty TreeNode
    TreeNode<X> *curr = root; //start at the root
    TreeNode<X> *parent;

    while(true){
      parent = curr;
      if(key < curr->key){
        //go left
        curr = curr->left;
        if(curr == NULL){
          parent->left = node;
        }
      }
      else{
        //go right
        curr = curr->right;
        if(curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}
template <class X>
bool BST<X>::search(int value) {
  if(isEmpty())
    return false;
  else {
    //its not an empty tree
    TreeNode<X> *current = root;

    while(current->key != value) {

      if(value < current->key)
        current = current->left;
      else
        current = current->right;

      if(current == NULL) //we didnt find value
        return false;

    }
  }
  return true;
}
template <class X>
bool BST<X>::deleteNode(int k){

  if(isEmpty())
    return false;

  TreeNode<X> *parent = root;
  TreeNode<X> *current = root;
  bool isLeft = true;
  //when isLeft is false then its right

  while(current->key != k)
  {
    parent = current;
    if(k < current->key) {
      isLeft = true;
      current = current->left;
    }
    else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL) // we didnt find value
      return false;
  }
  //if we make it here we found the value now delete
  if(current->left == NULL && current->right == NULL) {
    //then we have a leaf TreeNode
    //have to determine if left or right and if root nodee
    if(current == root)
      root = NULL;
    else if (isLeft)
      parent->left = NULL;
    else
      parent->right = NULL;

  }
  else if(current->right == NULL) //no right child, so must have left child
  {
    if(current == root)
      root = current->left;
    else if(isLeft)
      parent->left = current->left;
    else
      parent->right = current->left;
      //node we are deleting has a child thats a left child
      //this else if determines position of node to be deleted
  }
  else if(current->left == NULL) //no right child, so must have left child
  {
    //these branching statements identify position of node to be deleted
    if(current == root)
      root = current->left;
    else if(isLeft)
      parent->left = current->right;
    else
      parent->right = current->right;
      //node we are deleting has a child thats a left child
   }
   else{
     //the node to be deleted has two children
     //at this point we being to cry and bang our heads while listening to music

     TreeNode<X> *successor = getSuccessor(current);

     if(current == root)
       root = successor;
     else if (isLeft)
       parent->left = successor;
     else
       parent->right = successor;

     //connect/link successor to current's (D) left child
     successor->left = current->left;

     return true;

   }

}
template <class X>
TreeNode<X>* BST<X>::getSuccessor(TreeNode<X> *d) {
  //the parameter d represents the node to be deleted
  TreeNode<X> *current = d->right;
  TreeNode<X> *sp = d; //successor parent
  TreeNode<X> *successor = d;

  while(current != NULL) {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template <class X>
void BST<X>::printSingleNode(int key){ //used in database
  /*if(isEmpty())
    return NULL;
  else { */
    //its not an empty tree
    TreeNode<X> *current = root;

    while(current->key != key) {
      try{
        if(key < current->key)
          current = current->left;
        else
          current = current->right;

        if(current == NULL) //we didnt find value
          throw 99;
      }catch(int x){
        cout << "there is no matching value for that key" << endl;
      }
    } //break out while becasuse current.key = key
      current->value.printInfo();

}
