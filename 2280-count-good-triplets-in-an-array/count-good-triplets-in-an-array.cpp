

class Solution {
public:

struct SegmentTree {
    vector<long long> tree;
    int size;
    static const int MAX_X = 100001;
    SegmentTree(int n = MAX_X) {
        size = n;
        tree.resize(4 * size, 0);
    }

    void update(int idx, int val, int node = 1, int l = 0, int r = MAX_X) {
        if (l == r) {
            tree[node] += val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int ql, int qr, int node = 1, int l = 0, int r = MAX_X) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;
        return query(ql, qr, 2 * node, l, mid) + query(ql, qr, 2 * node + 1, mid + 1, r);
    }

    // Wrapper for "sum of values of elements > x"
    long long sumGreaterThan(int x) {
        if (x >= MAX_X) return 0;
        return query(x + 1, MAX_X);
    }
};
void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& res) {
    if (right - left <= 1) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, res);
    mergeSort(arr, mid, right, res);

    vector<pair<int, int>> temp;
    int j = mid, count = 0;

    for (int i = left; i < mid; ++i) {
        while (j < right && arr[j].first <= arr[i].first) {
            temp.push_back(arr[j++]);
        }
        // All remaining elements in [j, right) are greater than arr[i]
        res[arr[i].second] += (right - j);
        temp.push_back(arr[i]);
    }

    // Add the remaining right elements
    while (j < right) temp.push_back(arr[j++]);

    // Copy back to original array
    for (int i = left; i < right; ++i) {
        arr[i] = temp[i - left];
    }
}

vector<int> countGreaterElementsRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; ++i) {
        arr.emplace_back(nums[i], i);  // {value, index}
    }

    mergeSort(arr, 0, n, res);
    return res;
}
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>> arr(n,vector<int>(2));
        for(int i=0;i<n;i++){
        arr[nums1[i]][0]=i;
        arr[nums2[i]][1]=i;
        }
        sort(arr.begin(),arr.end());
        vector<int> farr;
        for(auto it:arr)farr.push_back(it[1]);
        vector<int> nextGreater(n,-1);
        stack<int> stk;
        stk.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(stk.size()&&farr[stk.top()]<=farr[i])
            stk.pop();
            if(stk.size())
            nextGreater[i]=stk.top();
            stk.push(i);
        }
        vector<int> greaterElements=countGreaterElementsRight(farr);
        SegmentTree seg;
        seg.update(farr.back(),0);
        long long ans=0;
        for(int i=n-2;i>=0;i--)
        {
            ans+=seg.sumGreaterThan(farr[i]);
            seg.update(farr[i],greaterElements[i]);
        }
        return ans;
    }
};