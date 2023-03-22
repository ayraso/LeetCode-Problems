class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {

    priority_queue<pair<int,int>> Costs_goToCityA;

    for(int i=0; i<costs.size(); i++){
      Costs_goToCityA.push(make_pair(costs[i][1]-costs[i][0],i));
    }

    int totalCost = 0;

    while(!Costs_goToCityA.empty()){
      if(Costs_goToCityA.size() > costs.size()/2){
        totalCost += costs[Costs_goToCityA.top().second][0];
      }
      else{
        totalCost += costs[Costs_goToCityA.top().second][1];
      }
      Costs_goToCityA.pop();
    }

    return totalCost;
  }
};