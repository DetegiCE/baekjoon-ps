from itertools import permutations
n,m = map(int,input().split())
print('\n'.join(map(lambda x:' '.join(map(str,x)),map(list,sorted(list(set(permutations(sorted(map(int,input().split())),m))))))))