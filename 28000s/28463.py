a = input()
b = input()+input()
if a == 'N':
    if b == 'P..O': print('Lz')
    elif b == 'P..I': print('F')
    elif b == '.PO.': print('T')
    else: print('?')
elif a == 'S':
    if b == '.OP.': print('T')
    elif b == 'I..P': print('F')
    elif b == 'O..P': print('Lz')
    else: print('?')
elif a == 'E':
    if b == 'O..P': print('T')
    elif b == '.PI.': print('F')
    elif b == '.PO.': print('Lz')
    else: print('?')
else:
    if b == 'P..O': print('T')
    elif b == '.IP.': print('F')
    elif b == '.OP.': print('Lz')
    else: print('?')