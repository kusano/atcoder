N, K, Q = map(int, raw_input().split())

P = [K-Q]*N
for i in range(Q):
  P[input()-1] += 1

for p in P:
  print "Yes" if p>0 else "No"
