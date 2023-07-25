class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(m>0&&m<arr.size()-1)
            {
            if(arr[m]>arr[m-1]&&arr[m]>arr[m+1])
                return m;
            else if(arr[m]>arr[m-1]&&arr[m]<arr[m+1])
                l=m+1;
            else
                r=m-1;
            }
            else if(m==0)
            {
                if(arr[m]<arr[m+1])
                    return m+1;
                else
                    return m;
            }
            else
               if(arr[m]<arr[m-1])
                    return m-1;
                else
                    return m;
        }
        return -1;
    }
};