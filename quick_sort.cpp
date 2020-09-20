/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: lsj
	> Mail: 2659002865@qq.com
	> Created Time: Sun Sep 20 23:18:52 2020
 ************************************************************************/

#include <cstdio>

#define swap(a, b) { \
    __typeof(a) __a = a; \
    __typeof(b) __b = b; \
    a = __b; \
    b = __a; \
}

void handle(int *num, int tmp, int &i, int &j) { //i，j为引用类型
    while (i <= j) { //应用二分思想（严格的）将小于基准的值放在序列的左边，大于基准的值放在序列的右边，待完成全部交换后将中间的一个数字空出来
        while (tmp > num[i]) i++; //找到大于等于基准值的数字（必须得包含等于，因为如果不包含等于基准的数字，一旦出现比基准大或者小的数字将无法和等于自己的值交换）
        while (tmp < num[j]) j--; //找到小于等于基准值的数字
        if (i > j) break; //当序列中i与j指向同一个值之后，如果这个值不是基准值则必会出现i > j的情况，此时表明i或者j因为必有1个越界而不需要交换，跳出循环
        swap(num[i], num[j]); //满足条件时（i || j）在（左半 || 右半）区间的时候交换两个数字
        i++; //完事之后自加和自减
        j--;
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (l >= r) return ; //证明已经排好序了，直接结束调用即可
    int tmp = num[(l + r) / 2], i = l, j = r; //选取基准(序列的中间最快,猜测与序列的有序程度有关,取中间值能降低递归深度,可以拿一个逆序序列带入), i为左区间选择的值的序号（左针），j为右区间选择的序号（右针）
    handle(num, tmp, i, j); //对选取的区间进行处理
    quick_sort(num, l, j); //对选取的左边和右边的范围如法炮制（中间有个值将被空出来，因为单个数字为有序）
    quick_sort(num, i, r);
    return ;
}

int main() {
    int num[100005], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    quick_sort(num, 0, n - 1); //快排
    for (int i = 0; i < n; i++) {
        i && putchar(' ');
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}
