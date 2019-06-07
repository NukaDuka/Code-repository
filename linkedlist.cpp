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
Node<T> *createList(size_t listsize)
{
    Node<T> *prev = new Node<T>(nullptr);
    Node<T> *curr;
    size_t sz = listsize - 1;
    while (sz--)
    {
        curr = new Node<T>(prev);
        prev = curr;
    }

    return curr;
}

template<class T>
void deleteList(Node<T> **head)
{
    
    Node<T> *next = (*head)->next;
    while (true)
    {
        
        cout << "Deleted" << endl;
        delete(*head);
        *head = next;
        if (*head == nullptr) break;
        next = next->next;
    }

}
int main(void)
{
    Node<int> *test = createList<int>(10);
    Node<int> *temp = test;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    deleteList<int>(&test);
    return 0;
}