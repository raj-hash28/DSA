class Solution {
public:
    int leastInterval(vector<char>& tasks, int gap) {
        int n = tasks.size();
        unordered_map<char, int> freq;
        unordered_map<char, int> free;
        
        for(char c : tasks){
            freq[c]++;
            free[c] = 1;
        }

        priority_queue<pair<int, char>> pq;
        for(auto i : freq){
            pq.push({i.second, i.first});
        }

        int seat = 1;
        while(!pq.empty()){
            vector<pair<int, char>> side;
            bool executed = false;

            while(!pq.empty()){
                pair<int, char> p = pq.top();
                pq.pop();

                int fr = p.first;
                int child = p.second;

                if(free[child] <= seat){
                    free[child] = seat+gap+1;
                    if(fr-1 > 0){
                        side.push_back({fr-1, child});
                    }
                    executed = true;
                    break;
                }
                else{
                    side.push_back(p);
                }
            }

            for(auto& item : side){
                pq.push(item);
            }

            if(!pq.empty()){
                seat++;
            }
        }
        return seat;
    }
};