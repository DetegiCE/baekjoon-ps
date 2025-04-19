r, c = map(int, input().split())
e = list(map(int, input().split()))
n = list(map(int, input().split()))
if max(e) == max(n):
    print('possible')
else: print('impossible')