#include <bits/stdc++.h>
using namespace std;

int n;
char ss[60];
char s[11][11];
char t[11];

int ans[12];
int acc[12];

void f(int pos)
{
    if (pos == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", ans[i]);
        }
        exit(0);
    }
    if (s[pos][pos] == '+')
    {
        for (int i = 1; i <= 10; i++)
        {
            int flg = 0;
            for (int j = 1; j < pos; j++)
            {
                if (s[j][pos] == '+' && acc[pos - 1] - acc[j - 1] + i <= 0)
                {
                    flg = 1;
                    break;
                }
                if (s[j][pos] == '-' && acc[pos - 1] - acc[j - 1] + i >= 0)
                {
                    flg = 1;
                    break;
                }
                if (s[j][pos] == '0' && acc[pos - 1] - acc[j - 1] + i != 0)
                {
                    flg = 1;
                    break;
                }
            }
            if (flg == 1)
                continue;
            else
            {
                ans[pos] = i;
                acc[pos] = i + acc[pos - 1];
                f(pos + 1);
            }
        }
    }
    else if (s[pos][pos] == '-')
    {
        for (int i = -10; i <= -1; i++)
        {
            int flg = 0;
            for (int j = 1; j < pos; j++)
            {
                if (s[j][pos] == '+' && acc[pos - 1] - acc[j - 1] + i <= 0)
                {
                    flg = 1;
                    break;
                }
                if (s[j][pos] == '-' && acc[pos - 1] - acc[j - 1] + i >= 0)
                {
                    flg = 1;
                    break;
                }
                if (s[j][pos] == '0' && acc[pos - 1] - acc[j - 1] + i != 0)
                {
                    flg = 1;
                    break;
                }
            }
            if (flg == 1)
                continue;
            else
            {
                ans[pos] = i;
                acc[pos] = i + acc[pos - 1];
                f(pos + 1);
            }
        }
    }
    else
    {
        for (int i = 0; i <= 0; i++)
        {
            int flg = 0;
            for (int j = 1; j < pos; j++)
            {
                if (s[j][pos] == '+' && acc[pos - 1] - acc[j - 1] + i <= 0)
                {
                    flg = 1;
                    break;
                }
                if (s[j][pos] == '-' && acc[pos - 1] - acc[j - 1] + i >= 0)
                {
                    flg = 1;
                    break;
                }
                if (s[j][pos] == '0' && acc[pos - 1] - acc[j - 1] + i != 0)
                {
                    flg = 1;
                    break;
                }
            }
            if (flg == 1)
                continue;
            else
            {
                ans[pos] = i;
                acc[pos] = i + acc[pos - 1];
                f(pos + 1);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf(" %s", ss);

    int sscnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            s[i][j] = ss[sscnt++];
        }
    }

    f(1);
}