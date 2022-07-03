f=0
for i in range(5):
    s=input()
    if 'FBI' in s:
        print(i+1, end=' ')
        f=1
if f==0: print('HE GOT AWAY!')