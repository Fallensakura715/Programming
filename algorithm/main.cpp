#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1),s(n+1);
    s[0]=0;
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