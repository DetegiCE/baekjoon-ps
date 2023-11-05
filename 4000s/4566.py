while True:
    a = input()
    if a == 'END':
        break
    if a.count('"') != 2:
        print('not a quine')
        continue
    b = a.split('"')[1]
    c = a.split('"')[2]
    if b == c[1:] and len(b) > 0 and c[0] == ' ':
        print(f'Quine({b})')
    else:
        print('not a quine')
