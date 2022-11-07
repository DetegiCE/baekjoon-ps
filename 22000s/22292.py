def side(x, y, z):
    if x == 0: return 1
    if x == 100: return 2
    if y == 0: return 3
    if y == 100: return 4
    if z == 0: return 5
    if z == 100: return 6
    return 0

def dist(x, y):
    return (x*x+y*y)**0.5

def P3(x, y, z):
    sideOn = side(x, y, z)
    if sideOn == 1:
        return min(dist(100-y, 200-z), dist(100-z, 200-y))
    if sideOn == 2:
        return dist(100-y, 100-z)
    if sideOn == 3:
        return min(dist(100-x, 200-z), dist(100-z, 200-x))
    if sideOn == 4:
        return dist(100-x, 100-z)
    if sideOn == 5:
        return min(dist(100-y, 200-x), dist(100-x, 200-y))
    if sideOn == 6:
        return dist(100-x, 100-y)
    return 0