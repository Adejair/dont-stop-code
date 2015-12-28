//

#include <iostream>
#include "../C++/linkedList.h"

using namespace std;

typedef struct Staff {
  char* name;
  int age;
} Staff;


int main() {
  // Numbers

  Node<int>* numbers = new Node<int>;
  numbers->createList();

  numbers->pushBackList(10);
  numbers->pushFrontList(5);
  numbers->pushBackList(20);

  numbers->showList();

  numbers->destroyList();

  // Using with struct

  Node<Staff>* membersStaff = new Node<Staff>;
  membersStaff->createList();

  Staff myCompany[] = {{"Adejair Júnior", 69}, {"Mr Thug", 157}};

  for(int i = 0; i != (sizeof(myCompany) / sizeof (Staff)); ++i)
    membersStaff->pushBackList(myCompany[i]);

    Node<Staff>* aux = *(membersStaff->getHead());

    while(aux != NULL) {
      cout << "NAME: " << aux->data.name << " AGE: " << aux->data.age << endl;
      aux = aux->next;
    }

    cout << "SIZE: " << membersStaff->getSize() << endl;

    membersStaff->destroyList();
}
