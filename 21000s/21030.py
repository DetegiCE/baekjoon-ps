n = int(input())
a = input()
b = input()
mx = 0
for i in range(97, 123):
    c = 0
    for j in range(n):
        if a[j] == chr(i) or b[j] == chr(i):
            c += 1
    mx = max(mx, c)
print(mx)