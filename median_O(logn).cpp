#include<iostream>

using namespace std;

int maxi(int a, int b);
int mini(int a, int b);

double func(int *a,int n,int *b,int m)
{    
    int start=0,end=n,i,j,ans;
    while(start<=end)
    {
        i=(start + end) / 2;
        j=((n + m + 1) / 2) - i;
        if(j<0)
        {
            end = i-1;
            continue;
        }
        if(i<n && j>0 && b[j-1] > a[i])    
            start = i + 1;
        else if(i>0 && j<m && b[j]<a[i-1])    
            end = i - 1;
        else
        {
            if(i==0)        
                ans=b[j-1];        
            else if(j==0)        
                ans=a[i-1];        
            else        
                ans=maxi(a[i-1],b[j-1]);        
            break;
        }
    }
    if ((n + m) % 2 == 1)
        return (double)ans;
    if (i == n)
        return (ans+b[j])/2.0;
    if (j == m)
        return (ans + a[i])/2.0;
    return (ans + mini(a[i], b[j])) / 2.0;
}

int maxi(int a, int b)
{
    return a > b ? a : b;
}

int mini(int a, int b)
{
    return a < b ? a : b;
}


int main()
{
    int m,n;
    cin >> n >> m;
    if(m==0 && n==0)
    {
        cout << 0 << endl;
        return 0;
    }
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    if(n<m)
        cout << func(a,n,b,m) << endl;
    else
        cout << func(b,m,a,n) << endl;
    return 0;
}
