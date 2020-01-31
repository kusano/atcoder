import sys

N = input()

m = -1
for i in range(1, N):
  print "?", 1, i+1
  sys.stdout.flush()
  d = input()
  if d>m:
    m = d
    mi = i

ans = 0
for i in range(N):
  if i!=mi:
    print "?", mi+1, i+1
    sys.stdout.flush()
    d = input()
    ans = max(ans, d)

print "!", ans
