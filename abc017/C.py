N, M = map(int, raw_input().split())
L = [0]*M
R = [0]*M
for i in range(N):
  l, r, s = map(int, raw_input().split())
  L[l-1] += s
  R[r-1] += s

LS = [0]*M
LS[-1] = L[-1]
for i in range(M-2, -1, -1):
  LS[i] = LS[i+1] + L[i]
RS = [0]*M
RS[0] = R[0]
for i in range(1, M):
  RS[i] = RS[i-1] + R[i]

ans = 0
for i in range(M):
  ans = max(ans, (RS[i-1] if i>0 else 0)+(LS[i+1] if i<M-1 else 0))
print ans
