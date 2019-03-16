N = input()
C = [0]*(N-1)
S = [0]*(N-1)
F = [0]*(N-1)
for i in range(N-1):
  C[i], S[i], F[i] = map(int, raw_input().split())

for i in range(N):
  t = 0
  for j in range(i, N-1):
    t = max(t, S[j])
    t = (t+F[j]-1)/F[j]*F[j]+C[j]
  print t
