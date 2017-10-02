#ifndef MYHELPER_H
#define MYHELPER_H

#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;
class MyHelper
{
    public:
        static bool bin_apart(vector<int>& v, int tgt);
        static void bubble_sort(int* p, int len);
        static void shell_sort(int* p, const int len);
        static void build_min_heap(int* p, const int len);
        static void heap_sort(int *p, int len);
        static void quick_sort(int* p, int head, int tail);
        static int quick_partition(int* p, int head, int tail);
        static void insert_sort_with_binary_search(int *p, int len);
        static void insert_sort_normal(int *p, int len);
        static void insert_sort_slow(int *p, int len);
        static void select_sort(int *p, const int len);
        static void adjust_from_up_to_down(int *p, const int len, const int idn_root);
};

#endif // MYHELPER_H
