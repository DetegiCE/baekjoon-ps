a=[0,1,1,1]
for i in range(117):
    a.append(a[-1]+a[-3])
print(a[int(input())])