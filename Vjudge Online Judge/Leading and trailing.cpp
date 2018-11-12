#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int num, length=0, temp, lead=0, trail=0;
    cin >> num;
    temp = num;
    while (temp!=0){
        temp = temp/10;
        length ++;
    }
    for (int i=1; i<=length; i++){
            if (i <= 3){
        lead = (lead*10) + (num%10);
            }
            if (i > length-3){
                trail = (trail*10) + (num%10);
            }
            num = num/10;
    }
    temp = lead;
    lead = 0;
    while (temp!=0){
        lead = (lead*10) + (temp%10);
        temp = temp/10;
    }
    temp = trail;
    trail = 0;
    while (temp!=0){
        trail = (trail*10) + (temp%10);
        temp = temp/10;
    }
    cout << lead << endl << trail;

    return 0;
}
