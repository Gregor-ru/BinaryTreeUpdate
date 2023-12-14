#include "my_list.h"
#include "binary_tree.h"

using namespace std;


int main() {

    BinarySearchTree employeeTree;

    employeeTree.insert(30);  // Director
    employeeTree.printNodeCount();
    cout << "\n";
    employeeTree.insert(50);  // CEO
    employeeTree.printNodeCount();
    cout << "\n";
    employeeTree.insert(70);  // Manager
    employeeTree.printNodeCount();
    cout << "\n";
    employeeTree.insert(80);  // Project Manager
    employeeTree.printNodeCount();
    cout << "\n";
    employeeTree.insert(40);  // Team Lead
    employeeTree.printNodeCount();
    cout << "\n";
    employeeTree.insert(20);  // Team Lead
    employeeTree.printNodeCount();
    cout << "\n";
    employeeTree.insert(60);  // Project Manager
    employeeTree.printNodeCount();
    cout << "\n";

    cout << "Binary Tree Structure:\n";
    employeeTree.printTree();
    cout << "\n";
    employeeTree.printNodeCount();
    cout << endl;

    employeeTree.convertToBinarySearchTree();

    cout << "Binary Search Tree Structure:\n";
    employeeTree.printTree();
    cout << "\n";
    employeeTree.printNodeCount();
    cout << endl;

    int removeEmployee = 30;
    employeeTree.remove(removeEmployee);

    cout << "Binary Search Tree Structure after removal:\n";
    employeeTree.printTree();
    cout << "\n";
    employeeTree.printNodeCount();
    cout << endl;

    return 0;
}