/*
    Problem:
        AcWing: https://www.acwing.com/problem/content/312/
        LuoGu: https://www.luogu.com.cn/problem/P10958
*/

/*
    题目：
    魔鬼数：有连续 666 出现的数字称为“魔鬼数”
    求第 X 小的魔鬼数。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL f[21][4];
int t, n, m;

void prework() {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 3; j++) {
            f[i + 1][j + 1] += f[i][j];
            f[i + 1][0] += f[i][j] * 9;
        }
        f[i + 1][3] += f[i][3] * 10;
    }
}

void solve() {
    prework();

    cin >> t;
    while (t--) {
        cin >> n;
        for (m = 3; f[m][3] < n; m++)
            ;
        for (int i = m, k = 0; i; i--) {
            for (int j = 0; j <= 9; j++) {
                LL cnt = f[i - 1][3];
                if (j == 6 || k == 3)
                    for (int l = max(3 - k - (j == 6), 0); l < 3; l++)
                        cnt += f[i - 1][l];
                if (cnt < n)
                    n -= cnt;
                else {
                    if (k < 3) {
                        if (j == 6)
                            k++;
                        else
                            k = 0;
                    }
                    cout << j;
                    break;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}