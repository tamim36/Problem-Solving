#include<bits/stdc++.h>
using namespace std;

int main ()
{
    double x1, x2, x3, y1, y2, y3, result, ab, bc, ca;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ab = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    bc = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    ca = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));

    if (ab==bc){
        if (ab+bc > ca){
            printf("Yes\n");
        }
        else {
        printf("No\n");
    }
    }
    else {
        printf("No\n");
    }
    return 0;
}
