import itertools

N, K = map(int, raw_input().split())
T = [map(int, raw_input().split()) for _ in range(N)]

for t in itertools.product(*T):
  r = 0
  for x in t:
    r ^= x
  if r==0:
    print "Found"
    break
else:
  print "Nothing"
