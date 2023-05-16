n = int(input())
a, pa, b, pb = map(int, input().split())
m = 0
ma, mb = 0, 0
for i in range(0, n+1):
    ca = i//pa
    cb = (n-i)//pb
    cm = a * ca + b * cb
    if cm > m:
        m = cm
        ma, mb = ca, cb
print(ma, mb)
