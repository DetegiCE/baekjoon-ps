#include<iostream>
using namespace std;
typedef long long ll;
#define PREC ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MOD 10000

ll n;
ll a[2][2]={1,1,1,0};
ll ans[2][2];

void matPro(ll (&dest)[2][2], ll (&a)[2][2], ll (&b)[2][2]) {
	ll temp[2][2];
	for(int i=0 ; i<2 ; i++){
		for(int j=0 ; j<2 ; j++){
			temp[i][j]=0;
			for(int k=0 ; k<2 ; k++){
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%MOD;
			}
		}
	}
	for(int i=0 ; i<2 ; i++){
		for(int j=0 ; j<2 ; j++){
			dest[i][j]=temp[i][j];
		}
	}
}

int main()
{
	PREC;
	while(1) {
    	cin >> n;
    	if(n == -1) break;
    	for(int i=0 ; i<2 ; i++) ans[i][i]=1;
    	ans[0][1]=ans[1][0]=0;
    	a[0][0]=a[0][1]=a[1][0]=1;
    	a[1][1]=0;
    	n--;
    	if(n==-1){
    		cout << "0\n";
    		continue;
    	}
    	while(n){
    		if(n&1) matPro(ans, ans, a);
    		matPro(a, a, a);
    		n>>=1;
    	}
    	cout << ans[0][0] << '\n';
	    
	}
}