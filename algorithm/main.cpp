#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 100010
int r[N]={0};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int &it:a) cin>>it;
    int maxlen=1;
    for (int i=0,j=0;i<n;++i) {
        r[a[i]]++;
        while (r[a[i]]>1) {
            r[a[j]]--;
            j++;
        }
        maxlen=max(maxlen,i-j+1);
    }
    cout<<maxlen<<endl;
    return 0;
}