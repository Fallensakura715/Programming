#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp_sub_vector(const vector<int> &A,const vector<int> &B){
    if (A.size()!=B.size()) return A.size()>B.size();
    for (int i = A.size()-1; i >= 0; --i)
        if (A[i]!=B[i]) return A[i]>B[i];
    return true;
}

vector<int> sub(const vector<int> &A,const vector<int> &B){
    vector<int> result;
    int temp=0;
    for (int i = 0; i < A.size(); ++i) {
        temp= A[i] - temp;
        if (i<B.size()) temp -= B[i];
        result.push_back((temp + 10) % 10);
        if (temp < 0) temp=1;
        else temp=0;
    }
    while (result.size()>1 && result.back()==0) result.pop_back();
//    reverse(result.begin(),result.end());
    return result;
}

vector<int> add(const vector<int> &A,const vector<int> &B){
    vector<int> result;
    int carry=0,i=0,j=0;
    while (i<A.size() || j<B.size() || carry){
        if (i<A.size()) carry+=A[i++];
        if (j<B.size()) carry+=B[j++];
        result.push_back(carry%10);
        carry/=10;
    }
//    reverse(result.begin(),result.end());
    return result;
}

int main(){
    string a,b;
    vector<int> A,B,result;
    cin>>a>>b;
    for (int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');
    for (int i=b.size()-1;i>=0;--i) B.push_back(b[i]-'0');

//    add
//    result=add(A,B);

//    sub
//    bool c= cmp_sub_vector(A,B);
//    cout<<c<<endl;
//    if (cmp_sub_vector(A,B)) {
//        result= sub(A,B);
//    }else{
//        result= sub(B,A);
//        cout<<"-";
//    }
    for (int i = result.size()-1; i >= 0; --i) cout<<result[i];
    cout<<endl;
    return 0;
}
