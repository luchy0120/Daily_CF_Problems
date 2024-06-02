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

    int t;cin >> t;

    for (int u = 0;u < t;++u) {

        int n; cin >> n;
        long long x;cin >> x;
        vector<long long> a(n);
        long long ans = 0;
        for (int i = 0;i < n;++i) {
            cin >> a[i];
            if (i >= 1) {
                ans += abs(a[i] - a[i - 1]);
            }
        }
        long long mx = *max_element(a.begin(), a.end());
        long long mi = *min_element(a.begin(), a.end());

        if (x > mx) {
            int v = min(x - max(a[0], a[n - 1]), 2 * (x - mx));
            ans += v;
        }
        if (1 < mi) {
            int v = min(min(a[0], a[n - 1]) - 1, 2 * (mi - 1));
            ans += v;
        }
        cout << ans << endl;


    }


    return 0;
}