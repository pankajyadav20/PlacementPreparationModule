
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

		int n = points.size();
		vector<int> distance(n);

		for (int i = 0 ; i < n ; i++) {
			int point1 = points[i][0] , point2 = points[i][1];
			distance[i] = point1 * point1 + point2 * point2;
		}

		priority_queue < pair<int, pair<int , int>> , vector<pair<int, pair<int , int>>>, greater<pair<int, pair<int , int>>>>	 pq;

		for (int i = 0 ; i < n ; i++) {
			int dist = distance[i];
			pair<int, pair<int , int>> p;
			p.first = dist;
			pair<int, int> p2;
			p2.first = (points[i][0]);
			p2.second = (points[i][1]);
			p.second = p2;
			pq.push(p);
		}
		vector<vector<int>> ans;
		while(k--){
			vector<int> temp;
			pair<int, pair<int , int>> p = pq.top();
			pq.pop();
			temp.push_back(p.second.first);
            temp.push_back(p.second.second);
			ans.push_back(temp);
		}
		return ans;

	}
};