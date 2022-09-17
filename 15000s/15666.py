from itertools import product
m=input().split()[1]
print('\n'.join(list(map(lambda x:' '.join(map(str,x)),[l for l in list(product(sorted(list(set(map(int,input().split())))),repeat=int(m))) if not (lambda p:1 in [(-1 if p[i]==p[i+1] else(p[i]-p[i+1])/abs(p[i]-p[i+1])) for i in range(int(m)-1)])(l)]))))