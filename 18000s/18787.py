n = int(input())
a = input()
b = input()
flg = False
cnt = 0
for i in range(n):
    if a[i] != b[i]:
        if not flg:
            flg = True
            cnt += 1
    else:
        flg = False 
print(cnt)
