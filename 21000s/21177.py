n = int(input())
a = list(map(int, input().split()))
c = [0 for _ in range(90001)]
for i in a:
    c[i] = 1
b = 0
for i in range(1, 90001):
    if c[i] == 1 and c[i-1] == 0:
        b += i
print(b)