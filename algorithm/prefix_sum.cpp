#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//一维前缀和
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1),s(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>v[i];
    }
    for (int i = 1; i <= n; ++i) {
        s[i]=s[i-1]+v[i];
    }
    while (m--) {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}
//二维前缀和
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    vector<vector<int>> s(n+1,vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>v[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j]=v[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    while (q--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]<<endl;
    }
    return 0;
}
