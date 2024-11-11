#include <iostream>
using namespace std;
#define N 100

int n;
char path[N][N];
bool dg[N],udg[N],col[N];
//全排列解法
void dfs(int u) {
    if (n == u) {
        for (int i = 0; i < n; ++i) {
            puts(path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        //对角线下标想象成一次函数的截距，row和col想象成x和y  +n是防止<0
        if (!dg[u-i+n] && !udg[i+u] && !col[i]) {
            path[u][i] = 'Q';
            col[i]=dg[u-i+n]=udg[u+i]= true;
            dfs(u + 1);
            path[u][i] = '.';
            col[i]=dg[u-i+n]=udg[u+i]= false;
        }
    }
}

int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            path[i][j]='.';
        }
    }
    dfs(0);
    return 0;
}
