#include <iostream>
#include <vector>

using namespace std;

class BinaryIndexedTree {
private:
    vector<int> BIT; 
    int n;

    int lowbit(int x) { return x & (-x); }

public:
    BinaryIndexedTree(int size) {
        n = size;
        BIT.resize(n + 1, 0);
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= lowbit(idx);//把下面的都加起来,从idx往下找
        }
    }

    void update(int idx, int value) {
        while (idx <= n) {
            BIT[idx] += value;
            idx += lowbit(idx);//把上面覆盖到的数全都 update value,从idx往上找
        }
    }

    int queryRange(int left, int right) {
        return query(right) - query(left - 1);
    }

    void buildFromArray(const vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            update(i + 1, arr[i]);
        }
    }

};

int main() {
    return 0;
}