/*----- driver.cpp -----------------------------------------------------
                program that tests all functions for class BST
 ------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
#include "BST.h"

int main()
{
    // Testing Constructor and empty()
    BST BinarySearchTree;            // test the class constructor
    cout << "Let's construct empty BST\n";
    cout << "BST " << (BinarySearchTree.empty() ? "is" : "is not") << " empty\n";
    
    // Testing add(insert)
    cout << "\nINsert elements in the tree."
        "\nTry some of them that are already in it and some new: \n";

    int number;
    while(1)
    {
        cout << "Item to insert (-1 to stop): ";
        cin >> number;
        if (number == -1) break;
        BinarySearchTree.insert(number);
    }
    BinarySearchTree.graph(cout);
    cout << "BST " << (BinarySearchTree.empty() ? "is" : "is not") << " empty\n";

    // Testing traversals
    cout << "Inorder Traversal of BST: \n";
    BinarySearchTree.inorder(cout);

    cout << "\nPreorder Traversal of BST: \n";
    BinarySearchTree.preorder(cout);

    cout << "\nPostorder Traversal of BST: \n";
    BinarySearchTree.postorder(cout);


    cout << endl;
    
    
    // Testing remove()
    cout << "\nNow testing the remove() operation."
        "\nTry some of them that are already in it and some new:\n";
    for (;;)
    {
        cout << "Item to remove (-1 to stop): ";
        cin >> number;
        if (number == -1) break;
        BinarySearchTree.remove(number);
        BinarySearchTree.graph(cout);
    }
    cout << "\nInorder Traversal of BST: \n";
    BinarySearchTree.display(cout);
    cout << endl;


    // Testing search()
    cout << "\n\nLets test the search() function."
        "\nTry some of them that are already in it and some new:\n";
    while (1)
    {
        cout << "Item to find (-1 to go to stop): ";
        cin >> number;
        if (number == -1) break;
        cout << (BinarySearchTree.search(number) ? "Found" : "Not found") << endl;
    }

}