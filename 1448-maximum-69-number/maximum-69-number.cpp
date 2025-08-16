class Solution {
public:
    int maximum69Number (int nums) {
        string num=to_string(nums);
        for(int i=0;i<num.size();i++){
            if(num[i]=='6'){
                num[i]='9';
                break;
            }
        }
        return stoi(num);
    }
};