#include <stdio.h>
#include <stdlib.h>

/**
 * 定义单链表结点
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

/**
 * 定义指向LNode的指针变量
 */
typedef LNode *LinkList;

/**
 * 头插法建立单链表
 * @return LinkList
 */
LinkList CreatList_L1() {
    LinkList L;
    LinkList p;
    int x; //数据元素的类型为int
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL; //建立一个空链表
    scanf("%d", &x);
    while (x != 0) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
        scanf("%d", &x);
    }
    return L;
}

/**
 * 尾插法创建单链表
 * @return LinkList
 */
LinkList CreatList_L2() {
    LinkList L, p, r;
    int x;
    r = L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 0) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = x;
        p->next = NULL;
        r->next = p;
        r = p;
        scanf("%d", &x);
    }
    return L;
}

/**
 * 求单链表长度
 * @param L
 * @return
 */
int ListLength_L(LinkList L) {
    LinkList p;
    int i = 0;
    p = L;
    while (p->next != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

/**
 * 查找单链表中第i个结点
 * @param L
 * @param i
 * @return
 */
LinkList Get_LinkList(LinkList L, int i) {
    LinkList p = L;
    int j = 0;
    while (p->next != NULL && j < i) {
        p = p->next;
        j++
    }
    if (j == i) {
        return p;
    } else {
        return NULL;
    }
}

/**
 * 查找单链表中值为x的节点
 * @param L
 * @param x
 * @return
 */
LinkList Locate_LinkList(LinkList L, int x) {
    LinkList p;
    p = L->next;
    while (p != NULL && p->data != x) {
        p = p->next;
    }
    return p;
}

/**
 * 在单链表第i个节点前插入值为x的元素
 * @param L
 * @param i
 * @param x
 * @return
 */
LinkList LinkInsert(LinkList L, int i, int x) {
    LinkList p, s;
    int j;
    p = L;
    j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1) {
        printf("参数i错误");
        exit(1);
    }
    s = (LinkList) malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    return L;
}

/**
 * 删除第i个节点
 * @param L
 * @param i
 * @return
 */
LinkList ListDelete(LinkList L, int i) {
    LinkList p, q;
    int j;
    p = L;
    j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1) {
        printf("参数i错误");
        exit(1);
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return L;

}

/**
 * 有序链表归并算法
 * @param A
 * @param B
 * @return
 */
LinkList Merge_LinkList(LinkList A, LinkList B) {
    LinkList C, p, q, s;
    p = A->next;
    q = B->next;
    free(B);
    C = A;
    C->next = NULL;
    while (p && q) {
        if (p->data < q->data) {
            s = p;
            p = p->next;
        } else {
            s->next = C->next;
            C->next = s;
        }
    }
    if (p == NULL) {
        p = q;
    }
    while (p) {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
    return C;
}
//int main(){
//    CreatList_L1();
//}