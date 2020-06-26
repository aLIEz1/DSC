//
// Created by super on 2020/6/26.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxNode
/**
 * 双亲表示法树的定义
 */
typedef struct {
    int data;
    int parent;
} PTNode;

/**
 * 孩子表示法
 */
typedef struct {
    int child;
    struct CTNode *next;
} CTNode;

/**
 * 孩子兄弟表示法
 */
typedef struct CSNode {
    int data;
    struct CSNode *firstChild;
    struct CSNode *nextSibling;
} CSNode;

/**
 * 二叉树数据结构定义
 */
typedef struct BiTNode {
    char data;
    struct BiTNode *lChild, *rChild;
} BiTNode;
typedef BiTNode *BiTree;

/**
 * 前序遍历
 * @param root
 */
void PreOrder(BiTree root) {
    if (root == NULL) {
        return;
    } else {
        printf("%c", root->data);
        PreOrder(root->lChild);
        PreOrder(root->rChild);
    }
}

/**
 * 中序遍历
 * @param root
 */
void InOrder(BiTree root) {
    if (root == NULL) {
        return;
    } else {
        InOrder(root->lChild);
        printf("%c", root->data);
        InOrder(root->rChild);
    }
}

/**
 * 后序遍历
 * @param root
 */
void PostOrder(BiTree root) {
    if (root == NULL) {
        return;
    } else {
        PreOrder(root->lChild);
        PostOrder(root->rChild);
        printf("%c", root->data);
    }
}

