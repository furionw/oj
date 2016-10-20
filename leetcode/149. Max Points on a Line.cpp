#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


struct Point 
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution 
{
public:
	int maxPoints(vector<Point> &points) 
	{
		int cnt = 0;

		for (size_t i = 0; i < points.size(); ++ i)
		{
			map<double, int> slope;
			int increment = 0;
			int vertical_line = 0;
			for (size_t j = 0; j < points.size(); ++ j)
			{
				if (points[i].x==points[j].x && points[i].y==points[j].y) // include itself
				{
					++ increment;
				} else if (points[i].x==points[j].x)
				{
					++ vertical_line;
				} else
				{
					++ slope[1.0*(points[j].y-points[i].y) / (points[j].x-points[i].x)]; // int cast to double!!
				}
			}
			int maxx = 0;
			for (auto it = slope.begin(); it != slope.end(); ++ it)
			{
				maxx = maxx>it->second? maxx: it->second;
			}
			maxx = maxx>vertical_line? maxx: vertical_line;
			cnt = cnt>maxx+increment? cnt: maxx+increment;
		}

		return cnt;
	}
};

int main()
{
	Solution a;
	vector<Point> points;

	points.push_back(Point(0, 0));
	points.push_back(Point(0, 0));
	cout << a.maxPoints(points);

	return 0;
}