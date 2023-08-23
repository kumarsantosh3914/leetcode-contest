class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        //add all chars to map - freq
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        
        //push all pairs to pq baed on freq
        priority_queue<pair<int, char>> pq;
        for(auto it:mp) {
            pq.push({it.second, it.first});
        }
        
        string sum = "";
        //oiof only char and its freq is 1 then return it;
        if(pq.size() == 1 && pq.top().first == 1) 
        return sum + pq.top().second;
        
        while(pq.size() > 1) {
            //while priority queue has more than 1 element
            //we || keep adding top two chars alternately , until freq >    
            auto it1 = pq.top(); //take top two chars and save it
            pq.pop();
            auto it2 = pq.top();
            pq.pop();
            
            //add them to sum string
            sum += it1.second;
            sum += it2.second;
            
            //if freq is 1 then we don't need to add that char anymore
            if(it1.first > 1) pq.push({it1.first - 1, it1.second});
            if(it2.first > 1) pq.push({it2.first - 1, it2.second});
        }
        
        //if remaning char has freq > then return empty string
        if(pq.size() == 1 && pq.top().first > 1) {
            return "";
        }
        
        //if remaining chars freq is 1 the add it to ans string
        else if(pq.size() == 1 && pq.top().first == 1) {
            sum += pq.top().second;
        }
        return sum;
    }
};