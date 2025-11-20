class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        
        int count = 0;
        int first = INT_MIN;   
        int second = INT_MIN;  
        
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (start <= first) {
                continue;  
            }
            if (start <= second) {
                first = second;
                second = end;
                count++;
            }
            else {
                first = end - 1;
                second = end;
                count += 2;
            }
        }
        
        return count;
    }
};
/* ...
commented code for future referance
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end point (ascending), then by start point (descending)
        // This ensures we process intervals optimally for greedy selection
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        int count = 0;
        int first = INT_MIN;   // Last picked number
        int second = INT_MIN;  // Second last picked number
        
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            // Already has both numbers we picked earlier
            if (start <= first) continue;
            
            // Has second number but not first - add end to maintain 2 numbers
            if (start <= second) {
                first = second;
                second = end;
                count++;
            }
            // Has neither number - add both end-1 and end (greedy from end)
            else {
                first = end - 1;
                second = end;
                count += 2;
            }
        }
        
        return count;
    }
};
*/
