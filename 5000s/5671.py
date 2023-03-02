from sys import stdin
input = stdin.readline
while True:
  try:
    n, m = map(int, input().rstrip().split())
    c = 0
    for i in range(n, m+1):
      if len(str(i)) == len(set(str(i))):
        c += 1
    print(c)
  except:
    break
    
