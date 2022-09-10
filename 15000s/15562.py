saw = ['']
t = -1

def realrotate(num: int, di: int):
    if di == -1:
        nsaw = saw[num][1:] + saw[num][0]
        saw[num] = nsaw
    else:
        nsaw = saw[num][-1] + saw[num][:-1]
        saw[num] = nsaw


def rotate(num: int, di: int, orig: int):
    if orig == 0:
        if num > 1 and saw[num][6] != saw[num-1][2]:
            rotate(num-1, -di, 1)
        if num < t and saw[num][2] != saw[num+1][6]:
            rotate(num+1, -di, -1)
    elif orig == -1:
        if num < t and saw[num][2] != saw[num+1][6]:
            rotate(num+1, -di, -1)
    else:
        if num > 1 and saw[num][6] != saw[num-1][2]:
            rotate(num-1, -di, 1)
    realrotate(num, di)

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        saw.append(input())
    k = int(input())
    for _ in range(k):
        n, m = map(int,input().split())
        rotate(n, m, 0)
    c = 0
    for i in range(1, t+1):
        if saw[i][0] == '1':
            c += 1
    print(c)