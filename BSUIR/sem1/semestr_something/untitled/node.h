#ifndef NODE_H
#define NODE_H
#include <string>
struct Node
{
    std::string val;
    int key;
    Node *right=nullptr;
    Node *left=nullptr;
    int h=1;
};
#endif // NODE_H
