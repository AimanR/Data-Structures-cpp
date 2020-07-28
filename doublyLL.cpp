/*
Author : Aiman Rafeed

This code implements the doubly linked lists (DLLs). The 'doublist'
class models such a list. Some important methods like adding an element at
a particular index or removing from a particular index are yet to be
added.

The idea of this implementation is taken from DS tutorials of William
Fiset at youtube. Java implementation of this code can be found from
his repository.

Python implementations and other C++ implementations are also available
elsewhere.

*/

#include <iostream>

using namespace std;

class doublist
{
    //internal class : node
    class node
    {
    public:
        int data;
        node *prev, *next;
        node(int dat, node *prv, node *nxt)
        {
            this->data = dat;
            this->prev = prv;
            this->next = nxt;
        }
    };

    node *head, *tail;
    int SIZE;

    public:
        // Constructor
        doublist()
        {
            head = nullptr;
            tail = nullptr;
            SIZE = 0;
        }
        // Clears the list, O(n)
        void makeEmpty()
        {
            node *curr = head;
            while(curr!=nullptr)
            {
                node *temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = tail = nullptr;
            SIZE = 0;
            // delete curr;
        }

        // returns the size, O(1)
        int len()
        {
            return SIZE;
        }

        // Checks if empty, O(1)
        bool isEmpty()
        {
            return SIZE==0;
        }

        // Adds an element at front, O(1)
        void addFirst(int elem)
        {
            if(SIZE==0)
                head = tail = new node(elem, nullptr, nullptr);
            else
            {
                head->prev = new node(elem, nullptr, head);
                head = head->prev;
            }
            SIZE++;
        }

        // Adds an element at back, O(1)
        void addLast(int elem)
        {
            if(SIZE==0)
                head = tail = new node(elem, nullptr, nullptr);
            else
            {
                tail->next = new node(elem, tail, nullptr);
                tail = tail->next;
            }
            SIZE++;
        }

        // returns the first element, O(1)
        int peekFirst()
        {
            if (SIZE==0) cout << "ERROR : NO FIRST ELEMENT TO BE PEEKED.\n";
            return head->data;

        }

        // returns the last element, O(1)
        int peekLast()
        {
            if (SIZE==0) cout << "ERROR : NO LAST ELEMENT TO BE PEEKED.\n";
            return tail->data;

        }

        // Removes the first element, O(1)
        int remFirst()
        {
            if (SIZE==0) cout << "ERROR : NO FIRST ELEMENT TO BE REMOVED.\n";

            int firstElem = head->data;
            head = head->next;
            SIZE--;

            if (SIZE==0) delete tail;
            else delete head->prev;

            return firstElem;
        }


        // Removes the last element, O(1)
        int remLast()
        {
            if (SIZE==0) cout << "ERROR : NO LAST ELEMENT TO BE REMOVED.\n";

            int lastElem = tail->data;
            tail = tail->prev;
            SIZE--;

            if (SIZE==0) delete head;
            else delete tail->next;

            return lastElem;
        }

        // Prints the list, O(n)
        void print()
        {
            node *curr = head;
            while(curr)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
            delete curr;
            cout << "\n";
        }

};

int main()
{
    return 0;
}
