#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

ll roman2int(string s) {
    ll ans = 0;
    ll prev = 0;
    for(int i=s.length()-1 ; i>=0 ; i--) {
        ll cur = 0;
        if(s[i] == 'I') cur = 1;
        if(s[i] == 'V') cur = 5;
        if(s[i] == 'X') cur = 10;
        if(s[i] == 'L') cur = 50;
        if(s[i] == 'C') cur = 100;
        if(s[i] == 'D') cur = 500;
        if(s[i] == 'M') cur = 1000;

        if(cur >= prev) ans += cur;
        else ans -= cur;
        prev = cur;
    }
    return ans;
}

string int2roman(ll n) {
    string ans = "";
    if(n >= 1000) {
        for(int i=0 ; i<n/1000 ; i++) ans += 'M';
        n %= 1000;
    }
    if(n >= 900) {
        ans += "CM";
        n -= 900;
    }
    if(n >= 500) {
        ans += "D";
        n -= 500;
    }
    if(n >= 400) {
        ans += "CD";
        n -= 400;
    }
    if(n >= 100) {
        for(int i=0 ; i<n/100 ; i++) ans += 'C';
        n %= 100;
    }
    if(n >= 90) {
        ans += "XC";
        n -= 90;
    }
    if(n >= 50) {
        ans += "L";
        n -= 50;
    }
    if(n >= 40) {
        ans += "XL";
        n -= 40;
    }
    if(n >= 10) {
        for(int i=0 ; i<n/10 ; i++) ans += 'X';
        n %= 10;
    }
    if(n == 9) {
        ans += "IX";
        n -= 9;
    }
    if(n >= 5) {
        ans += 'V';
        n -= 5;
    }
    if(n == 4) {
        ans += "IV";
        n -= 4;
    }
    if(n >= 1) {
        for(int i=0 ; i<n ; i++) ans += "I";
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    while(1) {
        int n;
        cin >> n;
        if(n == 0) break;
        cnt++;

        ll sum = 0;
        for(int i=0 ; i<n ; i++) {
            string num;
            cin >> num;
            sum += roman2int(num);
        }

        cout << "Case " << int2roman(cnt) << ": " << int2roman(sum) << '\n';
    }
}