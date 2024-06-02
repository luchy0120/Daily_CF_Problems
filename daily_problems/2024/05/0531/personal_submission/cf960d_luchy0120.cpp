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

    vector<long long> m(63);
    int q;cin >> q;
    for (int i = 0;i < q;++i) {
        long long t, x, k;cin >> t;
        if (t == 1) {
            cin >> x >> k;
            long long xx = x;
            long long ht = 0;
            while (xx != 1) {
                ht++;
                xx /= 2;
            }
            long long mod = 1LL << ht;
            m[ht] += k % mod;
        } else if(t==2){
            cin >> x >> k;
            long long xx = x;
            long long ht = 0;
            while (xx != 1) {
                ht++;
                xx /= 2;
            }
            long long c = 1;
            while (ht < 63) {
                long long mod = 1LL << ht;
                m[ht] += c*k;
                m[ht] %= mod;
                m[ht] += mod;
                m[ht] %= mod;
                c *= 2;
                ht++;
            }
        }
        else {
            cin >> x;
            long long xx = x;
            long long ht = 0;
            while (xx != 1) {
                ht++;
                xx /= 2;
            }

            long long mod = 1LL << ht;
            long long fst = mod;
            long long d = x - fst;

            long long pos =  (fst + (((d + m[ht]) % mod + mod) % mod));

            while (pos != 1) {

                long long mod = 1LL << ht;
                long long fst = mod;
                long long d = pos - fst;

                cout << (fst + (((d - m[ht]) % mod + mod) % mod)) << " ";
               

                pos /= 2;
                ht--;
            }
            cout << 1 << endl;

        }
    }




    return 0;
}