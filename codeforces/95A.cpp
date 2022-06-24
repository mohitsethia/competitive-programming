#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 100;
const int M = 100;

int compare(char *s, char *t, int l) {
	int i;

	for (i = 0; i < l; i++) {
		char a = toupper(s[i]), b = toupper(t[i]);

		if (a != b)
			return a - b;
	}
	return 0;
}

int main() {
	static char ss[N][M + 1], cc[M + 1], lucky[M];
	static int ll[N];
	int n, m, i, j;
	char c, c_, a, a_;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", ss[i]);
		ll[i] = strlen(ss[i]);
	}
	scanf("%s\n%c", cc, &c), m = strlen(cc);
	c_ = toupper(c);
	a = c == 'a' ? 'b' : 'a';
	a_ = toupper(a);
	for (j = 0; j < m; j++)
		for (i = 0; i < n; i++)
			if (m - j >= ll[i] && compare(cc + j, ss[i], ll[i]) == 0)
				memset(lucky + j, 1, ll[i]);
	for (j = 0; j < m; j++)
		if (lucky[j]) {
			if (tolower(cc[j]) == c)
				cc[j] = isupper(cc[j]) ? a_ : a;
			else
				cc[j] = isupper(cc[j]) ? c_ : c;
		}
	printf("%s\n", cc);
	return 0;
}
