#include <iostream>
#include <string>
using namespace std;

struct Node {
    int hasChild;
    Node *child[26];

    Node() {
        hasChild = 0;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

int cnt;

struct Trie {
    Node *root;
    Trie() { root = new Node(); }

    void insert(Node *node, string s, int pos, int chk) {
        if (pos == s.size()) {
            return;
        }
        node->hasChild |= chk;

        if (!node->child[s[pos] - 'a']) {
            node->child[s[pos] - 'a'] = new Node();
        }
        insert(node->child[s[pos] - 'a'], s, pos + 1, chk);
    }

    int solve(Node *node, int lev) {
        if (!(node->hasChild & (1 << lev))) {
            return 0;
        }

        for (int i = 0; i < 26; i++) {
            if (node->child[i] && !solve(node->child[i], lev ^ 1)) {
                return 1;
            }
        }

        return 0;
    }
};

Trie trie;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 2; i++) {
        int n;
        string s;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> s;
            trie.insert(trie.root, s, 0, (1 << i));
        }
    }

    int val = trie.solve(trie.root, 0);
    if (val == 0)
        cout << "Emilija";
    else
        cout << "Nina";
}