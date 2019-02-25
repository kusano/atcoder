W,H,N = map(int, raw_input().split())

l,r,t,b = 0,W,0,H
for _ in range(N):
  x,y,a = map(int, raw_input().split())
  if a==1:
    l = max(l, x)
  if a==2:
    r = min(r, x)
  if a==3:
    t = max(t, y)
  if a==4:
    b = min(b, y)
print max(r-l, 0)*max(b-t, 0)
