#include "myhelper.h"

bool MyHelper::bin_apart(vector<int>& v, int tgt)
{
    auto it_begin = v.cbegin();
    auto it_end = v.cend();
    auto it_mid = it_begin + (it_end - it_begin) / 2;
    while (it_mid != it_end && *it_mid != tgt)
    {
        if (*it_mid < tgt)
            it_begin = it_mid + 1;
        else
            it_end = it_mid;
        it_mid = it_begin + (it_end - it_begin) / 2;
    }
    return (tgt == *it_mid) ? true : false ;
}

void MyHelper::bubble_sort(int* p, int len)
{
    for (int i = 0; i < len ; i++)
    {
        for (int j = 0; j < len - 1 - i ; j++)
        {
            if (p[j] > p[j + 1]) //大数后移
            {
                int tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
}


void MyHelper::insert_sort_with_binary_search(int* p, int len)
{
    int t = 0;
    for (int i = 1; i < len; i++)
    {
        if (p[i] < p[i - 1]) //升序
        {
            t = p[i];
            int low = 0, height = i - 1, mid;
            while (low < height)
            {
                mid = (height + low) / 2;
                if (p[mid] < t)
                    low = mid + 1;
                else
                    height = mid - 1;
            }
            int j;
            for (j =  i - 1; j >= low; j--)
                p[j + 1] = p [j];
            p[j + 1] = t;
        }
    }
}

void MyHelper::insert_sort_normal(int* p, int len)
{
    int t = 0;
    for (int i = 1; i < len; i++)
    {
        if (p[i] < p[i - 1]) //升序
        {
            t = p[i];
            int j;
            for (j = i - 1; p[j] > t && j >= 0; j--)
                p[j + 1] = p[j]; //p[j]空出
            p[j + 1] = t;  //p[j]的上一数已空出
        }
    }
}

void MyHelper::insert_sort_slow(int* p, int len)
{
    int t = 0;
    for (int i = 1; i < len; i++)
    {
        if (p[i] < p[i - 1]) //升序
        {
            t = p[i];
            int j;
            for (j = i - 1; p[j] > t && j >= 0; j--)
            {
                int tmp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = tmp;
            }
        }
    }
}

void MyHelper::select_sort(int* p, const int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < len; j++)
        {
            if (p[j] < p[min_ind])
                min_ind = j;
        }
        if (min_ind != i)
        {
            int tmp = p[i];
            p[i] = p[min_ind];
            p[min_ind] = tmp;
        }
    }
}

void MyHelper::shell_sort(int* p, const int len)
{
    int d, i, j, k, tgt;
    for (d = len / 2; d != 0; d = d / 2)//增量
    {
        for (i = 0; i < d; i++) //在一种增量下，所有可能的分组
        {
            for (j = i + d; j < len; j = j + d) //对一个分组进行直接插入排序
            {
                if (p[j] < p[j - d])
                {
                    tgt = p[j];
                    for (k = j - d; p[k] > tgt && k >= 0 ; k = k - d)
                        p[k + d] = p[k];
                    p[k + d] = tgt;
                }
            }
        }
    }
}

void MyHelper::quick_sort(int* p, int head, int tail)
{
    int k;
    if (head < tail)
    {
        k = quick_partition(p, head, tail);
        quick_sort(p, head, k - 1);
        quick_sort(p, k + 1, tail);
    }
}

int MyHelper::quick_partition(int* p, int head, int tail)
{
    int tgt = p[head];
    int i = head;
    int j = tail;
    while (i < j)
    {
        while (p[j] > tgt && i < j)
            j--;
        p[i] = p[j];
        while (p[i] < tgt && i < j)
            i++;
        p[j] = p [i];
    }
    p[i] = tgt;
    return i;
}

void MyHelper::adjust_from_up_to_down(int* p, const int len, const int idn_root)
{
    int i = idn_root;
    for (int j = i * 2 + 1; j < len;
         j = j * 2 + 1)//自上而下调整子树，形成小根堆
    {
        if (j+1 < len && p[j] > p[j + 1]) //左子节点 > 右子节点
        {
            j++;
            if (p[(j - 2) / 2] < p[j]) //父节点 < 子节点
                break;
            else     //父节点 > 子节点，则交换父子节点
            {
                int tmp = p[(j - 2) / 2];
                p[(j - 2) / 2] = p[j];
                p[j] = tmp;
            }
        }
        else //左子节点 < 右子节点
        {
            if (p[j / 2] < p[j]) //父节点 < 子节点
                break;
            else     //父节点 > 子节点，则交换父子节点
            {
                int tmp = p[j / 2];
                p[j / 2] = p[j];
                p[j] = tmp;
            }
        }
    }
}

void MyHelper::build_min_heap(int* p, const int len)
{
    for (int i = len / 2; i >= 0; i--)//自下而上遍历所有子树的根节点
    {
        adjust_from_up_to_down(p, len, i);//调整第i棵子树，形成小根堆
    }
}

void MyHelper::heap_sort(int* p, const int len)
{
    build_min_heap(p, len); //最小值在root
    for (int i = len - 1;  i > 0; i--)
    {
        int tmp = p[i];
        p[i] = p[0];
        p[0] = tmp;
        adjust_from_up_to_down(p, i, 0);
    }
}
