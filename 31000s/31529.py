x, y = map(int, input().split())
if x > y or x*2 - y < 0:
    print(-1)
else:
    print(506 * (x*2-y))