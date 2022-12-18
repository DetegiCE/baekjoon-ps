a=input()
n=len(a)
minv = 51
for i in range(n, -1, -1):
    b = a + a[:i][::-1]
    if b == b[::-1]:
        minv = i + n
print(minv)