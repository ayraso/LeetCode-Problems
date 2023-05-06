class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Stones(stones.begin(), stones.end());
        while(Stones.size()>1){
            int mostHeavyStone = Stones.top(); 
            Stones.pop();
            int secondHeavyStone = Stones.top(); 
            Stones.pop();
            if(mostHeavyStone-secondHeavyStone!=0) Stones.push(mostHeavyStone-secondHeavyStone);
        }
        if(Stones.empty()) return 0;
        else return Stones.top();
    }
};