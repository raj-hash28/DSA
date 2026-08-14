class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for(char c: s) count[c-'a']++;

        for(int c: count){
            if(c > (n+1)/2)
                return "";
        }

        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                pq.push({count[i], (char)('a'+i)});
            }
        }

        string res = "";
        int seat = 0;

        while(!pq.empty()){
            pair<int, char> p = pq.top();
            pq.pop();

            if(seat == 0 || res[seat-1] != p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first > 0) pq.push(p);
            }
            else {
                if(pq.empty() ) return "";

                pair<int, char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;

                if(p2.first > 0) pq.push(p2);
                pq.push(p);
            }
        }
        return res;
    }
};