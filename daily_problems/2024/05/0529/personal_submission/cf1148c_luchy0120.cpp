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

const int N = 5001;
long long c[N][N];
long long f[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;cin >> n;
    vector<int> c(n + 1);
    vector<int> p(n + 1);
    for (int i = 1;i <= n;++i) {
        cin >> c[i];
        p[c[i]] = i;
    }
    vector<array<int, 2>> vs;
    auto sw = [&](int a,int b) {
        vs.push_back({ a,b });
        swap(c[a], c[b]);
        p[c[a]] = a;
        p[c[b]] = b;
    };

    for (int i = 1;i <= n;++i) {
        if (p[i] - 1 >= n / 2) {
            sw(p[i], 1);

            if (abs(1 - i) >= n / 2) {
                sw(1, i);
            }
            else {
                sw(1, n);
                sw(i, n);
            }


        }
        else {
            sw(p[i], n);

            if (abs(n - i) >= n / 2) {
                sw(n, i);
            }
            else {
                sw(1, n);
                sw(i, 1);
            }
        }
        
        
    }
    cout << vs.size() << endl;

    for (auto h : vs) {
        cout << h[0] << " " << h[1] << endl;
    }




    return 0;
}