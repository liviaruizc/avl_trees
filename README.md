# avl_trees
Definitions and declarations of properties and methods of AVL trees

# AVL Tree Implementation in C++

This project implements an **AVL Tree**, a self-balancing binary search tree (BST) where the difference in heights between the left and right subtrees of any node is at most one. This implementation includes methods for inserting elements and balancing the tree using various rotations to maintain the AVL property.

## Features

- **Self-Balancing**: The tree automatically maintains balance after each insertion to ensure O(log n) time complexity for both insertion and search.
- **Rotations**: The implementation supports four types of rotations:
  - Single Left Rotation
  - Single Right Rotation
  - Double Left Rotation
  - Double Right Rotation
- **Tree Printing**: A utility function `printBT()` that prints the tree structure to the console for easy visualization of the tree's structure.

## Data Structures

- **AVLNode**: The internal structure that represents each node in the tree. It contains:
  - `data`: The value stored in the node.
  - `left` and `right`: Pointers to the left and right children of the node.
  - `height`: The height of the node, which is used for balancing.

## Functions

### Public Methods:
- `insert(T key)`: Inserts a new key into the AVL tree and balances the tree.
- `clear(AVLNode* node)`: Recursively deletes all nodes in the tree to free up memory.
- `printBT()`: Prints the tree structure in a readable format.
  
### Private Methods:
- `insert(AVLNode* node, T key)`: Helper function for inserting a key into the tree.
- `balance(AVLNode* node)`: Balances the tree by checking the balance factor and performing necessary rotations.
- `singleLeft(AVLNode* node)`, `singleRight(AVLNode* node)`: Perform single left and right rotations.
- `doubleLeft(AVLNode* node)`, `doubleRight(AVLNode* node)`: Perform double left and right rotations.
- `heightLeft()`, `heightRight()`: Helper functions to get the height of the left and right child nodes.
- `printBT(const std::string& prefix, const AVLNode* node, bool isLeft)`: A recursive function to print the tree in a visually structured way.

## Example Usage

### Inserting elements:
The following code demonstrates inserting elements into an AVL tree and printing the tree structure after each insertion.

```cpp
#include <iostream>
#include <vector>
#include "avl_trees.cpp"

int main() {
    std::vector<int> list{10, 8, 12, 7, 3, 6};
    AVLTree<int> tree;

    for (int i = 0; i < list.size(); ++i) {
        tree.insert(list[i]);
        tree.printBT();  // Print the tree structure after each insertion
    }

    return 0;
}

## Example Output:
|--10
|  L--8
|     L--7
|        L--3
|  R--12
|     L--6

## How to Run the Program
Clone this repository to your local machine:

git clone <repository-url>
Compile the program using a C++ compiler:

g++ avl_trees.cpp -o avl_trees
Run the compiled executable:

./avl_trees
The program will output the AVL tree structure as it inserts new elements, balancing the tree as necessary.

## Contributing
If you'd like to contribute to this project, please fork the repository and submit a pull request with your changes.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

This **README.md** file provides a clean structure with instructions for using and understanding the AVL Tree implementation. It also includes sections for setup and contribution, which are useful for anyone else looking to explore or contribute to your project. Be sure to replace the `<repository-url>` with your actual GitHub repository URL.

