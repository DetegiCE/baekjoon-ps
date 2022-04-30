n = int(input())
a = list(map(int, input().split()))
s, t = map(int, input().split())
if s > t:
    s, t = t, s
print(min(sum(a[s-1:t-1]), sum(a[0:s-1])+sum(a[t-1:])))
