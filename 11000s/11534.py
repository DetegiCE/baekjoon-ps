a, b = input().split()
for i in range(len(a)-1):
    try:
        if b.index(a[i]) > b.index(a[i+1]):
            exit(0)
        else:
            aid = b.index(a[i])
            b = b[:aid] + '.' + b[aid+1:]
    except:
        print('FAIL')
        exit(0)
print('PASS')
        
