r, l = map(float, input().split())
print(r, 0)
c = max(-1, 1-(l**2)/(2*r*r))
print(r*c, r*((max(0, 1-c**2))**0.5))
