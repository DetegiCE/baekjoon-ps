a = input()
b = input()
if len(a) > len(b):
    a, b = b, a
for i in range(1, len(a)+1):
    if len(a) % i == 0 and len(b) % i == 0:
        s = a[:i]
        if a == s * (len(a)//i) and b == s * (len(b)//i):
            print(s)
            exit(0)
print('No solution')