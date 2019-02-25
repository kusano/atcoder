N = input()
T = map(int, raw_input().split())
S = sum(T)

M = input()
for _ in range(M):
  P, X = map(int, raw_input().split())
  print S - T[P-1] + X
