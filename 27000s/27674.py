t = int(input())
for _ in range(t):
    input()
    a = sorted(list(input()))[::-1]
    print(int(''.join(a[:-1]))+int(a[-1]))
    
