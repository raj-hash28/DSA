class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        int n = profit.size();
        vector<pair<int, int>> projects;
        int i;

        for(i = 0; i < n; i++){
            projects.push_back({capital[i], profit[i]});
        }

        sort(projects.begin(), projects.end());
        priority_queue<int> pq;   //max heap
        int idx = 0;

        while(k--){
            while(idx < n){
                if(projects[idx].first > w)
                    break;
                pq.push(projects[idx].second);
                idx++;
            }

            if(pq.empty()){
                return w;
            }

            w = w + pq.top();
            pq.pop();
        }
        return w;
    }
};