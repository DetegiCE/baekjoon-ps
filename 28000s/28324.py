n = int(input())
a = list(map(int, input().split()))
spd = 0
s = 0
for i in a[::-1]:
    if spd < i:
        spd += 1
    else: spd = i
    
    s += spd
print(s)
