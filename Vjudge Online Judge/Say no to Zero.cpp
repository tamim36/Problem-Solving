#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, sum1, sum2, a1=0, b1=0, temp=0;
    cin >> a >> b;
    sum1 = a+b;
    while (sum1 != 0){
        if (sum1%10 != 0 ){
            temp = (sum1%10) + (10*temp) ;
        }
        sum1 = sum1/10;
    }
    sum1=0;
    while (temp != 0){
        sum1 = (temp%10) + (10*sum1);
        temp = temp/10;
    }



    while (a != 0){
        if (a%10 != 0 ){
            a1 = (a%10) + (10*a1) ;
        }
        a = a/10;
    }
    a=0;
    while (a1 != 0){
        a = (a1%10) + (10*a);
        a1 = a1/10;
    }
        while (b != 0){
        if (b%10 != 0 ){
            b1 = (b%10) + (10*b1) ;
        }
        b = b/10;
    }
    b=0;
    while (b1 != 0){
        b = (b1%10) + (10*b);
        b1 = b1/10;
    }
    sum2 = a+b;
    if (sum1 == sum2){
        cout <<"YES"<<endl;
    }
    else {
        cout <<"NO" <<endl;
    }
    return 0;
}
