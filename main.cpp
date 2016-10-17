#include "BST.h"
#include "employee.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

//Place employee objects froma data base into a tree
//dataBase: a data base with entries in format "LASTNAME FIRSTNAME ID"
//One record per line
void buildTree(BST<Employee> &tree, string dataBase, int numElements=-1);  

//save tree to file
void saveTree(BST<Employee> &tree, string fileName);

//Creates a new Employee record to insert into data base
void createNewRecord(BST<Employee> &tree);

//Delete a Employee from tree
void deleteRecord(BST<Employee> &tree);

//Returns a valid Employee id
int getValidId();

int main(){
  BST<Employee> tree;
  char menuOption;
  string newline;
  while(true){
    cout << "####################" << endl;
    cout << "#       MENU       #" << endl;
    cout << "####################" << endl;
    cout << "(C)reate Binary Search Tree" << endl;
    cout << "(P)rint Tree" << endl;
    cout << "(I)nsert new record" << endl;
    cout << "(D)elete record" << endl;
    cout << "(E)mployee ID search" << endl;
    cout << "(S)ave database to a file" << endl;
    cout << "(Q)uit" <<endl;
    cout << endl;
    cout << "Enter choice: ";
    cin >> menuOption;
    getline(cin, newline);
    cout << endl;
    switch(menuOption){
    case 'C':
      buildTree(tree,"Employee-Database.txt", -1);
      break;
    case 'P':
      tree.printTree();
      cout << endl;
      break;
    case 'I':
      createNewRecord(tree);
      cout << endl;
      break;
    case 'D':
      tree.remove(getValidId());
      cout << endl;
      break;
    case 'E':
      tree.search(getValidId());
      cout << endl;
      break;
    case 'S':
      saveTree(tree, "saved_DataBase.txt");
      break;
    case 'Q':
      return EXIT_SUCCESS;
    default:
      cout << "Please select a valid option" << endl;
    }
  }
  return EXIT_SUCCESS;
}

void buildTree(BST<Employee> &tree, string dataBase, int numElements){
  size_t space1,space2;
  string data, first, last;
  int id;
  ifstream ifs;
  bool done = false;
  
  ifs.open(dataBase.c_str());
  if(!ifs.fail()){
    try{
      while(getline(ifs, data) && numElements != 0){
	space1 = data.find(' ');
	space2 = data.find(' ', space1 + 1);
	last = data.substr(0,space1);
	first = data.substr(space1 + 1, space2 - space1 - 1);
	id = atoi(data.substr(space2 + 1).c_str());
	Employee e(last,first,id);
	tree.insert(e);
	if(!(numElements == -1)) --numElements;
      }
    }
    catch(...){
      cout << "Problem Reading in file" << endl;
    }
    ifs.close();
  }
  else{
    cout << "Failded to open file" << endl;
  }
}
  
  
void createNewRecord(BST<Employee> &tree){
  string first, last;
  cout << "ENTER A NEW RECORD" << endl;
  cout << "Enter first name: ";
  getline(cin, first);
  cout << "Enter last name: ";
  getline(cin, last);
  Employee e(last,first,getValidId());
  tree.insert(e);
}

int getValidId(){
  string ID;
  int id;
  bool done = false;
  while(!done){
    cout << "Enter employee ID: ";
    getline(cin,ID);
    id = atoi(ID.c_str());
    if(0 < id && id < 10000000) done = true;
    else cout << "Please enter a valid ID number" << endl;
  }
  return id;
}

void saveTree(BST<Employee> &tree, string fileName){
  Employee e;
  ofstream ofs;
  vector<Employee> l = tree.getElementList();

  ofs.open(fileName.c_str());
  for(int i=0; i < l.size();++i){
    e = l[i];
    ofs << e.getLastName()
	<< " "
	<<e.getFirstName()
	<< " "
	<< e.getId()
	<< endl;
  }
  ofs.close();
}
