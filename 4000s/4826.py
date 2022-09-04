befA = befB = -1
runDist = 0
usedFuel = 0
while True:
    a, b = map(float, input().split())
    if a == b == -1:
        break
    if a == b == 0:
        print("%.0f" % ((runDist/usedFuel)*befB))
        befA = -1
        runDist = 0
        usedFuel = 0
        continue
    if befA == -1:
        befA = a
        befB = b
        continue
    if befB > b:
        runDist += (a - befA)
        usedFuel += (befB - b)
        befA = a
        befB = b
    else:
        befA = a
        befB = b
        