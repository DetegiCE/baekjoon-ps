a = []
for i in range(12345, 98766):
    if i % 9 == 0 and len(set(str(i))) == 5:
        if len(set(str(i//9).zfill(5)) | set(str(i))) == 10:
            a.append(i)
n = int(input())
print(a[n-1], str(a[n-1]//9).zfill(5))
