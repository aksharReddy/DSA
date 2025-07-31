class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int cnt=0;
        int lastSmaller = INT_MIN;
        int longest = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1 == lastSmaller){
                cnt=cnt+1;
                lastSmaller = nums[i];
            }
            else if(nums[i] == lastSmaller){
                continue;
            }
            else{
                cnt=1;
                lastSmaller = nums[i];
            }

            longest = max(longest,cnt);
        }

        return longest;
    }
    
};