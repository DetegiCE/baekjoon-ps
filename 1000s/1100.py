cnt = 0
for i in range(8):
    t = input()
    cnt += t[(i%2)::2].count('F')
print(cnt)