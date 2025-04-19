from random import choice
a = 'aeiou'
b = 'bcdfghjklmnpqrstvwxyz'
for _ in range(int(input())):
    for j in range(20):
        if j % 3 == 2:
            print(choice(a), end='')
        else: print(choice(b), end='')
    print()