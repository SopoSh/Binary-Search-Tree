/* BST.h contains the declaration of class  BST.
   Basic operations:
     Constructor: Constructs an empty BST
      preorder, postorder, and level-by-level traversals
        function members:
     empty:       Checks if a BST is empty
     search:      Search a BST for an item
     insert:      Inserts a value into a BST
     remove:      Removes a value from a BST
     inorder:     Inorder traversal of a BST -- output the data values
       Private utility helper operations:
     search2:     Used by delete
     inorderAux:  Used by inorder

---------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
#include "TreeNode.h"

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
public:
    /***** Function Members *****/
    BST();
    /*------------------------------------------------------------------------
      Construct a BST object.
      Precondition:  None.
      Postcondition: An empty BST has been constructed.
     -----------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
      Check if BST is empty.

      Precondition:  None.
      Postcondition: Returns true if BST is empty and false otherwise.
     -----------------------------------------------------------------------*/

    bool search(const int item) const;
    /*------------------------------------------------------------------------
      Search the BST for item.

      Precondition:  None.
      Postcondition: Type bool returns true if item found, and false otherwise.
     -----------------------------------------------------------------------*/

    void insert(const int item);
    /*------------------------------------------------------------------------
      Insert item into BST.

      Precondition:  None.
      Postcondition: BST has been modified with item inserted at proper
          position to maintain BST property.
    ------------------------------------------------------------------------*/

    void remove(const int item);
    /*------------------------------------------------------------------------
      Remove item from BST.

      Precondition:  None.
      Postcondition: BST has been modified with item removed (if present);
          BST property is maintained.
      Note: remove uses auxiliary function search2() to locate the node
            containing item and its parent.
   ------------------------------------------------------------------------*/

    void inorder(ostream& out) const;
    /*------------------------------------------------------------------------
      Inorder traversal of BST.

      Precondition:  ostream out is open.
      Postcondition: BST has been inorder traversed and values in nodes
          have been output to out.
      Note: inorder uses private auxiliary function inorderAux().
   ------------------------------------------------------------------------*/
    void preorder(ostream& out) const;
    /*------------------------------------------------------------------------
     Preorder traversal of BST.

     Precondition:  ostream out is open.
     Postcondition: BST has been preorder (VLR) traversed and values in nodes
         have been output to out.
     Note: preorder uses private auxiliary function preorderAux().
  ------------------------------------------------------------------------*/
    void postorder(ostream& out) const;
    /*------------------------------------------------------------------------
     Postorder traversal of BST.

     Precondition:  ostream out is open.
     Postcondition: BST has been postorder (LRV) traversed and values in nodes
         have been output to out.
     Note: postorder uses private auxiliary function inorderAux().
  ------------------------------------------------------------------------*/

    void display(ostream& out) const;

    void graph(ostream& out) const;
    /*------------------------------------------------------------------------
      Graphic output of BST.

      Precondition:  ostream out is open.
      Postcondition: Graphical representation of BST has been output to out.
      Note: graph() uses private auxiliary function graphAux().
   ------------------------------------------------------------------------*/

private:

    typedef TreeNode* TreeNodePointer;   //to implement bst with linked list
                                        //we need data member pointer to the first node

    /***** Private Function Members *****/
    void search2(const int item, bool& found,
        TreeNodePointer& locptr, TreeNodePointer& parent) const;
    /*------------------------------------------------------------------------
      Locate a node containing item and its parent.

      Precondition:  None.
      Postcondition: locptr points to node containing item or is null if
          not found, and parent points to its parent.
    ------------------------------------------------------------------------*/
    void inorderAux(ostream& out, 
        TreeNodePointer subtreePtr) const;
    /*------------------------------------------------------------------------
      Inorder traversal auxiliary function.

      Precondition:  ostream out is open; subtreePtr points to a subtree
          of this BST.
      Postcondition: Subtree with root pointed to by subtreePtr has been
          output to out.
   ------------------------------------------------------------------------*/
    void preorderAux(ostream& out,
        TreeNodePointer subtreePtr) const;
    /*------------------------------------------------------------------------
     Preorder traversal auxiliary function.

     Precondition:  ostream out is open; subtreePtr points to a subtree
         of this BST.
     Postcondition: Subtree with root pointed to by subtreePtr has been
         output to out.
  ------------------------------------------------------------------------*/
    void postorderAux(ostream& out,
        TreeNodePointer subtreePtr) const;
    /*------------------------------------------------------------------------
     Postorder traversal auxiliary function.

     Precondition:  ostream out is open; subtreePtr points to a subtree
         of this BST.
     Postcondition: Subtree with root pointed to by subtreePtr has been
         output to out.
  ------------------------------------------------------------------------*/


    void graphAux(ostream& out, int indent,
        TreeNodePointer subtreeRoot) const;
    /*------------------------------------------------------------------------
      Graph auxiliary function.

      Precondition:  ostream out is open; subtreePtr points to a subtree
          of this BST.
      Postcondition: Graphical representation of subtree with root pointed
          to by subtreePtr has been output to out, indented indent spaces.
   ------------------------------------------------------------------------*/

   /***** Data Members *****/
    TreeNodePointer myRoot;

}; // end of class  declaration

#endif