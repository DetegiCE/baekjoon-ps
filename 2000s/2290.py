s = -1
n = ''

def line1():
    for i in n:
        if i in '14':
            print(' '+' '*s+' ', end=' ')
        else:
            print(' '+'-'*s+' ', end=' ')
    print()

def line2():
    for i in n:
        if i in '456890':
            print('|'+' '*s, end='')
        else:
            print(' '+' '*s, end='')
        if i in '12347890':
            print('|', end=' ')
        else:
            print(' ', end=' ')
    print()

def line3():
    for i in n:
        if i in '170':
            print(' '+' '*s+' ', end=' ')
        else:
            print(' '+'-'*s+' ', end=' ')
    print()
    
def line4():
    for i in n:
        if i in '2680':
            print('|'+' '*s, end='')
        else:
            print(' '+' '*s, end='')
        if i in '134567890':
            print('|', end=' ')
        else:
            print(' ', end=' ')
    print()
    
def line5():
    for i in n:
        if i in '147':
            print(' '+' '*s+' ', end=' ')
        else:
            print(' '+'-'*s+' ', end=' ')
    print()
    
if __name__ == '__main__':
    s, n = input().split()
    s = int(s)
    line1()
    for _ in range(s):
        line2()
    line3()
    for _ in range(s):
        line4()
    line5()