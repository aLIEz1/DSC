//
// Created by super on 2020/6/26.
//

#include <stdio.h>
#include <stdlib.h>

#define StackInitSize 100

/**
 * 栈数据结构定义
 */
typedef struct {
    int data[StackInitSize];
    int top;
} SeqStack;

/**
 * 栈的初始化
 * @return
 */
SeqStack *InitStack() {
    SeqStack *s;
    s = (SeqStack *) malloc(sizeof(SeqStack));
    if (s != NULL) {
        s->top - 1;
        return s;
    } else {
        printf("没有足够的内存空间，申请失败");
        exit(0);
    }
}

/**
 * 判断栈是否为空
 * @param s
 * @return
 */
int IsEmpty(SeqStack *s) {
    return (s->top == -1) ? 1 : 0;
}

/**
 * 销毁栈
 * @param s
 */
void DestroyStack(SeqStack *s) {
    free(s);
    printf("栈已销毁");
}


/**
 * 进栈
 * @param s
 * @param x
 */
void Push(SeqStack *s, int x) {
    if (s->top == StackInitSize) {
        printf("栈满");
        exit(0);
    } else {
        s->top++;
        s->data[s->top] = x;
    }
}

/**
 * 出栈
 * @param s
 * @return
 */
int Pop(SeqStack *s) {
    int temp;
    if (IsEmpty(s)) {
        printf("栈空");
        exit(0);
    } else {
        temp = s->data[s->top];
        s->top--;
        return temp;
    }
}

int GetTop(SeqStack *s) {
    if (IsEmpty(s)) {
        printf("栈空");
        exit(0);
    } else {
        return s->data[s->top];
    }
}

/**
 * 打印栈
 * @param s
 */
void Display(SeqStack *s) {
    int p;
    for (int p = s->top; p > 0; p--) {
        printf("%d->", s->data[p]);
    }
    printf("/b/b\n");
}