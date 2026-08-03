#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE

TreeNode *createNode(int x) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if(node == NULL) {
      return NULL;
    }

    node->value = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

TreeNode *buildUtil(int inArray[], int postArray[], int inStart, int inEnd, int *pIndex) {

  if (inStart > inEnd)
    return NULL;

  TreeNode *node = createNode(postArray[*pIndex]);
  (*pIndex)--;

  if (inStart == inEnd)
    return node;

  int inIndex = search(inArray, inStart, inEnd, node->value);

  node->right = buildUtil(inArray, postArray, inIndex + 1, inEnd, pIndex);
  node->left = buildUtil(inArray, postArray, inStart, inIndex - 1, pIndex);

  return node;
    
}

Tree * buildTree(int * inArray, int * postArray, int size) {

  Tree* tree = malloc(sizeof(*tree));
  if (tree == NULL) {
    return NULL;
  }
  
  int pIndex = size - 1;
  tree->root = buildUtil(inArray, postArray, 0, size - 1, &pIndex);
 return tree;
}
#endif

#ifdef TEST_PRINTPATH
int recPath(TreeNode * curnode, int val) {

  if(curnode == NULL) {
    return false;
  }

  if(curnode->value == val) {
    printf("%d ", curnode->value);
    return true;
  }

  if(recPath(curnode->left, val) == true) {
    printf("%d ", curnode->value);
    return true;
  }

  if(recPath(curnode->right , val) == true) {
    printf("%d ", curnode->value);
    return true;
  }

  return false;

}

void printPath(Tree * tr, int val)
{
  if(tr == NULL) {
    return;
  }

  recPath(tr->root, val);
  printf("\n");
}
#endif
