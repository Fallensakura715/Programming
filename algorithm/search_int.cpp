#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for (int &i:a){
        cin>>i;
    }
    while (q--){
        int k;
        cin>>k;
        int l=0,r=n-1;
        while (l<r){
            int mid=(l+r)/2;
            if (a[mid]>=k) r=mid;
            else l=mid+1;
        }
        if (a[l]!=k) {
            cout<<"-1 -1"<<endl;
            break;
        }
        else {
            cout<<l<<" ";
            l=0,r=n-1;
            while (l < r) {
                int mid=(l+r+1)/2;
                if (a[mid]<=k) l=mid;
                else r=mid-1;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}
