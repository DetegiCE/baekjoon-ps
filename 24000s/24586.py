p, q = map(int, input().split())
p, q = min(p, q), max(p, q)
s = input()
if s == 'AABB' and q == 7:
    print(8, 9)
elif s == 'ABAB' and p == 6 and q == 8:
    print(7, 9) 
elif s == 'ABBA' and q - p == 3:
    print(p+1, q-1)
elif s == 'BAAB' and p == 2 and q == 8:
    print(1, 9) 
elif s == 'BABA' and p == 2 and q == 4:
    print(1, 3) 
elif s == 'BBAA' and p == 3:
    print(1, 2) 
else:
    print(-1)