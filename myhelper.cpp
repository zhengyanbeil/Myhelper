#include "myhelper.h"

//using namespace MyHelper_namespace;

const char MyHelper::hex_letter_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

bool MyHelper::bin_apart(vector<int> &v, int tgt)
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

void MyHelper::bubble_sort(int *p, int len)
{
    for (int i = 0; i < len ; i++)
    {
        for (int j = 0; j < len - 1 - i ; j++)
        {
            if (p[j] > p[j + 1]) //大数后移
            {
                swap(p + j, p + (j + 1));
            }
        }
    }
}


void MyHelper::insert_sort_with_binary_search(int *p, int len)
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

void MyHelper::insert_sort_normal(int *p, int len)
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

void MyHelper::insert_sort_slow(int *p, int len)
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
                swap(p + j, p + (j + 1));
            }
        }
    }
}

void MyHelper::select_sort(int *p, const int len)
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
            swap(p + min_ind, p + i);
        }
    }
}

void MyHelper::shell_sort(int *p, const int len)
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

void MyHelper::quick_sort(int *p, int head, int tail)
{
    int k;
    if (head < tail)
    {
        k = quick_partition(p, head, tail);
        quick_sort(p, head, k - 1);
        quick_sort(p, k + 1, tail);
    }
}

int MyHelper::quick_partition(int *p, int head, int tail)
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

void MyHelper::adjust_from_up_to_down(int *p, const int len, const int idn_root)
{
    int i = idn_root;
    for (int j = i * 2 + 1; j < len;
            j = j * 2 + 1)//自上而下调整子树，形成小根堆
    {
        if (j + 1 < len && p[j] > p[j + 1]) //左子节点 > 右子节点
            j++;
        if (p[i] < p[j]) //父节点 < 子节点
            break;
        else     //父节点 > 子节点，则交换父子节点
            swap(p + i, p + j);
        i = j;  //切换至新新子树的根节点
    }
}

void MyHelper::heap_sort(int *p, const int len)
{
    //最小值在root
    for (int i = len / 2; i >= 0; i--)//自下而上遍历所有子树的根节点
    {
        adjust_from_up_to_down(p, len, i);//调整第i棵子树，形成小根堆
    }
    for (int i = len - 1;  i > 0; i--)
    {
        swap(p, p + i);
        adjust_from_up_to_down(p, i, 0);
    }
}

void MyHelper::swap(int *p, int *q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

int MyHelper::substring(const char *s, const char *t, const int pos)
{
    int i = pos, j = 0;
    int len_s = strlen(s);
    int len_t = strlen(t);
    while (i < len_s && j < len_t)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j != len_t) //若子串未匹配完毕，说明检索失败
        return -1;
    else
        return i - j;
}

int MyHelper::substring_count(const char *s, const char *t, const int pos)
{
    int sum = 0, i = pos, loc = 0;
    do {
        loc = substring(s, t, i);
        if (-1 != loc)
        {
            sum++;
            i = loc + strlen(t);
        }
        else {
            break;
        }
    } while (1);
    return sum;
}

List *MyHelper::create_list(int len)
{
    List *p = NULL, *q = NULL, *head = NULL;
    while (len)
    {
        p = (List *)malloc(sizeof(List));
        if (NULL == p)
        {
            cout << "no memory...";
            break;
        }
        p->data = len;
        p->next = NULL;
        if (NULL == head)
            head = p;
        else
            q->next = p;
        q = p;
        p = p->next;
        len--;
    }
    return head;
}

void MyHelper::travel_list(List *head)
{
    List *p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

void MyHelper::reverse_list(List *head)
{
    List *pre = head;
    List *cur = head;
    List *nex = head->next;
    cur->next = NULL;
    cur = nex;
    nex = nex->next;
    while (cur)
    {
        cur->next = pre;
        pre = cur;
        cur = nex;
        if (nex != NULL)
            nex = nex->next;
    }
    head = pre;
}

void MyHelper::prime_factorization(unsigned int n, vector<unsigned int> &vec_factor)
{
    unsigned int factor = 2;
    if (n == 1 || n == 2)
        return;
    while (n % factor != 0)
        ++factor;
    n = n / factor;
    vec_factor.push_back(factor);
    prime_factorization(n, vec_factor);
}

int MyHelper::hexchar_to_int(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    return -1;
}

void MyHelper::hexstring_to_bytes(char *hexstring, char *bytes, int hexlength)
{
    //printf("length is : %ld\n", sizeof(hexstring) / sizeof(char));
    for (int i = 0 ; i < hexlength ; i += 2)
    {
        bytes[i / 2] = (char) ((hexchar_to_int(hexstring[i]) << 4) | hexchar_to_int(hexstring[i + 1]));
    }
}

void MyHelper::bytes_to_hexstring(unsigned char *source_u_char_array, int arraylength, char *dest_hexstring, int hexstrlength)
{
    int b;
    for (int i = 0, j = 0; i < arraylength && j < hexstrlength; i++, j++)
    {
        b = 0x0f & (source_u_char_array[i] >> 4);
        dest_hexstring[j++] = hex_letter_table[b];
        b = 0x0f & source_u_char_array[i];
        dest_hexstring[j] = hex_letter_table[b];
    }
}
