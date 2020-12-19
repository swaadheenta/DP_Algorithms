#include<bits/stdc++.h>
using namespace std;

int printCountDP(int dist)
{
    int cnt[dist+1];
    cnt[0]  = 1,  cnt[1] = 1,  cnt[2] = 2;

    for (int i=3; i<=dist; i++)
       cnt[i] = cnt[i-1] + cnt[i-2] + cnt[i-3];

    return cnt[dist];
}


int main()
{   cout<<"Enter the distance";
    int dist;
    cin>>dist;
    cout << "Minimum ways to cover distance are "<<printCountDP(dist);
    return 0;
}
