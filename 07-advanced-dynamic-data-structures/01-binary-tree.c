#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode *tree_node_create(int value);
const struct TreeNode *tree_find(const struct TreeNode *root, int value);

size_t tree_count(const struct TreeNode *root);
size_t tree_height(const struct TreeNode *root);

bool tree_insert_left(struct TreeNode *parent, int value);
bool tree_insert_right(struct TreeNode *parent, int value);

void tree_print_inorder(const struct TreeNode *root);
void tree_destroy(struct TreeNode *root);

struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
};

int main(void) {
  struct TreeNode *bt = tree_node_create(0);

  tree_insert_left(bt, 10);
  tree_insert_right(bt, 20);

  tree_print_inorder(bt);
  tree_destroy(bt);

  return 0;
}

struct TreeNode *tree_node_create(int value) {
  struct TreeNode *new_tree_node = malloc(sizeof(struct TreeNode));

  if (new_tree_node == NULL)
    return NULL;

  new_tree_node->value = value;
  new_tree_node->left = NULL;
  new_tree_node->right = NULL;

  return new_tree_node;
}

const struct TreeNode *tree_find(const struct TreeNode *root, int value) {
  if (root == NULL)
    return NULL;

  if (root->value == value)
    return root;

  const struct TreeNode *found = tree_find(root->left, value);

  if (found != NULL)
    return found;

  return tree_find(root->right, value);
}

size_t tree_count(const struct TreeNode *root) {  
  if (root == NULL)
    return 0;

  return 1 + tree_count(root->left) + tree_count(root->right);
}

size_t tree_height(const struct TreeNode *root) {
  if (root == NULL)
    return 0;

  size_t left_height = tree_height(root->left);
  size_t right_height = tree_height(root->right);

  return 1 + (left_height < right_height ? right_height : left_height);
}

bool tree_insert_left(struct TreeNode *parent, int value) {
  if (parent == NULL)
    return false;
  
  if (parent->left == NULL) {
    struct TreeNode *new_node = tree_node_create(value);
    
    if (new_node == NULL)
      return false;

    parent->left = new_node;
  } else
    return false;

  return true;
}

bool tree_insert_right(struct TreeNode *parent, int value) {
  if (parent == NULL)
    return false;

  if (parent->right == NULL) {
    struct TreeNode *new_node = tree_node_create(value);

    if (new_node == NULL)
      return false;

    parent->right = new_node;
  } else
    return false;

  return true;
}

void tree_print_inorder(const struct TreeNode *root) {
  if (root == NULL)
    return;

  tree_print_inorder(root->left);
  printf("%d ", root->value);
  tree_print_inorder(root->right);
}

void tree_destroy(struct TreeNode *root) {
  if (root == NULL)
    return;

  tree_destroy(root->left);
  tree_destroy(root->right);
  
  free(root);
}