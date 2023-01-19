#include <bits/stdc++.h>
using namespace std;

int subCount(int arr[], int n, int k)
{

    int mod[k];
    memset(mod, 0, sizeof(mod));

    int cumSum = 0;
    for (int i = 0; i < n; i++) {
        cumSum += arr[i];
 
        mod[((cumSum % k) + k) % k]++;
    }
 
    int result = 0; 
 

    for (int i = 0; i < k; i++)

        if (mod[i] > 1)
            result += (mod[i] * (mod[i] - 1)) / 2;

    result += mod[0];
 
    return result;
}

int main()
{
    int arr[] = { 4, 5, 0, -2, -3, 1 };
    int k = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subCount(arr, n, k) << endl;
    int arr1[] = { 4, 5, 0, -12, -23, 1 };
    int k1 = 5;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << subCount(arr1, n1, k1) << endl;
    return 0;
}
