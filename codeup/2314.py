n = int(input())
box10 = n // 10
n %= 10
box5 = n // 5
n %= 5
box3 = n // 3
n %= 3
box1 = n
print(box10 + box5 + box3 + box1)