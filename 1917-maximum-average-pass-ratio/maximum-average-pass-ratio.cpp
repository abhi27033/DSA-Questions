class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> pq;
        for(auto it:classes){
            double b=it[1];
            double a=it[0];
            pq.push({(b-a)/(b*b+b),a,b});
        }
        while(extraStudents--){
            double x=pq.top()[0];
            double a=pq.top()[1];
            double b=pq.top()[2];
            pq.pop();
            a++;b++;
            pq.push({(b-a)/(b*b+b),a,b});
        }
        double ans=0.0;
        while(pq.size()){
            double a=pq.top()[1],b=pq.top()[2];
            pq.pop();
            ans+=(a/b);
        }
        ans/=classes.size();
        return ans;
    }
};