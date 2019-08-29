#include "../header/bintree.h"

/*
 *   Creates a tree node. Allocates the memory
 * 
 *   value: node value
 *
 *   returns:  tree node pointer if memory allocation was successfull
 *             NULL if memory allocation failed
 */
tree_node_t* bintree_node(int value) {
    tree_node_t* node = malloc(sizeof(struct tree_node_s));
    // memory allocation for node failed
    if(node == NULL){
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

/*
 *   Destroys the tree. Deallocates the memory
 *
 *   *root: root node pointer
 */
void bintree_destroy(tree_node_t* root) {
    if(root != NULL){
        bintree_destroy(root->left);
        bintree_destroy(root->right);
        free(root);
    }
}

/*
 *   Creates and inserts a new node into the tree. 
 *   If no node has been inserted yet, the function creates and returns the root node
 *
 *   *root: root node pointer
 *    value: node value
 *
 *   returns: the root node pointer
 */
tree_node_t* bintree_insert(tree_node_t* root, int value) {
    // tree is empty. create root node
    if(root == NULL){
        return bintree_node(value);
    }
    // recursion to traverse tree & find place to insert
    if(value < root->value) {
        root->left = bintree_insert(root->left, value);
    } else if (value > root->value) {
        root->right = bintree_insert(root->right, value);
    }
    // return function argument node pointer
    return root;
}

/*
 *   Searches the tree for a given value
 *
 *   *root: root node pointer
 *    value: node value to search for
 *
 *   returns: 0 if the node value was not found
 *            1 if the node value was found
 */
int bintree_search(tree_node_t* root, int value) {
    if(root == NULL) { // node not found
        return 0;
    } else if(root->value == value) { // node found
        return 1;
    } else if(root->value < value) { // recursive search, right
        bintree_search(root->right, value);
    } else if(root->value > value) { // recursive search, left
        bintree_search(root->left, value);
    }
}

/*
 *   Tree depth is depth of left and right subtree +1 for the root node.
 *   The depth of an uninitialized tree is 0.
 *
 *   *root: root node pointer
 *
 *   returns: tree depth as int
 */
int bintree_depth(tree_node_t* root) {
    if(root == NULL) {
        return 0;
    } else {
        return 1 + MAX(bintree_depth(root->left), bintree_depth(root->right));
    }
}

/*
 *   Prints the elements in the tree in in-order notation (left, node, right)
 *
 *   *root: root node pointer
 */
void bintree_inorder(struct tree_node_s *root) { 
    if (root != NULL) {
        bintree_inorder(root->left); 
        printf("%d \n", root->value);
        bintree_inorder(root->right); 
    } 
}

/*
 *   Prints the elements in the tree in pre-order notation (node, left, right)
 *
 *   *root: root node pointer
 */
void bintree_preorder(struct tree_node_s *root) {
    if (root != NULL) {
        printf("%d \n", root->value);
        bintree_inorder(root->left);
        bintree_inorder(root->right); 
    } 
}

/*
 *   Prints the elements in the tree in in-order notation (left, right, node)
 *
 *   *root: root node pointer
 */
void bintree_postorder(struct tree_node_s *root) { 
    if (root != NULL) {
        bintree_inorder(root->left);
        bintree_inorder(root->right); 
        printf("%d \n", root->value);
    } 
}