#include <bits/stdc++.h>
using namespace std;
int c[10], d[10];
int main() {
    int a, b; cin >> a >> b;
    int t = a, y = b;

    while (t % 2 == 0)
        t /= 2, ++c[0];
    while (t % 3 == 0)
       t /= 3, ++c[1];
    while (t % 5 == 0)
       t /= 5, ++c[2];
    while (y % 2 == 0)
      y /= 2, ++d[0];
    while (y % 3 == 0)
      y /= 3, ++d[1];
    while (y % 5 == 0)
      y /= 5, ++d[2];


    if (t != y) puts("-1");
    else {
        int res = 0;
        for (int i=0; i<3; i++)
        res += max(c[i], d[i]) - min(c[i], d[i]);
        cout << res << endl;
    }
    return 0;
}
