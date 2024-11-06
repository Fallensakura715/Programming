#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 10010

int n,m,q;
int a[N][N]={0},diff[N][N]={0};

//二维差分(diff)
//a和diff都初始为0，以插入的形式，把a元素插入diff数组
//diff数组不等于a数组,插入值后(+=c) 后面的还-=c了,与a[i]-a[i-1]效果差不多的

void insert(int x1,int y1,int x2,int y2,int c){
    diff[x1][y1]+=c;
    diff[x2+1][y1]-=c;
    diff[x1][y2+1]-=c;
    diff[x2+1][y2+1]+=c;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
        }
    }
    while (q--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
            cout<<diff[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}