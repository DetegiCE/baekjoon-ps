def change(orig, key):
    num = ord(key) - 65
    if ord(orig) + num > ord('Z'):
        return chr(ord(orig) + num - 26)
    else:
        return chr(ord(orig) + num)

for _ in range(int(input())):
    key, msg = input().split()
    print('Ciphertext: ', end='')
    for i in range(len(msg)):
        print(change(msg[i],key[i%len(key)]), end='')
    print()