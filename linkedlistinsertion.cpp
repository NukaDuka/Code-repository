#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <ios>
#include <iterator>
#include <inttypes.h>
#include <stack>
#include <cstdio>
#include <map>
#include <climits>
#include <cctype>
#include <sstream>
#include <queue>
#include <list>
#include <chrono>

using namespace std;

template<class T>
class Node
{
    public:
    Node(Node<T> *nxt, T dta)
    {
        this->next = nxt;
        this->data = dta;
    }

    Node(Node<T> *nxt)
    {
        this->next = nxt;
    }

    Node()
    {
        this->next = nullptr;
    }
    Node<T> *next;
    T data;
};

template<class T>
void insertHead(Node<T> **head, T data)
{
    Node<T> *node = new Node<T>();
    node->data = data;
    node->next = *head;
    *head = node;
}

template<class T>
void insertTail(Node<T> **head, T data)
{
    Node<T> *node = new Node<T>();
    node->data = data;
    if (*head == nullptr)
    {
        *head = node;
        return;
    }
    Node<T> *temp = *head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = node;  
}

template<class T>
void insertAfter(Node<T> *node, T data)
{
    Node<T> *newn = new Node<T>();
    newn->data = data;
    newn->next = node->next;
    node->next = newn; 
}

int main(void)
{
    Node<int> *head = new Node<int>();
    head->data = 1;
    insertHead<int>(&head, 0);
    cout << head->data << ' ' <<  head->next->data << endl;
    insertTail<int>(&head, 2);
    insertHead<int>(&head, -1);
    insertTail<int>(&head, 3);
    insertAfter((head->next->next), 54);
    Node<int> *temp = head;
    while (temp->next)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    return 0;
}