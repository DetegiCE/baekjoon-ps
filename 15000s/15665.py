from itertools import product
m=input().split()[1]
print('\n'.join(list(map(lambda x: ' '.join(map(str,x)),list(product(sorted(list(set(map(int,input().split())))),repeat=int(m)))))))