def solve(S):
  n = len(S)
  T = [(-9999, "")]*(2*n+1)
  T[n] = (0, "")
  for s in S:
    P = T
    if s=="+":
      for i in range(2*n+1):
        T[i] = (P[i][0]+(i-n), P[i][1]+"+")
    elif s=="-":
      for i in range(2*n+1):
        T[i] = (P[i][0]-(i-n), P[i][1]+"-")
    else:
      T = [(-9999, "")]*(2*n+1)
      for i in range(1,2*n):
        if P[i][0]>T[i-1][0]:
          T[i-1] = (P[i][0], P[i][1]+"<")
        if P[i][0]>T[i+1][0]:
          T[i+1] = (P[i][0], P[i][1]+">")
  return T[n][1]

import random

n = 64
for i in range(10):
  while True:
    S = "".join(random.choice("+-MM") for _ in range(n))
    if S.count("M")%2==0:
      print S
      print solve(S)
      print
      break

print solve("M+MMM+MM+-+M-MM-MM+M-M+M+MM-MM")
