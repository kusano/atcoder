N = input()
R = [0]*N
H = [0]*N
for i in range(N):
  R[i], H[i] = map(int, raw_input().split())
  R[i] -= 1
  H[i] -= 1

C = [[0]*3 for _ in range(100000)]
for i in range(N):
  C[R[i]][H[i]] += 1

S = [0]*100000
S[0] = sum(C[0])
for i in range(1, 100000):
  S[i] = S[i-1]+sum(C[i])

for i in range(N):
  w = (0 if R[i]==0 else S[R[i]-1]) + C[R[i]][(H[i]+1)%3]
  d = C[R[i]][H[i]]-1
  l = N-w-d-1
  print w, l, d
