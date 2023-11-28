n = int(input())
a = (n-1)//9+1
if a%2==0 and n%2==1: a += 1
print(a)
