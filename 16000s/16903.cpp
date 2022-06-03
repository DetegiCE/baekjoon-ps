#include<cstdio>
using namespace std;

struct Node {
    Node *l, *r;
    int cnt;

    Node() {
        l = r = NULL;
        cnt = 0;
    }
};

struct XOR_Tree {
    Node *root;

    XOR_Tree() {
        root = new Node();
    }

    void add(int val) {
        Node *x = root;
        for(int i=30 ; i>=0 ; i--) {
            int cur = 1 << i;
            if(val & cur) {
                if(!(x->r)) x->r = new Node();
                x = x->r;
            }
            else {
                if(!(x->l)) x->l = new Node();
                x = x->l;
            }
            (x->cnt)++;
        }
    }

    void erase(int val) {
        Node *x = root;
        for(int i=30 ; i>=0 ; i--) {
            int cur = 1 << i;
            if(val & cur) x = x->r;
            else x = x->l;
            (x->cnt)--;
        }
    }

    int query(int val) {
        Node *x = root;
        int ans = 0;
        for(int i=30 ; i>=0 ; i--) {
            int cur = 1 << i;
            if(val & cur) {
                if(x->l && x->l->cnt) {
                    x = x->l;
                    ans |= cur;
                }
                else x = x->r;
            }
            else {
                if(x->r && x->r->cnt) {
                    x = x->r;
                    ans |= cur;
                }
                else x = x->l;
            }
        }
        return ans;
    }
};

int main()
{
    int q;
    XOR_Tree tree;
    scanf("%d", &q);
    tree.add(0);
    while(q--) {
        int a, x;
        scanf("%d %d", &a, &x);
        if(a == 1) tree.add(x);
        else if(a == 2) tree.erase(x);
        else printf("%d\n", tree.query(x));
    }
}