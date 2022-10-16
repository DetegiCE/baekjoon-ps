n = int(input())
n %= 100
if n == 0 or n == 10 or n == 30 or n == 60:
    print(0)
elif 75 < n < 85:
    print(4)
elif 40 < n < 50 or 70 < n < 90:
    print(3)
elif 15 < n < 25 or 35 < n < 55 or 65 < n < 95:
    print(2)
else:
    print(1)
