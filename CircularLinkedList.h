#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include "DataType.h"

struct NodeType{
  DataType data;
  NodeType* next;
  //NodeType* predLoc;
};

class CircularLinkedList{

 public:
  CircularLinkedList();
  ~CircularLinkedList();
  void insertItem(DataType &item);
  void deleteItem(DataType &item);
  int lengthIs() const;
  void print();

 private:
  int length;
  NodeType* head;

};

#endif
