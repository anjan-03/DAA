#include <iostream>

using namespace std;

int main()
{
    int size,diff,i,sum1=0,tsum=0,part=0,temp;
    cin >> size;
    cin >> diff;
    int arr[size];
    for(i=0;i<size;i++)
        cin >> arr[i];
    for(i=0;i<size;i++)
        tsum += arr[i];
    for(i=0;i<size;i++)
    {
        sum1 += arr[i];
        if(sum1 - (tsum - sum1) == diff || sum1-(tsum-sum1) == -diff)
        {
            part = i;
            cout << "1" << endl;
            for(i=0;i<=part;i++)
                cout << arr[i] << endl;
            temp = 1;
            break;
        }
        else
            temp = 0;
    }
    if(temp == 1)
    {    
        cout << "2" << endl;
        for(i=part+1;i<size;i++)
            cout << arr[i] << endl;
    }
    else
        cout << "*";   
    return(0);    
}
