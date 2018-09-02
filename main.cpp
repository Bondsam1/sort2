 //
//  main.cpp
//  排序2
//
//  Created by bondsam on 31/05/2018.
//  Copyright © 2018 bondsam. All rights reserved.
//

#include<iostream>
using namespace std;

void Insertsort(int r[], int n, int*compare, int *move)
{
    *compare = 0;
    *move = 0;
    int i, j;
    for (i = 1; i < n; i++)
    {
        int x = r[i];
        for (j = i-1; x < r[j]&&j>=0; j--)
        {
            (*compare)++;
            (*move)++;
            r[j + 1] = r[j];
        }
        if (j >= 0)
        (*compare)++;
        r[j + 1] = x;
    }
}

void ShellSort(int r[], int n, int*compare, int*move)
{
    *compare = 0;
    *move = 0;
    int j;
    for (int d = n / 2; d >= 1; d = d / 2)
    {
        for (int i = d; i < n; i++)
        {
            if (r[i] < r[i - d])
            {
                int x = r[i];
                for (j = i - d; (j >= 0) && (x < r[j]); j = j - d)
                {
                    (*compare)++;
                    (*move)++;
                    r[j + d] = r[j];
                }
                if(j>=0)
                (*compare)++;
                r[j + d] = x;
            }
            else
            (*compare)++;
        }
    }
}

void BubbleSort(int r[], int n, int*compare, int *move)
{
    *compare = 0;
    *move = 0;
    int x;
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = n - 1; i > j; i--)
        {
            if (r[i] < r[i - 1])
            {
                (*compare)++;
                (*move) += 3;
                x = r[i];
                r[i] = r[i - 1];
                r[i - 1] = x;
            }
            else
            (*compare)++;
        }
    }
}

int Partion(int r[], int first, int end, int *compare, int *move)
{
    int i = first;
    int j = end;
    int zhou = r[i];
    while (i < j)
    {
        while ((i < j) && (r[j] >= zhou))
        {
            (*compare)++;
            j--;
        }
        if (i < j)
        {
            (*compare)++;
            (*move)++;
            r[i] = r[j];
        }
        while ((i < j) && (r[i] <= zhou))
        {
            (*compare)++;
            i++;
        }
        if (i < j)
        {
            (*compare)++;
            (*move)++;
            r[j] = r[i];
        }
    }
    r[i] = zhou;
    return i;
}
void Qsort(int r[], int i, int j, int*compare, int*move)
{
    if (i < j)
    {
        int centre = Partion(r, i, j, compare, move);
        Qsort(r, i, centre - 1, compare, move);
        Qsort(r, centre + 1, j, compare, move);
    }
}

void Selectsort(int r[], int n, int *compare, int *move)
{
    *compare = 0;
    *move = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            (*compare)++;
            if (r[j] < r[min])
            min = j;
        }
        if (min != i)
        {
            (*move) += 3;
            int Min;
            Min = r[min];
            r[min] = r[i];
            r[i] = Min;
        }
    }
}

int main()
{
    int i;
    int compare = 0;
    int move = 0;
    int n;
    cout << "输入元素数量：" << endl;
    cin >> n;
    int *r = new int[n];
    cout << "请输入数组中的元素" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    int *a = new int[n];
    for (i = 0; i < n; i++)
    {
        a[i] = r[i];
    }
    Insertsort(a, n, &compare, &move);
    cout << "直接插入排序结果为：";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n直接插入排序比较次数为：" << compare;
    cout << "\n直接插入排序移动次数为：" << move << endl;
    int *b = new int[n];
    for (i = 0; i < n; i++)
    {
        b[i] = r[i];
    }
    ShellSort(b, n, &compare, &move);
    cout << "希尔排序结果为：";
    for (i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n希尔排序比较次数为：" << compare;
    cout << "\n希尔排序移动次数为：" << move << endl;
    int*c = new int[n];
    for (i = 0; i < n; i++)
    {
        c[i] = r[i];
    }
    BubbleSort(c, n, &compare, &move);
    cout << "冒泡排序结果为：";
    for (i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << "\n冒泡排序比较次数为：" << compare;
    cout << "\n冒泡排序移动次数为：" << move << endl;
    compare = 0;
    move = 0;
    int *d = new int[n];
    for (i = 0; i < n; i++)
    {
        d[i] = r[i];
    }
    Qsort(d, 0, n - 1, &compare, &move);
    cout << "快速排序结果为：";
    for (i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    cout << "\n快速排序比较次数为：" << compare;
    cout << "\n快速排序移动次数为：" << move << endl;
    int *e = new int[n];
    for (i = 0; i < n; i++)
    {
        e[i] = r[i];
    }
    Selectsort(e, n, &compare, &move);
    cout << "选择排序结果为：";
    for (i = 0; i < n; i++)
    {
        cout << e[i] << " ";
    }
    cout << "\n选择排序比较次数为：" << compare;
    cout << "\n选择排序比移动较次数为：" << move << endl;
    system("pause");
    delete[]a;
    delete[]b;
    delete[]c;
    delete[]e;
    delete[]r;
}
