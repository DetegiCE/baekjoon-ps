def countSmall(s):
    cnt = 0
    for i in s:
        if i >= 'a' and i <= 'z':
            cnt += 1
    return cnt

def countLarge(s):
    cnt = 0
    for i in s:
        if i >= 'A' and i <= 'Z':
            cnt += 1
    return cnt

def countNumber(s):
    cnt = 0
    for i in s:
        if i >= '0' and i <= '9':
            cnt += 1
    return cnt

def countSpecial(s):
    cnt = 0
    for i in s:
        if i in '!@#$%^&*()-+':
            cnt += 1
    return cnt

n = int(input())
a = input()
need = 0

if countSmall(a) == 0:
    need += 1
if countLarge(a) == 0:
    need += 1
if countNumber(a) == 0:
    need += 1
if countSpecial(a) == 0:
    need += 1
if n + need <= 6:
    need += (6-n-need)

print(need)

