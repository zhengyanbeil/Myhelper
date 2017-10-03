#ifndef MYHELPER_H
#define MYHELPER_H

#include <vector>
#include <cstring>
#include <time.h>

using namespace std;

extern "C" {
    class MyHelper
    {
        public:
            //插入排序
            static void insert_sort_with_binary_search(int* p, int len);
            static void insert_sort_normal(int* p, int len);
            static void insert_sort_slow(int* p, int len);
            static void shell_sort(int* p, const int len);

            //交换排序
            static void quick_sort(int* p, int head, int tail);
            static int quick_partition(int* p, int head, int tail);
            static void bubble_sort(int* p, int len);

            //选择排序
            static void select_sort(int* p, const int len);
            static void adjust_from_up_to_down(int* p, const int len, const int idn_root);
            static void heap_sort(int* p, int len);

            //查找
            static bool bin_apart(vector<int>& v, int tgt);

            //其他
            static void swap(int* p, int* q);

            //字符串查找
            static int substring(const char *s, const char *t, const int pos);
            static int substring_count(const char *s, const char *t, const int pos);
    };
}
#endif // MYHELPER_H
