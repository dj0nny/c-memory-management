#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *tree_node_create(int value);
const struct TreeNode *bst_find(const struct TreeNode *root, int value);
const struct TreeNode *bst_min(const struct TreeNode *root);
const struct TreeNode *bst_max(const struct TreeNode *root);

bool bst_insert(struct TreeNode **root, int value);

void tree_print_postorder(const struct TreeNode *root);
void tree_print_inorder(const struct TreeNode *root);
void destroy_bst(struct TreeNode *root);

int main(void) {
  struct TreeNode *bst = NULL;

  bst_insert(&bst, 10);
  bst_insert(&bst, 20);
  bst_insert(&bst, 30);
  bst_insert(&bst, 40);
  bst_insert(&bst, 50);

  tree_print_inorder(bst);
  printf("\n");
  tree_print_postorder(bst);
  destroy_bst(bst);

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

bool bst_insert(struct TreeNode **root, int value) {
  if (*root == NULL) {
    struct TreeNode *new_node = tree_node_create(value);
    
    if (new_node == NULL)
      return false;
    
    *root = new_node;
    return true;
  }

  if ((*root)->value == value)
    return false;

  if (value < (*root)->value)
    return bst_insert(&(*root)->left, value);

  return bst_insert(&(*root)->right, value);
}

const struct TreeNode *bst_find(const struct TreeNode *root, int value) {
  if (root == NULL)
    return NULL;
  
  if (root->value == value)
    return root;

  if (value < root->value)
    return bst_find(root->left, value);

  return bst_find(root->right, value);
}

const struct TreeNode *bst_min(const struct TreeNode *root) {
  if (root == NULL)
    return NULL;

  if (root->left == NULL)
    return root;

  return bst_min(root->left);
}

const struct TreeNode *bst_max(const struct TreeNode *root) {
  if (root == NULL)
    return NULL;

  if (root->right == NULL)
    return root;

  return bst_max(root->right);
}

void tree_print_inorder(const struct TreeNode *root) {
  if (root == NULL)
    return;

  tree_print_inorder(root->left);
  printf("%d ", root->value);
  tree_print_inorder(root->right);
}

void tree_print_postorder(const struct TreeNode *root) {
  if (root == NULL)
    return;

  tree_print_postorder(root->left);
  tree_print_postorder(root->right);
  printf("%d ", root->value);
}

void destroy_bst(struct TreeNode *root) {
  if (root == NULL)
    return;

  destroy_bst(root->left);
  destroy_bst(root->right);

  free(root);
}