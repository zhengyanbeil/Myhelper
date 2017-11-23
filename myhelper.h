#ifndef MYHELPER_H
#define MYHELPER_H

#include <vector>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct List
{
    int data;
    struct List* next;
} List;

typedef struct HashTable
{
    int arr[10] = {0};
    int key = 0;
    int addr_key = -1;
    const int (*hash_func)(const int key) = nullptr;
    const int (*collision)(const int key) = nullptr;
}HashTable;

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
        static bool hash_search(HashTable &h);
        static bool hash_insert(HashTable &h);

        //其他
        static void swap(int* p, int* q);

        //字符串查找
        static int substring(const char* s, const char* t, const int pos);
        static int substring_count(const char* s, const char* t, const int pos);

        //链表操作
        static List* create_list(int len);
        static void travel_list(List* head);
        static void reverse_list(List* head);

        //数学计算
        static void prime_factorization(unsigned int n,
                                        vector<unsigned int>& vec_factor);

        //字符转换
        static int hexchar_to_int(char c);
        static void hexstring_to_bytes(char* hexstring, char* bytes, int hexlength);
        static void bytes_to_hexstring(unsigned char* bytes, int bytelength,
                                       char* hexstring, int hexstrlength);

    private:
        static const char hex_letter_table[16];
        MyHelper() = delete;
        MyHelper(const MyHelper&) = delete;
        MyHelper operator =(const MyHelper&) = delete;
};

#endif // MYHELPER_H
