a, b = map(int, input().split())
s = 0
for i in range(1, a+1):
    l = len(str(i))
    if s < b <= s+l:
        print(str(i)[b-s-1])
        quit()
    s += l
print(-1)