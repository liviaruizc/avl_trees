// avl_trees.cpp
// Livia Correia
// Definitions and declarations of properties and methods of AVL trees.
// ------------------------------------------------------------
#include <iostream>     // printing
#include <vector>       // testing
#include <cmath>

template <typename T>
class AVLTree {
private:

    // Node structure for balanced tree with height property
    struct AVLNode {
        T data;
        AVLNode* left;
        AVLNode* right;
        int height;

        // public methods that return height of child nodes
        // or 0 if null
        int heightLeft() { return left ? left->height : 0; }
        int heightRight() { return right ? right->height : 0; }
    };

    AVLNode* root;

    // private methods:
    // ------------------------------------------------------------

    AVLNode* insert(AVLNode* node, T key) {
        if (!node) {
            node = new AVLNode{key, nullptr, nullptr, 0};
        }
        else if (key < node->data) {
            node->left = insert(node->left, key);
        }
        else {
            node->right = insert(node->right, key);
        }

        node->height = std::max(node->heightLeft(), node->heightRight()) + 1;


        node = balance(node);
        
        return node;
    }  // insert

    AVLNode* balance(AVLNode* node) {
        // If the height difference between left and right subtrees is greater than 1
        if ((std::abs(node->heightLeft() - node->heightRight())) > 1) {

            // Rotate left if the right subtree is taller
            if (node->heightRight() > node->heightLeft()) {
                // Get the right child of the current node
                AVLNode* rightChild = node->right;

                // Perform a single left rotation if the right subtree is right-heavy
                if (rightChild && rightChild->heightRight() > rightChild->heightLeft()) {
                    node = singleLeft(node);
                }

                // Otherwise, perform a double left rotation
                else
                    node = doubleLeft(node);
            }

            // Rotate right if the left subtree is taller
            if (node->heightLeft() > node->heightRight()) {
                    // Get the left child of the current node
                    AVLNode* leftChild = node->left;

                    // Perform a single right rotation if the left subtree is left-heavy
                    if (leftChild && leftChild->heightLeft() > leftChild->heightRight()) {
                        node = singleRight(node);
                    }
                    else
                        // Otherwise, perform a double right rotation
                            node = doubleRight(node);
            }

        }
        // Return the balanced node
        return node;
    } // balance
    
    AVLNode* singleLeft(AVLNode* node) {
        // Get the right child of the node
        AVLNode* rightChild = node->right;
        if (rightChild) {
            // Move the left subtree of rightChild to be the right subtree of node
            node->right = rightChild->left;
            // Set node as the left child of rightChild
            rightChild->left = node;
            // Update the height of node
            node->height = std::max(node->heightLeft(),node->heightRight()) + 1;
            // Update the height of rightChild
            rightChild->height = std::max(rightChild->heightRight(), rightChild->heightLeft()) + 1;
        }
        // Return the new root after rotation    
        return rightChild;
    } // singleLeft

    AVLNode* singleRight(AVLNode* node) {
        // Get the left child of the node
        AVLNode* leftChild = node->left;
        // Move the right subtree of leftChild to be the left subtree of node
        node->left = leftChild->right;
        // Set node as the right child of leftChild
        leftChild->right = node;
        // Update the height of node
        node->height = std::max(node->heightLeft(), node->heightRight()) + 1;
        // Update the height of leftChild
        leftChild->height = std::max(leftChild->heightLeft(), leftChild->heightRight()) + 1;
        // Return the new root after rotation
        return leftChild;
    } // singleRight

    AVLNode* doubleLeft(AVLNode* node) {
        // Perform a right rotation on the right child of node
        node->right = singleRight(node->right);
        // Perform a left rotation on node
        node = singleLeft(node);
        // Return the new root after rotation
        return node;
    } // doubleLeft

    AVLNode* doubleRight(AVLNode* node) {
        // Perform a left rotation on the left child of node
        node->left = singleLeft(node->left);
        // Perform a right rotation on node
        node = singleRight(node);
        // Return the new root after rotation
        return node;
    } // doubleRight

    void printBT(const std::string& prefix, const AVLNode* node, bool isLeft)
    {
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "L--" : "|--" );

            // print the value of the node
            std::cout << int(node->data) << std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
            printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        }
    }


public:
    // public methods:
    // ------------------------------------------------------------

    AVLTree() : root{nullptr} { }
    
    ~AVLTree() {
        clear(root);
    }
    
    void clear(AVLNode * node) {
        if (!node) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    };
    
    void insert(T key) {
        root = insert(root, key);
    }

    void printBT() {
        printBT("", root, false);
        std::cout << std::endl;
    }

};

// main application methods:
// ------------------------------------------------------------

int main() {
    std::vector<int> list{10, 8, 12, 7, 3, 6};

    AVLTree<int> tree;

    for (int i=0; i < list.size(); ++i) {
        tree.insert(list[i]);
        tree.printBT();
    }

    return 0;
}
