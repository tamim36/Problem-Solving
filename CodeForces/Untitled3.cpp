#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

#define MOD 1e9+7
#define M 101

typedef enum {false=0, true=1} bool;
typedef long long ll;


bool a[M] = {true};

int main() {
    for (int i = 3; i < M; ++i) {
        if (a[i - 3]) {
            a[i] = true;
        }
    }
    for (int i = 7; i < M; ++i) {
        if (a[i - 7]) {
            a[i] = true;
        }
    }

    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        puts(a[t] ? "YES" : "NO");
    }
    return 0;
}
