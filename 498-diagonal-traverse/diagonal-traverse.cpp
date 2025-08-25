class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> ans;
        int flg=1;
        for(int i=0;i<m+n-1;i++){
            int ii=-1,jj=-1;
            if(i>=n){
                ii=n-1;
                jj=i-n+1;
            }
            else{
                ii=i;
                jj=0;
            }
            // cout<<ii<<" "<<jj<<" "<<flg<<endl;
            if(flg){
                while(ii>=0&&jj<m){
                    ans.push_back(mat[ii][jj]);
                    ii--;
                    jj++;
                }
            }
            else{
                if(i>=m){
                    ii=i-m+1;
                    jj=m-1;
                }
                else{
                    ii=0;
                    jj=i;
                }
                while(ii<n&&jj>=0){
                    ans.push_back(mat[ii][jj]);
                    ii++;
                    jj--;
                }
            }
            // cout<<ii<<" "<<jj<<flg<<endl;
            flg=1-flg;
        }
        return ans;
    }
};