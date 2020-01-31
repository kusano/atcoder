W = input()
N, K = map(int, raw_input().split())
A = [0]*N
B = [0]*N
for i in range(N):
  A[i], B[i] = map(int, raw_input().split())

oo = 99999999
T = [[oo]*(100*N+1) for _ in range(K+1)]
T[0][0] = 0
for i in range(N):
  for j in range(K-1, -1, -1):
    for k in range(100*N+1):
      if T[j][k]<oo:
        T[j+1][k+B[i]] = min(T[j+1][k+B[i]], T[j][k]+A[i])
ans = 0
for i in range(K+1):
  for j in range(100*N+1):
    if T[i][j]<=W:
      ans = max(ans, j)
print ans
