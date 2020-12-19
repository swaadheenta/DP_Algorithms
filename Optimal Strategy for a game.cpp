#include <bits/stdc++.h>
using namespace std;

int optimalStrategyOfGame( int* arr, int n)
{
    int table[n][n];
    
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {

            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;

            table[i][j] = max( arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
    return table[0][n - 1];
}


int main()
{   cout<<"Enter the size of the array";
    int p;
    cin>>p;
    int arr[p];
    cout<<"Enter the elements of the array";
    for(int i=0;i<p;i++)
        cin>>arr[i];
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"optimal strategy of game is "<<optimalStrategyOfGame(arr, n);
    return 0;
}
