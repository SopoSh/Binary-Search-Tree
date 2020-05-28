#include <iostream>
using namespace std;

#ifndef TREE_NODE
#define TREE_NODE

/***** Node class *****/
class TreeNode
{
public:
    friend class BST;
    // TreeNode constructors
    // Default -- item is default value, pointers are nulls 
    TreeNode();

    // Explicit Value -- data part contains item; both links are null.
    TreeNode(int i, TreeNode* L, TreeNode* R); //explicit value constructor
    int getData() const; // accessor function

    private:
            int data;
            TreeNode* Lchild;
            TreeNode* Rchild;


};// end of class TreeNode declaration
inline TreeNode::TreeNode()
{
    Lchild = Rchild = NULL;
}

inline TreeNode::TreeNode(int i, TreeNode* L = 0, TreeNode* R = 0) : data(i), Lchild(L), Rchild(R)
{}

inline int TreeNode::getData() const
{
    return data;
}
#endif
