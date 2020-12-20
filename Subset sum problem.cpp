#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= arr[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - arr[i - 1]];
        }
    }

    return subset[n][sum];
}


int main()
{   cout<<"Enter the size of set";
    int p;
    cin>>p;
    int arr[p];
    cout<<"Enter the values of the set";
    for(int i=0;i<p;i++)
        cin>>arr[i];
    int sum = 9;
    if (isSubsetSum(arr, p, sum))
        cout<<"Found a subset with given sum";
    else
        cout<<"No subset with given sum";
    return 0;
}
