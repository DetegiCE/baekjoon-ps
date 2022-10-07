a = input()
b = a
c = 0
while int(a) >= 10:
    c += 1
    a = str(sum(list(map(int, a))))
print(c)
print('YNEOS'[a not in '369'::2])