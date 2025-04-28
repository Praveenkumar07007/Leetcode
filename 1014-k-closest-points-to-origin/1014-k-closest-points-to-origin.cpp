class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        vector<vector<int>> ans;
        for(auto i:points){
            double x = sqrt(pow(i[0],2)+pow(i[1],2));
            pq.push({x,i});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};