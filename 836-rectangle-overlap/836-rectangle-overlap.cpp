class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
     int a1=rec1[0], b1=rec1[1], a2=rec1[2], b2=rec1[3];
	int x1=rec2[0], y1=rec2[1], x2=rec2[2], y2=rec2[3];

	if(x1>=a2 and x2>=a2) return false;
	else if(x2<=a1 and x1<=a1) return false;
	else if(y1>=b2 and y2>=b2) return false;
	else if(y2<=b1 and y1<=b1) return false;
	else return true;
    }
};