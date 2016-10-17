#ifndef BST_H
#define BST_H
#include <cstdlib>
#include <vector>

//Node in a binary search tree
template<typename T>
struct Node{
  //constructor
Node(T element):element(element),leftChild(NULL),
    rightChild(NULL),parent(NULL){}

  T element;
  Node<T>* leftChild;
  Node<T>* rightChild;
  Node<T>* parent;
};

//Binary search tree
//Note: T must be of a type that overloads the < operator and
//must also have a printData() method
template<typename T>
class BST{
 public:
  
  //Constructor
 BST(): root(NULL), size(0){}

  //Destructor
  ~BST(){clear(root);}
  
  //Insert node into binary search tree
  void insert(T node);
 
  //Write tree to console
  void printTree()const;
  
  //Return true if employee
  //is found else false
  bool find(int id);
  
  //Print record to console
  void search(int id);

  //Remove record from tree
  void remove(int id);

  //Return the number of elements in tree
  int getSize()const{return size;}

  //Return the root node
  Node<T>*& getRoot(){return root;}

  //Return a list of elements in tree
  std::vector<T> getElementList();

  //Remove all nodes from tree
  void clear(Node<T>* &ptr);
  
 private:
 
  //Given a employeed id returns the employee
  //if not found returns null
  void findElement(Node<T>* &ptr, int id);

  //Return a list of elements in tree
  void getElements(Node<T> *ptr, std::vector<T> &array);

  //Insert node into binary tree
  void insertNode(Node<T>* &ptr, Node<T>* node);

  //Print out an in order traversal of the tree
  void preorder(Node<T>* ptr, int space)const;
  
  //Return pointer of parent node
  //asserts the parent is not null
  Node<T>*& getParentPtr(Node<T>* ptr); 
  
  Node<T>* root; //pointer to root of tree

  int size;
};

#include "BST.cpp"

#endif //BST_H
