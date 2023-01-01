#include <bits/stdc++.h>
using namespace std;

int row_with_max_1s(vector<vector<int>>matrix)
{
    int max_one = 0;   

    int max_one_index = 0;  

    for (int i = 0; i < matrix.size(); i++)
    {
        int count = 0;  

        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 1)
                count++;
        }
        if (count > max_one)
        {   max_one = count;
            max_one_index = i;
        }
    }

    return max_one_index;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
    };
    int max_one_index = row_with_max_1s(matrix);

    cout << max_one_index;

    return 0;
}
