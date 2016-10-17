#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee{
 public:

  //Default constructor
 Employee():lastName(""),firstName(""),employeeId(-1){}

  //constructor
 Employee(std::string last, std::string first, int id):
  lastName(last),firstName(first),employeeId(id){}

  void operator=(const Employee& e){
    if(this == &e) return;
    lastName = e.lastName;
    firstName = e.firstName;
    employeeId = e.employeeId;
  }

  //Return first name
  std::string getFirstName(){return firstName;}

  //Return last name
  std::string getLastName(){return lastName;}

  //Return employee id
  int getId(){return employeeId;}

  //Prints Employee information
  void printData(){
    std::cout << "Last: " <<lastName << " ";
    std::cout << "First: "<<firstName << " ";
    std::cout << "EID: " << employeeId;
  }

  //Returns true if employee id is greater than
  //another employeeid else false
  bool operator<(const Employee& rhs){return employeeId < rhs.employeeId;}
  
 private:
  std::string lastName;
  std::string firstName;
  int employeeId;
};

#endif //EMPLOYEE_H



