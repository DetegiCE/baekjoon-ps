a = input()
n = int(input())
b = input().split()
pos = 0
for i in b:
    by = 2
    if i == 'int':
        by = 8
    if i == 'long_long':
        by = 16
    v = a[pos:pos+by]
    pos += by
    print(int(v, 16), end=' ')
