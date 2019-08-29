#ifndef BINTREE_H
#define BINTREE_H

#define MAX(x,y) ((x > y) ? x : y)

#include <stdio.h>
#include <stdlib.h>

/*
 * Binary Search Tree (Integer only)
 * duplicates are not stored a BST is a set of non-duplicate values by definition
 */
struct tree_node_s {
  struct tree_node_s *left;
  struct tree_node_s *right;
  int value;
};
// ^fixed data type for "value" instead of void*
// e.g. compare operations in insert function require a type!
// pointer casting could be done with macros / enums&switches ..
// but this implementation is supposed to be a small working example

typedef struct tree_node_s tree_node_t;

/*
 * Allocates a tree node in memory
 */
tree_node_t *bintree_node(int value);
/*
 * Deallocates the whole tree in memory when given the root node
 */
void bintree_destroy(tree_node_t* root);
/*
 * Creates and inserts a new node into the tree
 */
tree_node_t* bintree_insert(tree_node_t* root, int value);
/*
 * Searches the tree for a given value
 */
int bintree_search(tree_node_t* root, int value);
/*
 * Returns the depth of the tree
 */
int bintree_depth(tree_node_t* root);
/*
 * Prints the tree. left, node, right
 */
void bintree_inorder(tree_node_t* root);
/*
 * Prints the tree. node, left, right
 */
void bintree_preorder(tree_node_t* root);
/*
 * Prints the tree. left, right, node
 */
void bintree_postorder(tree_node_t* root);

#endif