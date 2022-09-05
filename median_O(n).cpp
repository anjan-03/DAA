#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int i,j,n,m;
    cin>>n;
    cin>>m;
    int a[n],b[m];
    if(n != 0)
        for(i=0;i<n;i++)
            cin>>a[i];
    if(m != 0)
        for(j=0;j<m;j++)
            cin>>b[j];
    if(n != 0 && m==0)
    {
        if(n%2 == 1)
        cout << a[n/2] << endl;
        else
            cout << (a[n/2]+a[n/2-1])/2.0 << endl;
       return 0;
    }
    if(m != 0 && n==0)
      {
          if(m%2 == 1)
            cout << b[m/2] << endl;
          else
            cout << (b[m/2]+b[m/2-1])/2.0 << endl;
         return 0;
      }
    if(n == 0 && m == 0)
        return 0;
    i=0;
    j=0;
    vector<int> fin_arr;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            fin_arr.push_back(a[i]);
            i++;
        }
        else if(i<n && a[i]>b[j])
        {
            fin_arr.push_back(b[j]);
            j++;
        }
    }
    if(i == n)
        while(j<m)
        {
            fin_arr.push_back(b[j]);
            j++;
        }
    if(j == m)
        while(i<n)
            fin_arr.push_back(a[i]);
    if(fin_arr.size()%2 == 1)
        cout << fin_arr[fin_arr.size()/2] << endl;
    else
        if(fin_arr.size()%2 == 0)
            cout << (fin_arr[fin_arr.size()/2-1]+fin_arr[fin_arr.size()/2])/2.0 << endl;
    return 0;
}
