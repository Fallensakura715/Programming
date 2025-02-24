#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    vector<int> res(n, -1);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        while (!s.empty() && x <= s.top()) {
            res[s.top()] = x;
            s.pop();
        }

        s.push(x);
    }

    for (auto& t : res) cout << t << " ";
    return 0;
}
