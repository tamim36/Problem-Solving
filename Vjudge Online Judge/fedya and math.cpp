#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
char n[maxn];
int k = 1;
int number;
int total = 0 ;
int main ()
{
    cin >> n;
    int len = strlen(n);
    for (int i=len-1; i>=0; i--){
        number = n[i] - 48;
        if (k==1)
        {
            total = total + (number % 4);
            k++;
        }
        else if (k==2){
            total = total + ((number % 4 * 2)%4);
            k++;
        }
        total = (total % 4);
    }
    if (total == 1 || total == 2 || total == 3)
        cout << 0 <<endl;
    else
        cout << 4 << endl;

    return 0;
}
