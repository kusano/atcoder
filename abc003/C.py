N, K = map(int, raw_input().split())
R = map(float, raw_input().split())

R = sorted(R)
C = 0.0
for i in range(N-K, N):
  C = (C+R[i])/2.0
print "%.10f"%C
