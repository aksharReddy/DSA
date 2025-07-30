class Solution {
   
public:
     vector<int> rowgenerate(int row){
        vector<int>list;
        int ans = 1;
        list.push_back(ans);
        for(int i=1;i<row;i++){
            ans = ans*(row-i);
            ans = ans/i;
            list.push_back(ans);
        }
        return list;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        for(int i=1;i<=numRows;i++){
            vector<int>temp = rowgenerate(i);
            pt.push_back(temp);
           
        }
         return pt;
    }
};