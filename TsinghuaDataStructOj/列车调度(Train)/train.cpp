#include <iostream>
#include <cstring>
using namespace std;
template <class E>
class Stack{
public:
    E * data;int len;int capacity;
    Stack(int capacity) : capacity(capacity),len(0),data(new E[capacity]) {}
    void push(E e){ data[len++] = e; }
    E pop(){ return data[--len]; }
    E top(){ return data[len-1]; }
    bool isEmpty(){ return len == 0; }
    int getLen() const { return len; }
};
int len = 0;
char str[50000000];int  A[1600010]; int B[1600010]; Stack<int> S(1600010);
bool validateStackPermutation(int n,int m, char * str){
    int x = 0;int y = 0;
    for (int i = 0; i < n; ++i){
        A[i] = i+1; cin >> B[i];
    }
    while (x < n){
        S.push(A[x++]); strcpy(str+len,"push\n");len+=5;
        if (S.getLen() > m) break;
        while ((!S.isEmpty()) && (B[y] == S.top())){
            S.pop(); y++; strcpy(str+len,"pop\n");len+=4;
        }
    }
    if (S.isEmpty()) return true;
    else return false;
}
int main() {
    int n =0; int m =0;
    cin >> n >> m;
    if (validateStackPermutation(n, m, str)){
        cout << str;
    }else cout << "No\n";
    return 0;
}
