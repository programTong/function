#include <iostream>
using namespace std;
int binarySearchBAE(int * seq, int n, int query){
    int low = 0; int high = n - 1;
    while (low <= high){
        int mid = low + ((high - low) >> 1);
        if (seq[mid] >= query)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low < n ? low : -1;
}
int binarySearchLAE(int * seq, int n, int query){
    int low = 0; int high = n - 1;
    while (low <= high){
        int mid = low + ((high - low) >> 1);
        if (seq[mid] > query)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high >= 0 ? high : -1;
}
int cmp(const void * a, const void *b){
    return *((int *)a) - *((int *)b);
}
int main() {
    int n = 0; int m = 0;cin >> n >> m;
    int * inSeq = new int [n];
    for (int i = 0; i < n; ++i)
        cin >> inSeq[i];
    qsort(inSeq, n, sizeof(int), cmp);
    for (int i = 0; i < m; ++i) {
        int p = 0; int q = 0;cin >> p >> q;
        if (p > inSeq[n-1] || q < inSeq[0]){
            cout << 0 << endl;
        }else{
            int t1 = binarySearchBAE(inSeq, n, p);
            int t2 = binarySearchLAE(inSeq, n, q);
            cout << t2 - t1 + 1 << endl;
        }
    }
    return 0;
}
