/* 顺序表基本操作
 *
 * 思路：用一段连续内存 + 长度计数器实现线性表的顺序存储。
 * 关键点：插入/删除要移动元素，平均移动 n/2 个。
 *
 * 编译运行：make run f=linearlist/01-顺序表基本操作.c
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

/* 初始化：length 置 0。时间复杂度 O(1)。 */
void InitList(SqList *L) {
    /* TODO */
}

/* 按位查找：1 <= i <= length，返回下标 i-1 的元素值。
 * 时间复杂度 O(1)。位序 i 是 1-based，别忘了减 1。 */
int GetElem(const SqList *L, int i, int *e) {
    /* TODO: 返回 0 表示越界失败，1 表示成功 */
    return 0;
}

/* 按值查找：返回第一个等于 e 的位序（1-based），找不到返回 0。
 * 时间复杂度 O(n)。 */
int LocateElem(const SqList *L, int e) {
    /* TODO */
    return 0;
}

/* 插入：在位序 i 处插入 e，length 加 1。
 * 时间复杂度 O(n)。注意：需不需要判满？从后往前搬。 */
int ListInsert(SqList *L, int i, int e) {
    /* TODO */
    return 0;
}

/* 删除：删除位序 i 的元素并带回 e，length 减 1。
 * 时间复杂度 O(n)。从前往后搬。 */
int ListDelete(SqList *L, int i, int *e) {
    /* TODO */
    return 0;
}

/* 打印：格式 [1, 2, 3] */
void PrintList(const SqList *L) {
    /* TODO */
}

int main(void) {
    SqList L;
    InitList(&L);

    /* 边界用例：空表删除、表尾插入、非法位序 —— 这三个最常考 */
    for (int i = 1; i <= 5; i++) {
        ListInsert(&L, i, i * 10);
    }
    printf("插入 5 个元素: ");
    PrintList(&L);

    int e = 0;
    printf("GetElem(i=3) 成功? %d, 值=%d\n", GetElem(&L, 3, &e), e);
    printf("LocateElem(40) = %d\n", LocateElem(&L, 40));

    ListDelete(&L, 2, &e);
    printf("删除位序 2 (值=%d) 后: ", e);
    PrintList(&L);

    printf("非法插入 (i=0): %d\n", ListInsert(&L, 0, 99));
    printf("非法删除 (i=99): %d\n", ListDelete(&L, 99, &e));

    return 0;
}
