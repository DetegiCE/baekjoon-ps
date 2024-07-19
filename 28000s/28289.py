p = int(input())
sw = 0
em = 0
ai = 0
fr = 0
for i in range(p):
    gp, cp, np = map(int, input().split())
    if gp == 1: fr += 1
    elif cp <= 2: sw += 1
    elif cp == 3: em += 1
    else: ai += 1
print(sw)
print(em)
print(ai)
print(fr)