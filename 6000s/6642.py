from sys import stdin
input = stdin.readline

while True:
    a = int(input().rstrip())
    if a == 0:
        break
    d = dict()
    for i in range(a):
        b, c = input().rstrip().split()
        d[b] = float(c)
    while True:
        e = input().rstrip()
        if e == 'end':
            print('end')
            input()
            print()
            break
        e = e.split()
        if e[0] == 'create':
            if e[1] in d:
                print('create: already exists')
            else:
                d[e[1]] = 0.0
                print('create: ok')
        elif e[0] == 'deposit':
            if e[1] not in d:
                print(f'deposit {e[2]}: no such account')
            else:
                d[e[1]] += float(e[2])
                print(f'deposit {e[2]}: ok')
        elif e[0] == 'withdraw':
            if e[1] not in d:
                print(f'withdraw {e[2]}: no such account')
            elif d[e[1]] < float(e[2]):
                print(f'withdraw {e[2]}: insufficient funds')
            else:
                d[e[1]] -= float(e[2])
                print(f'withdraw {e[2]}: ok')
        else:
            if e[1] not in d or e[2] not in d:
                print(f'transfer {e[3]}: no such account')
            elif e[1] == e[2]:
                print(f'transfer {e[3]}: same account')
            elif d[e[1]] < float(e[3]):
                print(f'transfer {e[3]}: insufficient funds')
            else:
                d[e[1]] -= float(e[3])
                d[e[2]] += float(e[3])
                if e[1][-1] == e[2][-1]:
                    print(f'transfer {e[3]}: ok')
                else:
                    print(f'transfer {e[3]}: interbank')

print('goodbye')