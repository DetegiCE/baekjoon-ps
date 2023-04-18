n = int(input())
a = list(map(int,input().split()))
mx = 0
tmp = 0
for i in range(1, n):
  if a[i] > a[i-1]:
    tmp += 1
  if a[i] < a[i-1]:
    tmp = 0
  mx = max(mx, tmp)
tmp = 0
for i in range(1, n):
  if a[i] < a[i-1]:
    tmp += 1
  if a[i] > a[i-1]:
    tmp = 0
  mx = max(mx, tmp)
print(mx+1)
