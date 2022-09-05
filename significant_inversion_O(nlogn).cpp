#include <iostream>

using namespace std;
 
int func(int arr[], int arr1[], int left, int mid, int right);
 
int merge_sort(int arr[], int arr2[], int left, int right)
{
    int mid, ans = 0;
    if (right > left) 
    {
        mid = (right + left) / 2;
        ans = merge_sort(arr, arr2, left, mid);
        ans += merge_sort(arr, arr2, mid + 1, right);
        ans += func(arr, arr2, left, mid + 1, right);
    }
    return ans;
}
 
int func(int arr[], int temp[], int left,int mid, int right)
{
    int l, m, j, ans=0;
    l = left;
    m = mid;
    j = left;
    while ((l <= mid - 1) && (m <= right))
    {
        if (arr[m] >= 2 * arr[l])
        {
            ans += (mid - l);
            m++;
        }
        else
            l++;
    }
    l = left;
    m = mid;
    j = left;
    while ((l <= mid - 1) && (m <= right)) 
    {
        if (arr[m] <= arr[l]) 
            temp[j++] = arr[l++];
        else 
            temp[j++] = arr[m++];
    }
    while (l <= mid - 1)
        temp[j++] = arr[l++];
    while (m <= right)
        temp[j++] = arr[m++];
    for (l = left; l <= right; l++)
        arr[l] = temp[l];
    return ans;
}
int main()
{
    int i, size;
    cin >> size;
    int arr[size], arr2[size];
    for(i = 0;i < size;i++)
       cin >> arr[i];
    cout << merge_sort(arr, arr2, 0, size - 1);
    return 0;
}
