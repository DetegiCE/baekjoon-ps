eu, ed = map(int, input().split())
a, b = map(int, input().split())
x0 = int(input())
l = a * x0 + b
print(l)
if a == 0:
    print(0, 0)
else:
    print(eu, ed * abs(a))
