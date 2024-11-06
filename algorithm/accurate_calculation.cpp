#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//以下输入是倒序输入，输入的个位在前面
//函数没有reverse的输出是倒序，除法除外
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
    reverse(result.begin(),result.end());
    return result;
}

vector<int> multi_1(const vector<int> &A,const int &b){
    vector<int> result;
    int carry=0,i=0;
    while (i<A.size() || carry){
        if (i<A.size()) carry+=A[i++]*b;
        result.push_back(carry%10);
        carry/=10;
    }
    reverse(result.begin(),result.end());
    return result;
}

vector<int> multi_2(const vector<int> &A,const vector<int> &B){
    vector<int> result(A.size()+B.size(),0);
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            result[i+j]+=A[i]*B[j];
            result[i+j+1]+=result[i+j]/10;
            result[i+j]%=10;
        }
    }
    while (result.size()>1 && result.back()==0) result.pop_back();
    reverse(result.begin(),result.end());
    return result;
}

vector<int> div_1(const vector<int> &A,const int &b,int &r){
    vector<int> result;
    r=0;
    for (int i=A.size()-1; i>=0; --i) {
        r=r*10+A[i];
        result.push_back(r/b);
        r%=b;
    }
    while (result.size()>1 && result.front()==0) result.erase(result.begin());
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

//    multiply_Big*Int
//    int a_1;
//    cin>>a_1;
//    result= multi_1(A,a_1);

//    multiply_Big*Big
//    result= multi_2(A,B);

//    div_Big/Int
//    int r;//r是余数

    for (int it:result) cout<<it;
    cout<<endl;
    return 0;
}
