#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include "node.h"
using namespace std;

template<class T>

class LinkedList
{
    Node<T> *head, *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void Add(T data)
    {
        Node<T> *node = new Node<T>(data);

        if(head == NULL)
        {
            head = tail = node;
        }
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void Display()
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            cout << current->data << "  ";
            current = current->next;
        }
    }

    void insertAfterIndex(int index, T data)
    {

        Node<T> *current = getNodeByIndex(index);

        Node<T> *newNode = new Node<T>(data) ;
        newNode->prev = current;
        current->next->prev = newNode;
        newNode->next = current->next;
        current->next = newNode;

    }

    void insertBeforeIndex(int index, T data)
    {
        Node<T> *current = getNodeByIndex(index);
        Node<T> *newNode = new Node<T>(data);

        if(index != 0 )
        {
            insertAfterIndex(index - 1, data);
        }
        else
        {
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head= newNode;

        }


    }

    void reverseList()
    {

        Node<T> *temp = NULL;
        Node<T> *current = head;

        while(current != NULL)
        {

            temp = current->prev ;
            current->prev = current->next;
            current->next = temp ;
            current = current->prev ;

        }


        if(temp != NULL)
        {
            head = temp->prev;
        }

    }

    int getListSize(){
     Node<T> *current = head;
     int _count = 0 ;
     while(current != NULL){
      ++_count;
     current = current->next;
     }
      return _count;
    }

     bool contains(T data){
     Node<T> *current = getNodeByData(data);

     return current != NULL;

     }
private:

    Node<T>* getNodeByData(T data)
    {

        Node<T> *current = head;

        while(current != NULL )
        {
            if(current->data == data)
            {
                return current ;
            }
            else
            {
                current = current->next;
            }
        }
        return NULL ;
    }

    Node<T>* getNodeByIndex(int index)
    {

        Node<T> *current = head;
        int _count = 0 ;

        while(current != NULL )
        {
            if(index == _count)
            {
                return current ;
            }
            else
            {
                current = current->next;
                ++_count;
            }
        }
        return NULL ;
    }
protected:
};

#endif // LINKED_LIST_H_INCLUDED
