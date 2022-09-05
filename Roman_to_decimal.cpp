#include<iostream>
using namespace std;
int letter(char c)
{
    switch(c)
    {
        case 'I' :
            return 1;
        case 'V' :
            return 5;
        case 'X' :
            return 10;
        case 'L' :
            return 50;
        case 'C' :
            return 100;
        case 'D' :
            return 500;
        case 'M' :
            return 1000;
        default :
            return -1;
    }
}
int func(string s)
{
    int n = s.size() , ans = 0 , temp , next , i = 0;
    while(i < n)
    {
        if(i == n - 1)
        {
            ans += letter(s[i]);
            return ans;
        }
        temp = letter(s[i]) , next = letter(s[i + 1]);
        if(temp >= next)
            ans += temp , i++;
        else
            ans += next - temp , i += 2;
    }
    return ans;
}
int main()
{
    char s[16];
    scanf("%s",s);
    cout << func(s) << '\n';
    return 0;
}