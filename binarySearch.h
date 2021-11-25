#include <iostream>
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

/*
    Isaias Zamora
    izamora@pengo.cabrillo.edu
    Preffered email: Leezam01@gmail.com
    binarySearch.h
    assingment name: Binary search tree, assignment number: 7
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(int data, Node *left, Node *right, Node *parent)
    {
        this->data = data;
        this->right = right;
        this->left = left;
        this->parent = parent;
    }
};

class BinarySearch
{
public:
    BinarySearch() : root(nullptr) {}
    ~BinarySearch();
    void insert(int num);
    void min();
    void max();
    void search(int key);
    void remove(int key);
    void inorder();
    void postorder();
    void preorder();
    void successor(int key);
    void predecessor(int key);

private:
    Node *root;
    void _inorder(Node* x);
    void _preorder(Node* x);
    void _postorder(Node* x);
    Node* _max(Node*);
    Node* _min(Node*);
    Node* _successor(Node*);
    Node* _predecessor(Node*);
    void _remove(Node*);
    Node* _search(Node*, int key);
    void destroyNode(Node*);
};

BinarySearch::~BinarySearch()
{
    destroyNode(root);
}

void BinarySearch::insert(int k)
{
    Node *n = new Node(k, nullptr, nullptr, nullptr);
    Node *parent = nullptr;
    Node *temp = root;
    while (temp != nullptr)
    {
        parent = temp;
        if (k < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    n->parent = parent;
    if (parent == nullptr)
    {
        root = n;
        std::cout << "inserted " << root->data << std::endl;
        return;
    }
    if (n->data < parent->data)
        parent->left = n;
    else
        parent->right = n;
    std::cout << "inserted " << n->data << std::endl;
}

void BinarySearch::_remove(Node* node)
{
    Node* temp = nullptr;
    Node* target = nullptr;
    if(node->left == nullptr || node->right == nullptr)
        target = node;
    else 
        target = _successor(node);
    if(target->left != nullptr)
        temp = target->left;
    else 
        temp = target->right;
    if(temp != nullptr)
        temp->parent = target->parent;
    if(target->parent == nullptr) 
    {
        root = temp;
    }
    else 
    {
        if(target == target->parent->left)
            target->parent->left = temp;
        else 
            target->parent->right = temp;
    }
    if(target != node)
        node->data = target->data;
    delete target;
}

void BinarySearch::remove(int key)
{
    Node* node = _search(root, key);
    if(node == nullptr)
    {
        std::cout << "delete " << key << " - not found\n";
        return;
    } 
    std::cout << "deleted " << key << std::endl;
    _remove(node);
}

Node* BinarySearch::_min(Node* x)
{
    while (x->left != nullptr)
        x = x->left;
    return x;
}

void BinarySearch::min()
{
    Node* node = _min(root);
    std::cout << "min is " << node->data << std::endl;
}

void BinarySearch::max()
{
    Node* node = _max(root);
    std::cout << "max is " << node->data << std::endl;
}

Node* BinarySearch::_max(Node *x)
{
    while (x->right != nullptr)
        x = x->right;
    return x;
}

Node* BinarySearch::_search(Node *x, int k)
{
    if (x == nullptr || x->data == k)
        return x;
    if (k < x->data)
        return _search(x->left, k);
    return _search(x->right, k);
}

void BinarySearch::search(int key)
{
    if(_search(root, key))
        std::cout << key << " found\n";
    else 
        std::cout << key << " not found\n";
}

void BinarySearch::_inorder(Node* x)
{
    if(x == nullptr) return;
    _inorder(x->left);
    std::cout << x->data << " ";
    _inorder(x->right);
}

void BinarySearch::inorder()
{
    _inorder(root);
}

void BinarySearch::_preorder(Node* x)
{
    if(x == nullptr) return;
    std::cout << x->data << " ";
    _preorder(x->left);
    _preorder(x->right);
}

void BinarySearch::preorder()
{
    _preorder(root);
}

void BinarySearch::_postorder(Node* x)
{
    if(x == nullptr) return;
    _postorder(x->left);
    _postorder(x->right);
    std::cout << x->data << " ";
}

void BinarySearch::postorder()
{
    _postorder(root);
}

Node* BinarySearch::_successor(Node* x)
{
    if(x->right != nullptr) return _min(x->right);
    Node* temp = x->parent;
    while(temp != nullptr && x == temp->right)
    {
        x = temp;
        temp = temp->parent;
    } 
    return temp;
}

void BinarySearch::successor(int key)
{
    Node* target = _search(root, key);
    if(target == nullptr)
    {
        std::cout << key << " not in tree\n";
        return;
    }
    Node* node = _successor(target);
    if(node == nullptr)
    {
        std::cout << "no successor for " << key << std::endl;
        return;
    }
    std::cout << key << " successor is " << node->data << std::endl;
}

Node* BinarySearch::_predecessor(Node* x)
{
    if(x->left != nullptr) return _max(x->left);
    Node* temp = x->parent;
    while(temp != nullptr && x == temp->left)
    {
        x = temp;
        temp = temp->parent;
    }
    return temp;
}

void BinarySearch::predecessor(int key)
{
    Node* target = _search(root, key);
    if(target == nullptr)
    {
        std::cout << key << " not in tree\n";
        return;
    }
    Node* node = _predecessor(target);
    if(node == nullptr)
    {
        std::cout << "no predecessor for " << key << std::endl;
        return;
    }
    std::cout << key << " predecessor is " << node->data << std::endl;
}

void BinarySearch::destroyNode(Node* node)
{
    if(node)
    {
        destroyNode(node->left);
        destroyNode(node->right);
        delete node;
    }
}
#endif