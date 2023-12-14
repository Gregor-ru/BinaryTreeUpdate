#include "binary_tree.h"

TreeNode* BinarySearchTree::insertRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    // ”величиваем количество подузлов в текущем узле
    ++node->numChildNodes;

    // ¬ставл€ем новый элемент в первый свободный подузел
    if (node->left == nullptr) {
        node->left = insertRecursive(node->left, value);
    } else if (node->right == nullptr) {
        node->right = insertRecursive(node->right, value);
    } else {
        // ≈сли оба подузла заполнены, спускаемс€ дальше
        if (node->left->numChildNodes < node->right->numChildNodes) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }
    }

    return node;
}


void BinarySearchTree::inOrderTraversal(TreeNode* node, MyList<int>& values) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, values);
        values.push_back(node->data);
        inOrderTraversal(node->right, values);
    }
}

TreeNode* BinarySearchTree::buildBST(MyList<int>& values, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;

    MyList<int>::ListNode* midNode = values.begin();
    for (int i = 0; i < mid; ++i) {
        midNode = midNode->next;
    }

    TreeNode* newNode = new TreeNode(midNode->data);

    newNode->left = buildBST(values, start, mid - 1);
    newNode->right = buildBST(values, mid + 1, end);

    newNode->numChildNodes = 1+ (newNode->left ? newNode->left->numChildNodes : 0) + (newNode->right ? newNode->right->numChildNodes : 0);

    return newNode;
}


TreeNode* BinarySearchTree::removeRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->data) {
        node->left = removeRecursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = removeRecursive(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        node->data = minValue(node->right);
        node->right = removeRecursive(node->right, node->data);
    }

    // ѕосле удалени€ уменьшаем число подузлов в текущем узле
    --node->numChildNodes;

    return node;
}


int BinarySearchTree::minValue(TreeNode* node) const {
    int minValue = node->data;
    while (node->left != nullptr) {
        minValue = node->left->data;
        node = node->left;
    }
    return minValue;
}

bool BinarySearchTree::searchRecursive(TreeNode* node, int value) const {
    if (node == nullptr) {
        return false;
    }

    if (value == node->data) {
        return true;
    }
    else if (value < node->data) {
        return searchRecursive(node->left, value);
    }
    else {
        return searchRecursive(node->right, value);
    }
}

void BinarySearchTree::printRecursive(TreeNode* node, int indent) const {
    if (node != nullptr) {
        if (node->right) {
            printRecursive(node->right, indent + 4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (node->right) {
            cout << " /\n" << setw(indent) << ' ';
        }
        cout << node->data << "\n ";
        if (node->left) {
            cout << setw(indent) << ' ' << " \\\n";
            printRecursive(node->left, indent + 4);
        }
    }
}

void BinarySearchTree::printChildNodesRecursive(TreeNode* node, int indent) const {
    if (node != nullptr) {
        if (node->right) {
            printChildNodesRecursive(node->right, indent + 4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (node->right) {
            cout << " /\n" << setw(indent) << ' ';
        }
        cout << node->numChildNodes << "\n ";
        if (node->left) {
            cout << setw(indent) << ' ' << " \\\n";
            printChildNodesRecursive(node->left, indent + 4);
        }
    }
}

