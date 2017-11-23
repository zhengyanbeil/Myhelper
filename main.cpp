#include <iostream>
#include <myhelper.h>

using namespace std;

#define MOD_NUM 10

const int mod_hash_func(const int key)
{
    return key % MOD_NUM;
}

const int linear_explore_rehash(const int key)
{
    static unsigned int acc_idx = 1;
    return mod_hash_func((key + acc_idx++) % MOD_NUM);
}

int main()
{
    HashTable h;
    while (cin >> h.key)
    {
        h.hash_func = mod_hash_func;
        h.collision = linear_explore_rehash;
        cout << MyHelper::hash_insert(h) << endl;
        for(auto it_b = begin(h.arr); it_b != end(h.arr); it_b++)
            cout << *it_b << " ";
        cout << endl;
    }
}
