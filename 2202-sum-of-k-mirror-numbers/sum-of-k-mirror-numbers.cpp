class Solution {
public:
    // Convert a base-k string to base-10
    long long toBase10(const string& s, int k) {
        long long cur = 0;
        for (char c : s) {
            cur = cur * k + (c - '0');
        }
        return (long long)cur;
    }

    bool isDecPalindrome(long long x) {
        if (x < 0) return false;
        string s = to_string(x), r = s;
        reverse(r.begin(), r.end());
        return s == r;
    }

    // Build a base-k string of length 'width' from integer 'v'
    string toBaseKString(long long v, int k, int width) {
        string s(width, '0');
        for (int i = width - 1; i >= 0; --i) {
            s[i] = char('0' + (v % k));
            v /= k;
        }
        return s;
    }

    long long kMirror(int k, int n) {
        long long total = 0;
        int found = 0;

        // Try palindromes of increasing length
        for (int len = 1; found < n; ++len) {
            int halfLen = (len + 1) / 2;

            // smallest half = k^(halfLen-1), largest = k^halfLen - 1
            long long start = 1;
            for (int i = 1; i < halfLen; ++i) start *= k;
            long long end = start * k - 1;

            for (long long half = start; half <= end && found < n; ++half) {
                string left = toBaseKString(half, k, halfLen);

                // mirror to full palindrome
                string right = left;
                if (len % 2 == 1) 
                    right.pop_back();     // drop the middle digit once
                reverse(right.begin(), right.end());

                string full = left + right;
                long long v = toBase10(full, k);
                if (v != -1 && isDecPalindrome(v)) {
                    total += v;
                    ++found;
                }
            }
        }

        return total;
    }
};
