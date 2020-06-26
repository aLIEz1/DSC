#include <stdio.h>
#include <stdlib.h>

//
// Created by super on 2020/6/26.
//

/**
 * 定义双向链表
 */
typedef struct DuLNode {
    int data;
    struct DuLNode *prior, *next;
} DuLNode;

typedef DuLNode *DuLinkList;

/**
 * 在双向链表中插入节点
 * 注意修改链接的顺序，必须找到容易丢失的节点，先将待插入的节点指向它
 * @param L
 * @param i
 * @param x
 * @return
 */
DuLinkList ListInsert_Dul(DuLinkList L, int i, int x) {
    DuLinkList p, s;
    int j;
    p = L;
    j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) {
        printf("参数i错误");
        exit(1);
    }
    if (!(s = (DuLinkList) malloc(sizeof(DuLNode)))) {
        exit(1);
    }
    s->data = x;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return L;
}

/**
 * 删除双向链表中的第i个元素
 * @param L
 * @param i
 * @return
 */
DuLinkList ListDelete_Dul(DuLinkList L, int i){
    DuLinkList p;
    int j;
    p=L;
    j=0;
    while (p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    if (p==NULL||j>i){
        printf("参数i错误");
        exit(1);
    } else{
        p->prior->next=p->next;
        p->next->prior=p->prior;
        free(p);
        return L;
    }
}