a,b=map(int,input().split())
c,d=map(int,input().split())
e,f=map(int,input().split())
if (a-c)*(d-f) != (b-d)*(c-e):
  print('WINNER WINNER CHICKEN DINNER!')
else:
  print('WHERE IS MY CHICKEN?')
