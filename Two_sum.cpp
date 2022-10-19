class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
       vector<int> ans ;
    map<int,int> m;
    for(int i=0;i<arr.size();i++){
        if(m.find(target - arr[i])!=m.end()){
            ans.push_back(m[target - arr[i]]);
            ans.push_back(i);
        }
        m[arr[i]] = i;
    }
        return ans;
    }
};
