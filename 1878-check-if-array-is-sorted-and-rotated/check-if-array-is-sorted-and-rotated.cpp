class Solution {
public:
    bool check(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1])cnt++;
        }
        if(arr[arr.size()-1]>arr[0])cnt++;
        if(cnt>1)return false;
        return true;
    }
};