#include<bits/stdc++.h>
using namespace std;

#define PRIME_L 50000

vector<int> primelist;
bool sieve[PRIME_L];

void prime_gen() {
    primelist.push_back(2);
    for(int i=3 ; i<PRIME_L ; i+=2) {
        if(!sieve[i]) {
            primelist.push_back(i);
            for(int j=i*2 ; j<PRIME_L ; j+=i) {
                sieve[j] = true;
            }
        }
    }
}

bool under_prime(int n) {
    int c = 0;
    for(int i = 0 ; i < primelist.size() ; i++) {
        int curp = primelist[i];
        while(n % curp == 0) {
            n /= curp;
            c++;
            if(n == 1) break;
        }
        if(n == 1) break;
    }
    return binary_search(primelist.begin(), primelist.end(), c);
}

int main()
{
    prime_gen();
    int a, b, c = 0;
    scanf("%d %d", &a, &b);
    for(int i=a ; i<=b ; i++) {
        if(under_prime(i)) {
            c++;   
        }
    }
    printf("%d", c);
}