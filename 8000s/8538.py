a = set()
for _ in range(int(input())):
    b = input().lower().replace('-','')
    a.add(b)
print(len(a))
