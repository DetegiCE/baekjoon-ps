k, s = map(int, input().split())
n = list(map(int, input().split()))
t = 0
for i in n:
    if i < k:
        t += i
    else:
        t += k-1
print(t+1)
