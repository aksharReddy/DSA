class Solution {
public:
    int trap(vector<int>& arr) {
        int water=0;
        int n = arr.size();
        // int prefmax[n];
        // int suffmax[n];
        // prefmax[0] = arr[0];
        // for(int i=1;i<n;i++){
        //     prefmax[i] = max(prefmax[i-1],arr[i]);
        // }
        // suffmax[n-1] = arr[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suffmax[i] = max(suffmax[i+1],arr[i]);
        // }
        // for(int i=0;i<arr.size();i++){
        //     // water +=  min(leftmax(i,arr),rightmax(i,arr)) - arr[i];
        //     water += min(prefmax[i],suffmax[i]) - arr[i];
        // }
        int l =0;
        int r = n-1;
        int rightmax=0,leftmax=0;
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(arr[l]>=leftmax)leftmax = arr[l];
                else{
                    water += leftmax-arr[l];
                    
                }
                l++;
            }
            else{
                if(arr[r]>=rightmax) rightmax=arr[r];
                else{
                    water+=rightmax-arr[r];
                    
                }
                r--;
            }
        }
        return water;
    }
};