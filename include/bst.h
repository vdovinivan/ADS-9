// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
#include  <fstream>

template <typename T>
struct Node {
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    int count = 0;
    T value = "";
};
template <typename T>
class BST {
 private:
    Node<T>* root = nullptr;
    int depthV = 0;

 public:
    BST() {
        root = nullptr;
        depthV = 0;
    }
    void printT(Node<T>* tree, int i) {
        std::cout << i << "-----" << tree->value <<"\n";
        ++i;
        if (tree->left != nullptr) {
            printTree(tree->left, i);
        }
        if (tree->right != nullptr) {
            printTree(tree->right, i);
        }
        return;
    }
    void getDepth(Node<T>* tree, int i) {
        ++i;
        if (tree->left != nullptr) {
            getDepth(tree->left, i);
        }
        if (tree->right != nullptr) {
            getDepth(tree->right, i);
        }
        if (i > depthV)
            depthV = i;
    }
    void Add(T val) {
        Node<T>* cur = root;
        if (cur == nullptr) {
            cur = new Node<T>;
            cur->left = nullptr;
            cur->right = nullptr;
            cur->value = val;
            cur->count +=1;
            root = cur;
            return;
        } else {
            Node<T>* past = nullptr;
            bool isleft = false;
            while (true) {
                if (cur == nullptr) {
                    cur = new Node<T>;
                    cur->left = nullptr;
                    cur->right = nullptr;
                    cur->value = val;
                    cur->count += 1;
                    if (past != nullptr) {
                        if (isleft == true) {
                            past->left = cur;
                        } else {
                            past->right = cur;
                        }
                        past = nullptr;
                    }
                    break;
                } else if (val == cur->value) {
                    cur->count += 1;
                    break;
                } else if (val > cur->value) {
                    isleft = false;
                    past = cur;
                    cur = cur->right;
                } else if (val < cur->value) {
                    isleft = true;
                    past = cur;
                    cur = cur->left;
                }
            }
        }
    }
    int search(T val) {
        Node<T>* cur = root;
        while (true) {
            if (cur->value == val) {
                return cur->count;
            } else if (val > cur->value) {
                cur = cur->right;
            } else if (val < cur->value) {
                cur = cur->left;
            }
        }
    }
    int depth() {
        Node<T>* cur = root;
        getDepth(cur, 0);
        return depthV - 1;
    }

    void printTree() {
        Node<T>* cur = root;
        printT(cur, 0);
    }
};
#endif  // INCLUDE_BST_H_
