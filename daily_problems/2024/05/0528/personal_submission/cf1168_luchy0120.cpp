#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;cin >> s;
    int n = s.size();

    vector<int> rt(n, n);
    for (int k = 1;k <= n / 2 && k <= 4;++k) {
        for (int i = 0;i + k + k < n;++i) {
            if (s[i] == s[i + k] && s[i] == s[i + 2 * k]) {
                rt[i] = min(rt[i],i + 2 * k);
            }
        }
    }
    long long res = 0;
    for (int i = n - 2;i >= 0;--i) {
        rt[i] = min(rt[i], rt[i + 1]);

        if (rt[i] < n) {
            res += n - rt[i];
        }
    }
    cout << res;



    return 0;
}