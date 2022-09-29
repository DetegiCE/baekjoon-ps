from itertools import combinations
m=int(input().split()[1])
print('\n'.join(map(lambda x:' '.join(map(str,x)),map(list,sorted(list(set(combinations(sorted(map(int,input().split())),m))))))))