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
void deleteAtValue(Node<T> **head, T val)
{
    Node<T> *temp = *head;
    if ((*head) != nullptr && (*head)->data == val)
    {
        *head = (*head)->next;
        delete(temp);
        return;
    }
    Node<T> *prev;
    while (temp && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        prev->next = temp->next;
        delete(temp);
    }
}

template<class T>
void deleteList(Node<T> **head)
{
    if (*head == nullptr) return;
    Node<T> *temp = *head;
    Node<T> *prev;
    while (temp)
    {
        prev = temp;
        temp = temp->next;
        delete(prev);
    }
}

int main(void)
{
    Node<int> *tail = new Node<int>(nullptr, 100);
    Node<int> *mid = new Node<int>(tail, 1000);
    Node<int> *head = new Node<int>(mid, 10000);
    
    deleteList<int>(&head);
    return 0;
}