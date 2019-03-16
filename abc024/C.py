N, D, K = map(int, raw_input().split())
L = [0]*D
R = [0]*D
for i in range(D):
  L[i], R[i] = map(int, raw_input().split())

for _ in range(K):
  S, T = map(int, raw_input().split())
  for i in range(D):
    if L[i]<=S<=R[i]:
      if S<T:
        S = min(R[i], T)
      else:
        S = max(L[i], T)
      if S==T:
        print i+1
        break
