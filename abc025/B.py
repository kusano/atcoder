N,A,B = map(int, raw_input().split())
X = 0
for _ in range(N):
  s, d = raw_input().split()
  d = int(d)
  if s=="East":
    X += max(A, min(B, d))
  else:
    X -= max(A, min(B, d))
if X>0:
  print "East", X
elif X<0:
  print "West", -X
else:
  print 0
