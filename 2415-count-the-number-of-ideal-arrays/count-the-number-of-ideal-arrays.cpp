static constexpr int MOD = 1'000'000'007;
long long modPow(long long x, long long p=MOD-2) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return res;
}

class Solution {
public:
    int N, maxVal;
    vector<long long> fact, invFact;
    unordered_map<int, unordered_map<int,int>> memo;

    // Precompute factorials and inverse factorials up to n
    void initFactorials(int n) {
        fact.resize(n+1);
        invFact.resize(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
        invFact[n] = modPow(fact[n]);
        for (int i = n; i > 0; --i)
            invFact[i-1] = invFact[i] * i % MOD;
    }

    // nCk % MOD
    int comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return int(fact[n] * (invFact[k] * invFact[n-k] % MOD) % MOD);
    }

    int rec(int k, int val) {
        if (k == N) {
            // exactly N distinct picks → only one arrangement of first‐occurrences
            return comb(N-1, k-1);
        }

        auto &row = memo[k];
        auto it = row.find(val);
        if (it != row.end()) return it->second;

        // Option 1: stop here
        long long cnt = comb(N-1, k-1);

        // Option 2: extend chain by multiplying
        for (int m = 2; m * val <= maxVal; ++m) {
            cnt = (cnt + rec(k+1, val*m)) % MOD;
        }

        return row[val] = int(cnt);
    }

    int idealArrays(int n, int maxValue) {
        N = n;
        maxVal = maxValue;
        initFactorials(n);             // O(n)
        long long total = 0;
        for (int start = 1; start <= maxVal; ++start)
            total = (total + rec(1, start)) % MOD;
        return int(total);
    }
};
