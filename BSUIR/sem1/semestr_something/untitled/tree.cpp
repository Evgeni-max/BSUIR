#include "tree.h"

Tree::Tree(){

};
int Tree::height(Node*n)
{

    if (n!=nullptr) return n->h;
    else return 0;


}
int Tree::balance(Node *n)
{
    return height(n->left)-height(n->right);
}
Node *Tree::rot_right(Node* smth)
{
    if (smth == nullptr || smth->left == nullptr) return smth;
    Node *tmp=smth->left;
    Node *tmp_r=tmp->right;
    tmp->right=smth;
    smth->left=tmp_r;

    tmp->h= 1 + std::max(height(tmp->left), height(tmp->right));
    smth->h= 1 + std::max(height(smth->left), height(smth->right));
    return tmp;

}
Node* Tree::rot_left(Node* smth)
{
    if (smth == nullptr || smth->right == nullptr) return smth;
    Node *tmp=smth->right;
    Node *tmp_r=tmp->left;
    tmp->left=smth;
    smth->right=tmp_r;

    tmp->h= 1 + std::max(height(tmp->left), height(tmp->right));
    smth->h= 1 + std::max(height(smth->left), height(smth->right));
    return tmp;

}
Node* Tree::create(int key)
{
    Node*n=new Node;
    n->key=key;
    n->left=nullptr;
    n->right=nullptr;
    return n;
}

void Tree::insert(Node* &n,int key)
{
    if(n==nullptr)
    {
        n=create(key);

    }

    if (key < n->key) insert(n->left, key);
    else if (key > n->key) insert(n->right, key);
    else return;


    n->h=1+std::max(height(n->left),height(n->right));
    int bal=balance(n);

    if (n->left!=nullptr && bal > 1 && key < n->left->key){
        rot_right(n);
    }
    if (n->right!=nullptr && bal < -1 && key > n->right->key){
        rot_left(n);
    }
    if (n->left!=nullptr && bal> 1 && key > n->left->key) {
        n->left = rot_left(n->left);
        rot_right(n);
    }

    if (n->right!=nullptr && bal < -1 && key < n->right->key) {
        n->right = rot_right(n->right);
        rot_left(n);
    }





}
Node* Tree::fmin(Node *n)
{

    Node* curr = n;
    while (curr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;

}
std::string Tree::find(Node *n,int key)
{
    if(n==nullptr) return "dick";
    else
    {
        if(n->key==key) return "awesome balls";
        else if(n->key>=key) return find(n->left,key);
        else return find(n->right,key);
    }
}
Node* Tree::del(Node *n,int key)
{
    if(n==nullptr) throw;
    else
    {
        if(n->key==key){
            if (n->left == nullptr) {
                Node* tmp = n->right;
                delete n;
                return n;
            } else if (n->right == nullptr) {
                Node* temp = n->left;
                delete n;
                return temp;
            }
            Node* temp = fmin(n->right);

            n->key = temp->key;


            n->right = del(n->right, n->key);
        }
        if(n->key>=key) return del(n->left,key);
        if(n->key<=key) return del(n->right,key);
    }
    throw;
}
void Tree::pr_ord(Node *n)
{
    if (n != nullptr) {
        std::pair <std::string,int> p1;

        p1.second=n->key;
        pair1.push_back(p1);
        pr_ord(n->left);
        pr_ord(n->right);
    }
}
void Tree::p_ord(Node *n)
{
    if (n != nullptr) {
        p_ord(n->left);
        p_ord(n->right);
        std::pair <std::string,int> p1;

        p1.second=n->key;
        pair2.push_back(p1);
    }
}
void Tree::in_ord(Node *n)
{
    if (n != nullptr) {
        in_ord(n->left);
        std::pair <std::string,int> p1;

        p1.second=n->key;
        pair3.push_back(p1);
        in_ord(n->right);
    }
}
Node* Tree::n1()
{
    return n2;
}
void Tree::ins(int key)
{
    if (find(n2,key) != "awesome balls") insert(n2,key);
}
void Tree::count()
{

    if (n2 == nullptr) return;

    std::queue<Node*> q;
    q.push(n2);

    int level = 0;
    while (!q.empty()) {
        int nodeCount = q.size();

        while (nodeCount > 0) {
            Node* node = q.front();
            q.pop();

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);

            nodeCount--;
        }

        level++;
    }

}
std::vector <std::string> Tree::ret()
{
    return l;
}
