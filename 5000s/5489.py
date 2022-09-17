cnt = [0] * 10001

if __name__ == '__main__':
    for _ in range(int(input())):
        cnt[int(input())] += 1
    for i in range(1, 10001):
        if cnt[i] == max(cnt):
            print(i)
            break