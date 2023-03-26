tm = {}
mt = {}

n, m = map(int, input().split())
for i in range(n):
  a = input()
  tm[a] = []
  b = int(input())
  for j in range(b):
    c = input()
    tm[a].append(c)
    mt[c] = a
for i in range(m):
  a = input()
  b = int(input())
  if b == 0:
    tm[a].sort()
    for j in tm[a]:
      print(j)
  else:
    print(mt[a])
