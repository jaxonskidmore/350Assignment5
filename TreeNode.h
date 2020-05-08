#include <iostream>
#include <stdexcept>
using namespace std;

template <class X>
class TreeNode{
public:
  TreeNode();
  TreeNode(int k, X v);
  //TreeNode(int k, <type> v); //key value constructor, int = key, v = value
  ~TreeNode();
  //Virtual ~TreeNode(); when working with a template class


  int key;
  X value;
  TreeNode *left;
  TreeNode *right;

};

template <class X>
TreeNode<X>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}

template <class X>
TreeNode<X>::TreeNode(int k, X v){
  value = v;
  key = k;
  left = NULL;
  right = NULL;
}
template <class X>
TreeNode<X>::~TreeNode(){

}
