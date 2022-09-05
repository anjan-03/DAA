#include<iostream>

using namespace std;

int main()
{ 
    int n,i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    if(n==1)
        cout << "*" << endl;
    else
    {
        int start,last,i,max,min;
        for (start = 0; start < n-1; start++)
        {
            if(a[start] > a[start+1])
            break;
        }
        if (start == n-1)
        {
            cout << "*" << endl;
            return(0);
        }
        for(last = n - 1; last > 0; last--)
        {
            if(a[last] < a[last-1])
            break;
        }
        max = a[start]; 
        min = a[start];
        for(i = start + 1; i <= last; i++)
        {
            if(a[i] > max)
                max = a[i];
            if(a[i] < min)
                min = a[i];
        }
        for( i = 0; i < start; i++)
            if(a[i] > min)
            {
                start = i;
                break;
            }    
        for( i = n -1; i >= last + 1; i--)
            if(a[i] < max)
            {
                last = i;
                break;
            }
        cout << start << endl << last << endl;
    }
    return 0;
}
