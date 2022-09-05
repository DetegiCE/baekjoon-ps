stack = []

if __name__ == '__main__':
    a = input()
    for i in a:
        if i.isnumeric():
            stack.append(int(i))
        else:
            j = '//' if i == '/' else i
            b = stack.pop()
            a = stack.pop()
            stack.append(eval(str(a)+j+str(b)))
    print(stack[0])