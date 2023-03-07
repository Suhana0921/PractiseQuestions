#include <bits/stdc++.h>
using namespace std;
 
bool cmp(vector<int> a, vector<int> b)
{
    return b[1] > a[1];
}
int minArrows(vector<vector<int>> points)
{
   
    sort(points.begin(), points.end(), cmp);

    int end = points[0][1];

    int arrow = 1;

    for (int i = 1; i < points.size(); i++)
    {
 
        if (points[i][0] <= end)
        {
            continue;
        }

        else
        {
            end = points[i][1];
            arrow++;
        }
    }

    return arrow;
}

int main()
{
 
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << (minArrows(points));
    return 0;
}
