#include<iostream>
using namespace std;
//assume it is a complete tree
struct Node{
    int val;
    Node *leftchild;
    Node *rightchild;
    Node *next;
    Node(int x): val(x), leftchild(NULL), rightchild(NULL), next(NULL){};
};

void connect(Node *p)
{
    if(!p)
        return;
    if(p->leftchild)
        p->leftchild->next = p->rightchild;
    if(p->rightchild)
        p->rightchild->next = p->next?p->next->leftchild:NULL;

    connect(p->leftchild);
    connect(p->rightchild);
}

int main()
{
    Node *p = new Node(1);
    Node *n1 = new Node(2);
    Node *n2 = new Node(3);
    p->leftchild = n1;
    p->rightchild = n2;
    Node *n3 = new Node(4);
    Node *n4 = new Node(5);

    connect(p);
}
