n = int(input())
a = input()
c = 1
for i in range(1, n):
    b = a[i-1:i+1]
    if b == '22': c += 2
    elif b == '25': c += 1
    elif b == '2[': c += 1
    elif b == '2]': c += 0
    elif b == '52': c += 1
    elif b == '55': c += 2
    elif b == '5[': c += 1
    elif b == '5]': c += 0
    elif b == '[2': c += 1
    elif b == '[5': c += 1
    elif b == '[[': c += 1
    elif b == '[]': c += 0
    elif b == ']2': c += 2
    elif b == ']5': c += 2
    elif b == '][': c += 1
    elif b == ']]': c += 1
print(c)