import math

N = input()
Ax = [0]*N
Ay = [0]*N
for i in range(N):
  Ax[i], Ay[i] = map(float, raw_input().split())
Bx = [0]*N
By = [0]*N
for i in range(N):
  Bx[i], By[i] = map(float, raw_input().split())

def f(x, y):
  ox = sum(x)/len(x)
  oy = sum(y)/len(y)
  l = 0
  for i in range(len(x)):
    l = max(l, math.hypot(x[i]-ox, y[i]-oy))
  return l

print "%.10f"%(f(Bx, By)/f(Ax, Ay))
