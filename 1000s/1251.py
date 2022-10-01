a = input()
c = a
for i in range(1, len(a)-1):
    for j in range(i+1, len(a)):
        n = a[:i][::-1] + a[i:j][::-1] + a[j:][::-1]
        if n < c:
            c = n
print(c)