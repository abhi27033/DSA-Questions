class Solution {
    vector<long long> factorial;
    void calculate_fact(){
        factorial.resize(11,1);
        for(int i=2;i<=10;i++){
            factorial[i]=factorial[i-1]*i;
        }
    }
public:
    long long countGoodIntegers(int n, int k) {
        int start = pow(10,((n+1)/2-1)),end=pow(10,(n+1)/2);
        unordered_set<string> st;
        calculate_fact();
        long long count = 0;
        for(int i=start;i<end;i++){
            string num = to_string(i);
            string rev;
            if(n&1){
                rev = num.substr(0,n/2);
            }else{
                rev = num;
            }
            reverse(rev.begin(),rev.end());
            num+=rev;
            long long palindrome = stoll(num);
            sort(num.begin(),num.end());
            if(!(palindrome%k) && st.find(num)==st.end()){
                st.insert(num);
                vector<int> freq(10,0);
                for(char& c:num){
                    freq[c-'0']++;
                }
                long long non_zero = n-freq[0];
                long long curr_count = non_zero*(factorial[n-1]);
                for(int i=0;i<10;i++){
                    curr_count/=factorial[freq[i]];
                }
                count+=curr_count;
            }  
        }
        return count;
    }
};