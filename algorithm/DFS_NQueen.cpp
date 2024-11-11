#include <iostream>
using namespace std;
#define N 20

int n;
char path[N][N];
bool dg[N],udg[N],col[N];
//全排列解法 u是row
void dfs(int u) {
    if (n==u) {
        for (int i = 0; i < n; ++i) {
            puts(path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        //对角线下标想象成一次函数的截距，row和col想象成x和y  +n是防止(u-i)<0
        if (!dg[u-i+u] && !udg[i+u] && !col[i]) {
            path[u][i]= 'Q';
            col[i]=dg[u-i+n]=udg[u+i]= true;
            dfs(u+1);
            path[u][i]= '.';
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

//原始解法
#include <iostream>
using namespace std;
#define N 20

int n;
char path[N][N];
bool row[N],col[N],dg[N],udg[N];

void dfs(int x,int y,int queen) {
    if (y==n) x++,y=0;
    if (x==n) {
        if (queen==n) {
            for (int i = 0; i < n; ++i) {
                puts(path[i]);
            }
            cout<<endl;
        }
        return;
    }
    //不放皇后
    dfs(x,y+1,queen);
    //放皇后
    if (!dg[x-y+n] && !udg[x+y] && !row[x] && !col[y]) {
        dg[x-y+n]=udg[x+y]=row[x]=col[y]= true;
        path[x][y]='Q';
        dfs(x,y+1,queen+1);
        dg[x-y+n]=udg[x+y]=row[x]=col[y]= false;
        path[x][y]='.';
    }
}

int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            path[i][j]='.';
        }
    }
    dfs(0,0,0);
    return 0;
}
