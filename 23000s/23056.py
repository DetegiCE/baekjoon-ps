n, m = map(int, input().split())
blue = []
white = []
cnt = [0 for _ in range(11)]
while True:
    a, b = input().split()
    if a == '0':
        break
    a = int(a)
    if cnt[a] < m and a % 2 == 0:
        white.append([a, b])
        cnt[a] += 1
    elif cnt[a] < m and a % 2 == 1:
        blue.append([a, b])
        cnt[a] += 1
blue.sort(key=lambda x:(x[0], len(x[1]), x[1]))
white.sort(key=lambda x:(x[0], len(x[1]), x[1]))
for i in blue:
    print(i[0], i[1])
for i in white:
    print(i[0], i[1])
