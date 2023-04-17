input()
a = input().split()
b = set()
for i in a:
    if i.endswith('Cheese'):
        b.add(i[:-6])
if len(b) >= 4: print('yummy')
else: print('sad')
