a = input()
c = 1
for i in range(1, len(a)):
    if a[i-1] != a[i]:
        c += 1
print(len(a) - c)