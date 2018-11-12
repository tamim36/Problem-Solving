#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int left, right, ambi, sum;
    cin >> left >> right >> ambi;
    while (ambi > 0){
        if (left < right){
            left++;
            ambi--;
        }
        else if (left > right){
            right ++;
            ambi--;
        }
        else if (left == right){
            left++;
            ambi --;
            if (ambi == 0){
                break;
            }
            right++;
            ambi--;
        }
    }
    cout << left << "  " << right << endl;
    if (left ==0 || right == 0){
        sum = 0;
    }
    else if (left > right){
        sum = right + right;
    }
    else if (left< right){
        sum = left + left;
    }
    else {
        sum = left+left;
    }
    cout << sum;
    return 0;
}
