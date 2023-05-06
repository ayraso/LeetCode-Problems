
struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
  }
};


class Solution {
public:
    bool isPathCrossing(string path) {
        bool isPathCrossing = false;
        unordered_set<pair<int, int>, PairHash> VisitedPoints;
        pair<int, int> currentPoint = make_pair(0, 0);
        VisitedPoints.insert(currentPoint);
        for (int i=0; i<path.size(); i++){
            currentPoint = obtainCoordinate(currentPoint, path[i]);
            cout<< "( " << currentPoint.first <<", "<< currentPoint.second <<" )"<<endl;

            if(VisitedPoints.count(currentPoint)==0){
                VisitedPoints.insert(currentPoint);
            }
            else{
                isPathCrossing = true;
                break;
            }
        }
        return isPathCrossing;
    }
private:
    pair<int, int> obtainCoordinate(pair<int, int> lastVisitedPoint, char newDirectionInfo){
        pair<int, int> nextDestinationPoint;
        if(newDirectionInfo == 'E')
            nextDestinationPoint = make_pair(lastVisitedPoint.first + 1, lastVisitedPoint.second);
        else if(newDirectionInfo ==  'W')
            nextDestinationPoint = make_pair(lastVisitedPoint.first - 1, lastVisitedPoint.second); 
        else if(newDirectionInfo == 'N')
            nextDestinationPoint = make_pair(lastVisitedPoint.first, lastVisitedPoint.second + 1); 
        else if(newDirectionInfo == 'S')
            nextDestinationPoint = make_pair(lastVisitedPoint.first, lastVisitedPoint.second - 1);
        
        return nextDestinationPoint;
    }
};
