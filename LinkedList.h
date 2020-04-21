#ifndef __LINKEDLIST__
#define __LINKEDLIST__
#include <string>
#include <iostream>
using namespace std;

template <class T>
class Node{
        public:
                T data;
                Node *link;
                Node(T element){
                        data = element;
                        link = 0;
                }
};

template <class T>
class LinkedList{
        protected:
                Node<T> *first;
                int current_size;
        public:
                LinkedList(){
                        first = 0;
                        current_size = 0;
                }
                int GetSize(){
                        return current_size;
                }
                void Insert(T element){
                        Node<T> *newnode = new Node<T>(element);
                        newnode->link = first;
                        first = newnode;
                        current_size++;
                }
                virtual bool Delete(T &element){
                        if (first == 0){
                                return false;
                        }
                        Node<T> *current = first, *previous = 0;

                        while(1){
                                if (current->link == 0){
                                        if (previous) previous->link = current->link;
                                        else first = first->link;
                                        break;
                                }
                                previous = current;
                                current = current->link;
                        }
                        element = current->data;
                        delete current;
                        current_size--;

                        return true;
                }
                void Print(){
                        Node<T>* m;
                        int i = 1;
                        if (current_size == 0){
                                return;
                        }        
                        if (current_size != 0){
                                for (m = first; m != NULL; m = m->link){
                                        if (i == current_size){
                                                cout << "[" << i << "|";
                                                cout << m->data << "]";
                                        }
                                        else {
                                                cout << "[" << i << "|";
                                                cout << m->data << "]->";
                                                i++;
                                        }
                                }
                                cout << endl;
                        }
                }
};
#endif
