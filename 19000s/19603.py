p=int(input())
n=int(input())
r=int(input())
s=n
for i in range(10000004):
    if s > p:
        print(i)
        break
    n *= r
    s += n