#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

typedef struct node {
	string name;
	vector<string> child;
	map<string, node*> next;
	node(string name) {
		this->name = name;
	}
} NODE;

int n;

void printAnt(NODE *cur, int floor) {
	if(floor >= 1) {
		for(int i=0 ; i<floor-1 ; i++) {
			cout << "--";
		}
		cout << cur->name << '\n';
	}
	sort(cur->child.begin(), cur->child.end());
	for(int i=0 ; i<cur->child.size() ; i++) {
		printAnt(cur->next[cur->child[i]], floor+1);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	NODE *root = new NODE("root");
	for(int i=0 ; i<n ; i++) {
		int t;
		cin >> t;
		
		NODE *cur = root;
		for(int j=0 ; j<t ; j++) {
			string food;
			cin >> food;
			if(cur->next.find(food) != cur->next.end()) {
				cur = cur->next[food];
				continue;
			}
			cur->child.push_back(food);
			NODE *myfood = new NODE(food);
			cur->next[food] = myfood;
			cur = myfood;
		}
	}
	
	printAnt(root, 0);
}
