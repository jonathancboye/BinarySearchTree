#ifndef BST_CPP
#define BST_CPP

#include<iostream>
#include<iomanip>
#include<string>
#include<cassert>
#include<vector>

using namespace std;

template<typename T>
void BST<T>::insert(T node){
  if(find(node.getId())) return;
  Node<T>* n = new Node<T>(node);
  insertNode(root, n);
  ++size;
}

template<typename T>
void BST<T>::insertNode(Node<T>* &ptr,Node<T>* node){
  if(ptr == NULL){
    ptr = node;
    return;
  }
  else{
    node -> parent = ptr;
    if(node -> element < ptr -> element)
      insertNode(ptr -> leftChild, node);
    else 
      insertNode(ptr -> rightChild, node);
    }
}

template<typename T>
void BST<T>::printTree()const{
  if(root == NULL){
    cout << "EMPTY"<< endl;
    return;
  }
  preorder(root, 0);
  cout << endl;
}

template<typename T>
void BST<T>::preorder(Node<T>* ptr, int space)const{
  if(ptr == NULL){
    return;
  }
  string prompt = "> ";
  //Print something resembling a tree structure, fun to play with :)
  cout.width(space * 2 + 1 + prompt.length());
  cout.fill('-');
  cout << right << prompt;
  ptr -> element.printData();
  cout << " DEPTH: " << space << endl;
  preorder(ptr -> leftChild, space += 1);
  preorder(ptr -> rightChild, space);
}

template<typename T>
void BST<T>::search(int id){
  Node<T>* ptr = root;
  findElement(ptr, id);
  if(ptr == NULL)
    cout << "Could not find element in tree" << endl;
  else{
    ptr -> element.printData();
    cout << endl;
  }
}

template<typename T>
bool BST<T>::find(int id){
  Node<T>* ptr = root;
  findElement(ptr,id);
  if(ptr == NULL){
    return false;
  }
  else
  return true;
}

template<typename T>
vector<T> BST<T>::getElementList(){
  vector<T> array;
  Node<T> *ptr = root;
  getElements(ptr, array);
  return array;
}

template<typename T>
void BST<T>::getElements(Node<T> *ptr, vector<T> &array){
  if(ptr == NULL) return;
  else{
    array.push_back(ptr -> element);
    getElements(ptr -> leftChild, array);
    getElements(ptr -> rightChild, array);
  }
}
    
   
template<typename T>
void BST<T>::findElement(Node<T>* &ptr, int id){
  if(ptr == NULL || ptr -> element.getId() == id) return;
  else{
    if(id < ptr -> element.getId()){
      return findElement(ptr = ptr -> leftChild, id);
    }
    else
      return findElement(ptr = ptr -> rightChild, id);
  }
}
  
template<typename T>
void BST<T>::remove(int id){
  Node<T>* ptr = root;
  findElement(ptr, id);
  //Empty tree
  if(ptr == NULL){
    cout << "Could not find element" << endl;
    return;
  }
  //External node
  if(ptr -> leftChild == NULL && ptr -> rightChild == NULL){
    if(ptr == root) root = NULL;
    else getParentPtr(ptr) = NULL;
    delete ptr;
  }
  else{ //interal node
    Node<T>* tmp = ptr -> leftChild;
    //only a right child
    if(tmp == NULL){
      if(ptr == root) root = ptr -> rightChild;
      else getParentPtr(ptr) = ptr -> rightChild;
      delete ptr;
    }
    //only a left child
    else if(ptr -> rightChild == NULL){
      if(ptr == root) root = ptr -> leftChild;
      else getParentPtr(ptr) = ptr -> leftChild;
      delete ptr;
    }
    //Has two children
    else{
      for(;tmp -> rightChild != NULL;tmp=tmp->rightChild); //get max node in left subtree
      if(tmp -> leftChild != NULL) getParentPtr(tmp) = tmp -> leftChild;
      else getParentPtr(tmp) = NULL;
      ptr -> element = tmp -> element;
      delete tmp;
    }
  }
  --size;
}
    
template<typename T>
Node<T>*& BST<T>::getParentPtr(Node<T>* ptr){
  assert(ptr -> parent != NULL);
  if(ptr -> parent -> rightChild == ptr)
    return ptr -> parent -> rightChild;
  else
    return ptr -> parent -> leftChild;
}

template<typename T>
void BST<T>::clear(Node<T>* &ptr){
  if(ptr == NULL) return;
  else if(ptr -> parent == NULL){
    root = NULL;
    delete ptr;
  }
  else{
    clear(ptr -> leftChild);
    clear(ptr -> rightChild);
    getParentPtr(ptr) = NULL;
    delete ptr;
  }
}

#endif //BST_CPP
