a = input()
pos = 0
ans = 0
for i in a:
    if i == 'HONI'[pos%4]:
        pos += 1
        if pos % 4 == 0:
            ans += 1
print(ans)
