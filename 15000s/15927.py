a=input()
if a != a[::-1]:
    print(len(a))
elif a[1:] == a[1:][::-1]:
    print(-1)
elif a[:-1] == a[:-1][::-1]:
    print(-1)
else:
    print(len(a)-1)
