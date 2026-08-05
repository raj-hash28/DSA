class Solution {
public:
    vector<int> ans;
    void check(int k, map<int, int>& indegree, vector<vector<int>>& v, vector<int>& visited){
        ans.push_back(k);

        for(int i = 0; i<v[k].size(); i++){
            if(visited[v[k][i]] == -1){
                visited[v[k][i]] = 1;
                check(v[k][i],  indegree, v, visited);
            }
            indegree[v[k][i]]--;
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> v(n);
        map<int, int> indegree;

        for(auto it: invocations){
            v[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<int> visited(n, -1);
        visited[k] = 1;
        check(k, indegree, v, visited);

        for(int i = 0; i < ans.size(); i++){
            if(indegree[ans[i]] > 0){
                vector<int> res;
                for(int i = 0; i < n; i++){
                    res.push_back(i);
                }
                return res;
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++){
            if(visited[i] == -1){
                res.push_back(i);
            }
        }
        return res;
    }
};