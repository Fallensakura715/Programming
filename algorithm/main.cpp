#include <iostream>
using namespace std;
#define N 100

int n;
char path[N][N];
bool dg[N],udg[N],col[N];

void dfs(int u) {
    if (n == u) {
        for (int i = 0; i < n; ++i) {
            puts(path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
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