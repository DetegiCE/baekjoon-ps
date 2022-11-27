n,g=input().split()
n=int(n)
s=set()
for i in range(n):
    s.add(input())
if g == 'Y':
    print(len(s))
elif g == 'F':
    print(len(s)//2)
else:
    print(len(s)//3)