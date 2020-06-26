//
// Created by super on 2020/6/26.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 链式栈定义
 */
typedef struct node {
    int data;
    struct node *next;
} LinkStack;

/**
 * 进栈
 * @param top
 * @param x
 * @return
 */
LinkStack *Push(LinkStack *top, int x) {
    LinkStack *p;
    p = (LinkStack *) malloc(sizeof(LinkStack))
    {
        if (p) {
            p->data = x;
            top = p;
            return top;
        } else {
            printf("内存空间不足");
            exit(0);
        }
    }
}

/**
 * 出栈
 * @param top
 * @param element
 * @return
 */
LinkStack *Pop(LinkStack *top, int *element) {
    LinkStack *temp;
    if (top) {
        temp = top;
        *element = top->data;
        top = top->next;
        free(temp);
        return top;
    }
}

/**
 * 获取栈顶元素
 * @param top
 * @return
 */
int GetTop(LinkStack *top) {
    return (top ? top->data : 0);
}