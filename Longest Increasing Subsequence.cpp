#include<bits/stdc++.h>
using namespace std;

int lis( int arr[], int n )
{
    int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++ )
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis+n);
}


int main()
{   cout<<"Enter the size of the array";
    int p;
    cin>>p;
    cout<<"Enter the elements of the array";
    int arr[p];
    for(int i=0;i<p;i++)
        cin>>arr[i];
    cout<<"Length of lis is "<<lis(arr,n);
    return 0;
}
