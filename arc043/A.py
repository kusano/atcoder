N, A, B = map(int, raw_input().split())
S = [input() for _ in range(N)]

d = max(S)-min(S)
if d==0:
  print -1
else:
  P = float(B)/d
  Q = A-sum(S)*P/N
  print "%.8f %.8f"%(P, Q)
