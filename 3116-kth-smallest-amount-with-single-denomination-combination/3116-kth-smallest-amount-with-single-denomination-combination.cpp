
class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countS(vector<int>& coins, long long amount) {
        long long count = 0;
//         for (long long it : coins) {
//             count += amount / it;
//         }
// cout<<count<<endl;
        long long n = coins.size();
        // long long f=pow(2,n);
        for (long long mask = 1; mask < (1<<n); ++mask) {
            long long f = 1;
            long long cnt = 0;
            for (long long i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    f = lcm(f, coins[i]);
                    ++cnt;
                }
            }
            if (cnt %2==1) {
                // cout<<f<<" "<<(amount / f)<<"-- ";
                count =count+ (amount / f);
            }
            else
            {
                count =count- (amount / f);
            }
        }
// cout<<endl;
        return count;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {
        long long left = 1;
        long long right = LONG_MAX, ans = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = countS(coins, mid);
            // cout<<count<<" " <<mid<<endl;
            if(count==k)ans=mid;
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
