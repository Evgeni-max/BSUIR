#ifndef NEWTREE_H
#define NEWTREE_H
#include "node.h"
#include"string"
#include "vector"
#include <queue>
class nTree
{
public:
    nTree();
    void insert(Node*&,int);
    Node* create(int);
    int height(Node*);
    int balance(Node *);
    Node* rot_right(Node*);
    Node* rot_left(Node*);
    std::string find (Node*,int);
    Node* del(Node*,int);
    Node *fmin(Node *);
    void pr_ord(Node* );
    void p_ord(Node*);
    void in_ord(Node *n);
    std::vector< std::pair <std::string,int>> pair1;
    std::vector< std::pair <std::string,int>> pair2;
    std::vector< std::pair <std::string,int>> pair3;
    Node* n1();
    void ins(int);
    void count();
    std::vector <std::string> ret();
private :
    int h;
    Node *n2=nullptr;
    std::vector <std::string> l;
    int global =0;

};

#endif // NEWTREE_H
