/**This file implements the signatures defined in the tree.h file
 * Author: Alvin Nguyen
 *
 */
#include "tree.h"
#include <iostream>
using namespace std;

//default constructor

Tree::Tree() {
    start = NULL;
}

//copy constructor

Tree::Tree(const Tree& other) {
    copyOther(other);
}

//destructor

Tree::~Tree() {
    clear();
}
//overloaded assignment operator

Tree& Tree::operator=(const Tree& other) {
    if (start == other.start) {
        return *this;
    }
    clear();
    copyOther(other);
    return *this;
}

//Returns the address containing the value

TreeNode* Tree::find(int value) const {
    return findFrom(start, value);
}


//insert value at appropriate location

void Tree::push(int value) {
    TreeNode* curr = new TreeNode;
    curr -> value = value;
    if (start == NULL) {
        start = curr;
        return;
    }
    pushFrom(start, curr);
}

//print the tree data

void Tree::print() const {
    printFrom(start, 0);
}

//deletes the node with value in the tree and deallocates its memory

void Tree::deleteNode(int value) {
    deleteFrom(start, value);
}

//copyOther

void Tree::copyOther(const Tree& other) {
    start = NULL;
    if (other.start == NULL) {
        start = NULL;
        return;
    }
    copyFrom(other.start);
}
// you should implement and use this function inside your 
// destructor to delete all the nodes and free memory

void Tree::clear() {
    if (start == NULL) {
        return;
    }
    clearFrom(start);
    start = NULL;
}

//recursively push a single element into a tree

void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush) {
    if (nodeToPush -> value < startingPoint -> value) {
        if (startingPoint -> left == NULL) {
            startingPoint -> left = nodeToPush;
        } else {
            pushFrom(startingPoint -> left, nodeToPush);
        }
    } else {
        if (startingPoint -> right == NULL) {
            startingPoint -> right = nodeToPush;
        } else {
            pushFrom(startingPoint -> right, nodeToPush);
        }
    }
}

//Recursively find a single element in a tree

TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const {
    if (startingPoint == NULL) {
        return NULL;
    }
    if (startingPoint -> value == value) {
        return startingPoint;
    } else if (value < startingPoint -> value) {
        return findFrom(startingPoint -> left, value);
    } else {
        return findFrom(startingPoint -> right, value);
    }
}

//Helper function used inside print function

void Tree::printFrom(TreeNode* startingPoint, int numSpaces) const {
    if (NULL == startingPoint) {
        return;
    }
    for (int i = 0; i < numSpaces; i++) {
        cout << " ";
    }
    cout << startingPoint -> value << endl;
    numSpaces += 1;
    printFrom(startingPoint->left, numSpaces);
    printFrom(startingPoint-> right, numSpaces);
}

//copyFrom

void Tree::copyFrom(TreeNode * startingPoint) {
    if (startingPoint == NULL) {
        return;
    }
    push(startingPoint -> value);
    copyFrom(startingPoint -> left);
    copyFrom(startingPoint -> right);
}

//use to implement deleteFrom function

TreeNode* Tree::searchParentNode(TreeNode* startingPoint, TreeNode* nodeOfInterest) {
    if (startingPoint == NULL) {
        return NULL;
    }
    if (startingPoint -> left == nodeOfInterest || startingPoint -> right == nodeOfInterest) {
        return startingPoint;
    } else if (nodeOfInterest -> value <= startingPoint -> value) {
        return searchParentNode(startingPoint -> left, nodeOfInterest);
    } else {
        return searchParentNode(startingPoint -> right, nodeOfInterest);
    }

}

//deleteFrom

void Tree::deleteFrom(TreeNode* startingPoint, int value) {
    if (startingPoint == NULL) {
        cout << "Sorry tree is empty, no nodes to delete!" << endl;
        return;
    }
    //case for no children
    if (startingPoint -> value == value) {
        delete startingPoint;
        if (startingPoint -> left == NULL && startingPoint -> right == NULL) {
            TreeNode* curr = new TreeNode;
            curr = searchParentNode(start, startingPoint);
            if (curr -> left == startingPoint) {
                curr -> left = NULL;
            } else {
                curr -> right = NULL;
            }
            startingPoint = NULL;
            //case if tree has right child
        } else if (startingPoint -> left == NULL) {
            TreeNode* temp = new TreeNode;
            TreeNode* curr = new TreeNode;
            temp = startingPoint;
            curr = searchParentNode(start, startingPoint);
            if (curr -> right == startingPoint) {
                startingPoint = startingPoint -> right;
                curr -> right = startingPoint;
                //case if tree has left child
            } else {
                startingPoint = startingPoint -> right;
                curr -> left = startingPoint;
            }
            delete temp;
        } else if (startingPoint -> right == NULL) {
            TreeNode* temp = new TreeNode;
            TreeNode* curr = new TreeNode;
            temp = startingPoint;
            curr = searchParentNode(start, startingPoint);
            if (curr -> right == startingPoint) {
                startingPoint = startingPoint -> left;
                curr -> right = startingPoint;
                //case if tree has left child
            } else {
                startingPoint = startingPoint -> left;
                curr -> left = startingPoint;
            }
            delete temp;
        } else {
            TreeNode* nodeToDelete = new TreeNode;
            nodeToDelete = startingPoint;
            nodeToDelete = startingPoint -> left;
            while (nodeToDelete -> right != NULL) {
                nodeToDelete = nodeToDelete -> right;
            }
            startingPoint -> value = nodeToDelete -> value;
            deleteFrom(startingPoint -> left, nodeToDelete ->value);
        }
        
    }

}
//clearFrom

void Tree::clearFrom(TreeNode * startingPoint) {
    if (startingPoint == NULL) {
        return;
    }
    clearFrom(startingPoint -> left);
    clearFrom(startingPoint -> right);
    delete startingPoint;
    startingPoint = NULL;
}