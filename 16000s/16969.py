a = input()
s = (10 if a[0] == 'd' else 26)
for i in range(1, len(a)):
    if a[i-1] == 'c' and a[i] == 'c':
        s *= 25
    elif a[i-1] == 'c' and a[i] == 'd':
        s *= 10
    elif a[i-1] == 'd' and a[i] == 'd':
        s *= 9
    else:
        s *= 26
    s %= 1000000009
print(s%1000000009)
