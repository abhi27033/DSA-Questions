class Solutio {
public:
	vector<int> ar, seg;
	Solutio(vector<int>& x, int n)
	{
		ar = x;
		seg.resize(4 * n);
		build(0, 0, n - 1);
	}
	void build(int idx, int l, int h)
	{
		if (l == h)
		{
			seg[idx] = ar[l];
			return;
		}
		int mid = (l + h ) / 2;
		build(2 * idx + 1, l, mid);
		build(2 * idx + 2, mid + 1, h);
		seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
	}
	int query(int idx, int l, int h, int ql, int qh)
	{
		//lies completely inside
		if (l >= ql && h <= qh)
			return seg[idx];
		//lies outside
		if (ql > h || qh < l)
			return INT_MIN;
		//overlaps
		int mid = (l + h ) / 2;
		int left = query(2 * idx + 1, l, mid, ql, qh);
		int right = query(2 * idx + 2, mid + 1, h, ql, qh);
		return max(left, right);
	}
};
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        Solutio ob(nums,nums.size());
        long long ans=0,n=nums.size();
        unordered_map<long long,vector<long long>> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]].push_back(i);
        for(auto it:mp)
        {
            vector<long long> an=it.second;
            long long t=1;
            for(int i=1;i<an.size();i++)
            {
                if(ob.query(0,0,n-1,an[i-1],an[i])<=it.first)
                t++;
                else
                {
                    t*=(t+1);
                    t/=2;
                    ans+=t;
                    t=1;
                }
            }
            t*=(t+1);
            t/=2;
            ans+=t;
        }
        return ans;
    }
};