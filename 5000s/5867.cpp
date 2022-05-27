#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

int n;
vector<string> incs;
vector<string> desc;
vector<string> save;

string makeInc(string a) {
    char *cstr = new char[a.length()+1];
    strcpy(cstr, a.c_str());
    sort(cstr, cstr+a.length());
    string nstr(cstr);
    return nstr;
}

string makeDesc(string a) {
    char *cstr = new char[a.length()+1];
    strcpy(cstr, a.c_str());
    sort(cstr, cstr+a.length(), greater<char>());
    string nstr(cstr);
    return nstr;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for(int i=0 ; i<n ; i++) {
        string tmp;
        cin >> tmp;
        save.push_back(tmp);
        incs.push_back(makeInc(tmp));
        desc.push_back(makeDesc(tmp));
    }
    sort(incs.begin(), incs.end());
    sort(desc.begin(), desc.end());
    for(int i=0 ; i<n ; i++) {
        string si = makeInc(save[i]);
        string sj = makeDesc(save[i]);
        cout << lower_bound(desc.begin(), desc.end(), si) - desc.begin() + 1 << ' ';
        cout << upper_bound(incs.begin(), incs.end(), sj) - incs.begin() << '\n';
    }
}