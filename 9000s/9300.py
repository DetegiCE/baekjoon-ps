from sys import stdin
input = stdin.readline
from math import tan, pi
t = int(input())
for tc in range(1, t+1):
    print(f'Case {tc}:', end=' ')
    h, th = map(float, input().split())
    if th == 0:
        print('Infinity')
    else:
        print(f'{abs((h/tan(pi/180*th))-h):.10f}')
