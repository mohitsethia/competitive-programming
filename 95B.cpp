#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 1e6;

void fill(char *aa, int i, int n4, int n7) {
    while (n4--)
        aa[i++] = '4';
    while (n7--)
        aa[i++] = '7';
    printf("%s\n", aa);
}

int main() {
    static char cc[N + 1], aa[N + 2 + 1];
    int n, n4, n7, i;

    scanf("%s", cc), n = strlen(cc);
    if (n % 2 == 1) {
        fill(aa, 0, (n + 1) / 2, (n + 1) / 2);
        return 0;
    }
    n4 = n / 2, n7 = n / 2;
    for (i = 0; i < n; i++)
        if (cc[i] != '4' && cc[i] != '7') {
            if (cc[i] < '4' && n4 > 0) {
                cc[i] = '4';
                n4--;
                fill(cc, i + 1, n4, n7);
                return 0;
            }
            if (cc[i] < '7' && n7 > 0) {
                cc[i] = '7';
                n7--;
                fill(cc, i + 1, n4, n7);
                return 0;
            }
            if (i == 0) {
                fill(aa, 0, (n + 2) / 2, (n + 2) / 2);
                return 0;
            }
            if (cc[i - 1] == '4')
                n4++;
            else
                n7++;
            cc[i - 1]++;
            i -= 2;
        } else if (cc[i] == '4' && n4 > 0)
            n4--;
        else if (cc[i] == '7' && n7 > 0)
            n7--;
        else
            cc[i--]++;
    fill(cc, n, 0, 0);
    return 0;
}
