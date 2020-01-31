N, D = map(int, raw_input().split())
X, Y = map(int, raw_input().split())

P = [1]*(N+1)
for i in range(1, N+1):
  P[i] = i*P[i-1]

if X%D!=0 or Y%D!=0:
  print 0
  exit(0)
dx = X/D
dy = Y/D

ans = 0
for U in range(0, N+1):
  D = U-dy
  if 0<=D:
    if (dx+N-U-D)%2==0:
      R = (dx+N-U-D)/2
      L = N-U-D-R
      if 0<=R and 0<=L:
        ans += P[N]/P[U]/P[D]/P[R]/P[L]
ans = ans*(10**100)/4**N/10.**100
print "%.12f"%ans
