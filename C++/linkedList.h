/*
  The MIT License (MIT)

  Copyright (c) 2015 Adejair Júnior

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

template<class A>
class Node {
public:
    /*
      Responsible for loading id of list and your first element.
    */
    Node<A>** linkedList;
    /*
      Next node of the list.
    */
    Node<A>* next;
    /*
      Value of the list.
    */
    A data;
    /*
      Total length of the list.
    */
    int size;

    // Prototype functions
    Node<A>** createList(void);
    Node<A>** getHead();
    void destroyList();

    int pushBackList(A);
    int pushFrontList(A);

    int popList(A);

    int getSize();
    int getPos(int);

    void showList();
};

/*
  Function responsible for create list.
*/
template<class A>
Node<A>** Node<A>::createList(void) {
    linkedList = new Node<A>*;

    if(linkedList != NULL)
      *linkedList = NULL;
    return linkedList;
}

/*
  Get Head of Node.
*/
template<class A>
Node<A>** Node<A>::getHead(void) {
  return linkedList;
}

/*
  Function that will destroy the list.
*/
template<class A>
void Node<A>::destroyList() {
  if(linkedList != NULL) {
    Node<A>* node;

    while((*linkedList)->next != NULL) {
      node = (*linkedList);
      *linkedList = (*linkedList)->next;
      delete node;
    }
    delete linkedList;
  }
}

/*
  Insert the end of the beginning
*/
template<class A>
int Node<A>::pushBackList(A value) {
  Node<A>* node = new Node<A>;

  if(node == NULL || linkedList == NULL)
    return 0;

  node->next = NULL;
  node->data = value;

  if(*linkedList == NULL)
    *linkedList = node;
  else {
    Node<A>* head = (*linkedList);
    while(head->next != NULL)
      head = head->next;
    head->next = node;
  }
  ++size;
}

/*
  Inserts on the list start
*/
template<class A>
int Node<A>::pushFrontList(A value) {
  Node<A>* node = new Node<A>;

  if(node == NULL || linkedList == NULL)
    return 0;

  node->data = value;
  node->next = (*linkedList);

  *linkedList = node;
  ++size;
}


/*
  Get total length of the list.
*/
template<class A>
int Node<A>::getSize(void) {
  return linkedList == NULL ? -1 : size;
}

/*
  Get position an element of list.
*/
template<class A>
int Node<A>::getPos(int value) {
  Node<A>* node = (*linkedList);
  int aux = 0;

  while(node != NULL && node->data != value) {
    ++aux;
    node = node->next;
  }
  return aux;
}

/*
  Print in screen all values(data) of list.
*/
template<class A>
void Node<A>::showList(void) {
  Node<A>* node = (*linkedList);

  while(node != NULL) {
    std::cout << node->data << std::endl;
    node = node->next;
  }
}


/*
  Remove certain value of list.
*/
template<class A>
int Node<A>::popList(A value) {
  Node<A>* node = (*linkedList);
  Node<A>* prev;

  while(node != NULL && node->data != value) {
    prev = node;
    node = node->next;
  }

  if(node == (*linkedList))
    *linkedList = node->next;
  else
    prev->next = node->next;

  delete node;
}
