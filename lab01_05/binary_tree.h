#pragma once

#include <iostream>
#include <algorithm> 
#include <iomanip>   

#include "my_list.h"

using namespace std;

struct TreeNode {
    int data;
    int numChildNodes; // Новое поле для хранения количества подузлов
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), numChildNodes(1), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void convertToBinarySearchTree() {
        MyList<int> values;
        inOrderTraversal(root, values);
        values.sort();
        root = buildBST(values, 0, values.get_size() - 1);
    }


    void remove(int value) {
        root = removeRecursive(root, value);
    }

    bool search(int value) const {
        return searchRecursive(root, value);
    }

    void printTree() const {
        printRecursive(root, 0);
    }
    
    void printNodeCount() const {
        printChildNodesRecursive(root, 0);
    }

private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* node, int value);

    void inOrderTraversal(TreeNode* node, MyList<int>& values) const;

    TreeNode* buildBST(MyList<int>& values, int start, int end);

    TreeNode* removeRecursive(TreeNode* node, int value);

    int minValue(TreeNode* node) const;

    bool searchRecursive(TreeNode* node, int value) const;

    void printRecursive(TreeNode* node, int indent) const;

    void printChildNodesRecursive(TreeNode* node, int indent) const;

};