N = input()
x = [0]*N
y = [0]*N
h = [0]*N
for i in range(N):
  x[i], y[i], h[i] = map(int, raw_input().split())

for p in range(N):
  if h[p]>0:
    for Cy in range(101):
      for Cx in range(101):
        H = h[p] + abs(x[p]-Cx) + abs(y[p]-Cy)
        for i in range(N):
          if max(H-abs(x[i]-Cx)-abs(y[i]-Cy), 0) != h[i]:
            break
        else:
          print Cx, Cy, H
          exit(0)
