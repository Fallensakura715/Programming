#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 110

typedef pair<int,int> PII;
int n,m;
int graph[N][N],went[N][N];//went数组是每一个点到起点的距离
PII q[N*N],Prev[N][N];//q是模拟队列 里面存路径点的坐标x,y,Prev是路径


int bfs(){
    int hh=0,tt=0;//hh是队头，tt是队尾
    q[0]={0,0};
    memset(went,-1, sizeof(went));
    went[0][0]=0;

    //扩展用的向量
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    while (hh<=tt) {//队列不空
        auto t=q[hh++];//t是队列头部的点，取出来个队头
        for (int i = 0; i < 4; ++i) {//队头往上下左右四个方向扩展
            int x=t.first+dx[i],y=t.second+dy[i];//(x,y)是t点扩展后的坐标
            if (x>=0 && x<n && y>=0 && y<n && graph[x][y]==0 && went[x][y]==-1) {//没出界，能走，没走过
                went[x][y]=went[t.first][t.second]+1;//该点的距离+1
                Prev[x][y]=t;//把对头存储进路径里
                q[++tt]={x,y};//把扩展后的点扔进队尾
            }
        }
    }

    //输出路径
    int x=n-1,y=m-1;
    while (x||y) {
        cout<<x<<" "<<y<<endl;
        auto t= Prev[x][y];
        x=t.first,y=t.second;
    }

    return went[n-1][m-1];
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&graph[i][j]);
        }
    }
    cout<<bfs()<<endl;
    return 0;
}