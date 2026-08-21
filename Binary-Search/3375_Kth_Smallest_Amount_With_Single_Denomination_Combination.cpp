// Problem   : 3375. Kth Smallest Amount With Single Denomination Combination
// Difficulty: Hard
// Tags      : Array, Math, Binary Search, Bit Manipulation, Combinatorics, Number Theory
// URL       : https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    long long lcmll(long long a, long long b) {
        return a / gcdll(a, b) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto count = [&](long long x) {
            long long res = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        l = lcmll(l, coins[i]);
                        if (l > x) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) continue;
                if (__builtin_popcount(mask) & 1)
                    res += x / l;
                else
                    res -= x / l;
            }
            return res;
        };
        long long lo = 1, hi = 1e18;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};