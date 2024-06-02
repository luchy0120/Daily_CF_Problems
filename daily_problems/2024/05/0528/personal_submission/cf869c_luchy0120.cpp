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

    long long mod = 998244353;
    c[0][0] = 1;
    f[0] = 1;
    for (int j = 1;j <= 5000;++j) {
        f[j] = f[j - 1] * j;
        f[j] %= mod;
        c[j][0] = c[j][j] = 1;
        for (int i = 1;i < j;++i) {
            c[j][i] = c[j - 1][i] + c[j - 1][i - 1];
            c[j][i] %= mod;
        }
    }

    int x, y, z;cin >> x >> y >> z;
    
    

    auto d = [&](int x,int y) {
        long long s = 0;
        for (int i = 0;i <= min(x, y);++i) {
            s += c[x][i] * c[y][i] % mod * f[i] % mod;
            s %= mod;
        }
        return s;
    };
    long long r = d(x, y) * d(y, z) % mod * d(x, z) % mod;
    cout << r;




    return 0;
}