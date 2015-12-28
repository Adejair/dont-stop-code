/*
  Adejair Júnior <adejair.junioroulook@gmai.com>
  # Tests C++/linkedList.h
  # OBS: use -std=c++11 to compile this.
*/

#include <iostream>
#include "../C++/linkedList.h"

using namespace std;

typedef struct Staff {
  char* name;
  int age;
} Staff;


int main() {
  // Numbers

  Node<int>* numbers = new Node<int>({10, 5, 15});
  numbers->showList();

  numbers->destroyList();

  // Using with struct

  Node<Staff>* membersStaff = new Node<Staff>({{"Adejair Júnior", 69}, {"Mr Thug", 157}});

  Node<Staff>* aux = *(membersStaff->getHead());

  while(aux != NULL) {
    cout << "NAME: " << aux->data.name << " AGE: " << aux->data.age << endl;
    aux = aux->next;
  }

  cout << "SIZE: " << membersStaff->getSize() << endl;

  membersStaff->destroyList();




}
