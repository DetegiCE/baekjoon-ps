a = input()
orig = a
for i in range(10):
    a = orig
    a = a.replace('*', str(i))
    sum = 0
    for j in range(12):
        if j % 2 == 0: sum += int(a[j])
        else: sum += int(a[j]) * 3
    sum %= 10
    if int(a[12]) == 0 and sum == 0:
        print(i)
        break
    if int(a[12]) == 10 - sum:
        print(i)
        break
