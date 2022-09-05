#include<iostream>
#include<math.h>

using namespace std;

void func(int bin[], int arr[], int n, int size)
{
	if(size<0)
		return;
	if(bin[size] == 0)
	{
		bin[size] = 1;
		int i;
        cout << "{";
        for(i=0; i<n; i++)
            if(bin[i] == 1)
                cout << arr[i] << " ";
        cout << "}" << endl;
		return;
	}
	else
	{
		bin[size] = 0;
		func(bin, arr, n, size-1);
    }
}

int main()
{
	int i, size;
	cin >> size;
	int arr[size],bin[size];
	for(i=0; i<size; i++)
		cin >> arr[i];
	for(i=0; i<size; i++)
		bin[i] = 0;
	cout << "\nThe subsets are: " << endl;
	for(i=0; i<pow(2,size); i++)
		func(bin, arr, size , size-1);
	return(0);
}
