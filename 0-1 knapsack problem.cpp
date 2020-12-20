#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];


    for (i = 0; i <= n; i++)      // Build table K[][] in bottom up manner
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                          + K[i - 1][w - wt[i - 1]],
                          K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}


int main()
{   cout<<"Enter total Weight(W)";
    int W;
    cin>>W;
    cout<<"Enter the number of values";
    int p;
    cin>>p;
    int val[p],wt[p];
    cout<<"Enter the values";
    for(int i=0;i<p;i++)
        cin>>val[i];
    cout<<"Enter the weight of values";
    for(int i=0;i<p;i++)
        cin>>wt[i];
    cout<<knapSack(W, wt, val, p);
    return 0;
}

