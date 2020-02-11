N = input()
D = [input() for _ in range(N)]

D.sort()

T = [[0]*N for _ in range(4)]
S = [[0]*N for _ in range(4)]

M = 10**9+7

for i in range(N):
  T[0][i] = 1
S[0][N-1] = T[0][N-1]
for i in range(N-1)[::-1]:
  S[0][i] = S[0][i+1]+T[0][i]

for i in range(1, 4):
  p = 0
  for j in range(N):
    while p<N and D[p]<D[j]*2:
      p += 1
    if p<N:
      T[i][j] = S[i-1][p]
  S[i][N-1] = T[i][N-1]
  for j in range(N-1)[::-1]:
    S[i][j] = S[i][j+1]+T[i][j]
    S[i][j] %= M

print S[3][0]
