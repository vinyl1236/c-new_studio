#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int N = 2005;
int f[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }

    // 1. 排序 (所有相同的数字都会挨在一起)
    sort(f, f + n);
    
    // 2. 直接使用标准库去重！
    // unique 返回的是去重后“新数组结束位置”的指针
    int new_len = unique(f, f + n) - f; 

    // 3. 完美输出（没有多余的末尾空格）
    cout << new_len << endl;
    for(int i = 0; i < new_len; i++) {
        if(i > 0) cout << ' ';
        cout << f[i];
    }

    return 0;
}
