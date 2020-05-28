#include <iostream>
#include <iomanip>
#include "BST.h"
using namespace std;


//--- Definition of constructor

BST::BST()
    : myRoot(0)
{}

//--- Definition of empty()
bool BST::empty() const
{
    return myRoot == 0;    //bool that simply returns false or true
}

//--- Definition of search()
bool BST::search(const int item) const
{
    BST::TreeNodePointer locptr = myRoot;
    bool found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
            locptr = locptr->Lchild;
        else if (locptr->data < item)  // descend right
            locptr = locptr->Rchild;
        else                           // item found
            found = true;
    }
    return found;
}

//--- Definition of insert()
void BST::insert(const int item)
{
    BST::TreeNodePointer
        locptr = myRoot,   // search pointer
        parent = 0;        // pointer to parent of current node
    bool found = false;     // indicates if item already in BST
    while (!found && locptr != 0)
    {
        parent = locptr;
        if (item < locptr->data)       // descend left
            locptr = locptr->Lchild;
        else if (locptr->data < item)  // descend right
            locptr = locptr->Rchild;
        else                           // item found
            found = true;
    }
    if (!found)
    {                                 // construct node containing item
        locptr = new TreeNode(item);
        if (parent == 0)               // empty tree
            myRoot = locptr;
        else if (item < parent->data)  // insert to left of parent
            parent->Lchild = locptr;
        else                           // insert to right of parent
            parent->Rchild = locptr;
    }
    else
        cout << "Item already in the tree\n";
}

//--- Definition of remove()
void BST::remove(const int item)
{
    bool found;                      // true if item is found
    BST::TreeNodePointer            //for removal we need two pointers
        x,                            // points to node to be deleted
        parent;                       //    "    " parent of x and xSucc
    search2(item, found, x, parent);

    if (!found)
    {
        cout << "Item not in the BST\n";
        return;
    }
    //else
    if (x->Lchild != 0 && x->Rchild != 0)
    {                                // node has 2 children

       /* Find x's inorder successor and its parent
        BST::TreeNodePointer xSucc = x->Rchild;
        parent = x;
        while (xSucc->Lchild != 0)       // descend left
        {
            parent = xSucc;
            xSucc = xSucc->Lchild;
        }
        */
        BST::TreeNodePointer xSucc = x->Lchild;
        parent = x;
        while (xSucc->Rchild != 0)       // descend right
        {
            parent = xSucc;
            xSucc = xSucc->Rchild;
        }

        // Move contents of xSucc to x and change x 
        // to point to successor, which will be removed.
        x->data = xSucc->data;
        x = xSucc;
    } // end if node has 2 children


    // Now proceed with case where node has 0 or 2 child
    BST::TreeNodePointer
        subtree = x->Lchild;             // pointer to a subtree of x
    if (subtree == 0)
        subtree = x->Rchild;
    if (parent == 0)                  // root being removed
        myRoot = subtree;
    else if (parent->Lchild == x)       // left child of parent
        parent->Lchild = subtree;
    else                              // right child of parent
        parent->Rchild = subtree;
    delete x;
}



void BST::display(ostream& out) const {
    inorderAux(out, myRoot);
}
//--- Definition of inorder()
 void BST::inorder(ostream& out) const
{
    inorderAux(out, myRoot);
}

 //--- Definition of preorder()
 void BST::preorder(ostream& out) const
 {
     preorderAux(out, myRoot);
 }

 //--- Definition of preorder()
 void BST::postorder(ostream& out) const
 {
     postorderAux(out, myRoot);
 }


//--- Definition of graph()
 void BST::graph(ostream& out) const
{
    graphAux(out, 10, myRoot);
}
 //--- Definition of graphAux()
 void BST::graphAux(ostream& out, int indent,
     TreeNodePointer subtreeRoot) const
 {
     if (subtreeRoot != 0)
     {
         graphAux(out, indent + 8, subtreeRoot->Rchild);
         out << setw(indent) << " " << subtreeRoot->data << endl;
         graphAux(out, indent + 8, subtreeRoot->Lchild);
     }
 }



//--- Definition of search2()      helper for remove
void BST::search2(const int item, bool& found,
    BST::TreeNodePointer& locptr,
    BST::TreeNodePointer& parent) const
{
    locptr = myRoot;
    parent = 0;
    found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
        {
            parent = locptr;
            locptr = locptr->Lchild;
        }
        else if (locptr->data < item)  // descend right
        {
            parent = locptr;
            locptr = locptr->Rchild;
        }
        else                           // item found
            found = true;
    }
}

//--- Definition of inorderAux()
void BST::inorderAux(ostream& out, 
    TreeNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        inorderAux(out, subtreeRoot->Lchild);    // L operation
        out << subtreeRoot->data << "  ";      // V operation
        inorderAux(out, subtreeRoot->Rchild);   // R operation
    }
}

//--- Definition of inorderAux()
void BST::preorderAux(ostream& out,
    TreeNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        out << subtreeRoot->data << "  ";      // V operation
        preorderAux(out, subtreeRoot->Lchild);    // L operation
        preorderAux(out, subtreeRoot->Rchild);   // R operation
    }
}
//--- Definition of inorderAux()
void BST::postorderAux(ostream& out,
    TreeNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        postorderAux(out, subtreeRoot->Lchild);    // L operation
        postorderAux(out, subtreeRoot->Rchild);   // R operation
        out << subtreeRoot->data << "  ";      // V operation
    }
}


