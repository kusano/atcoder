N, M, D = map(int, raw_input().split())
A = [int(a)-1 for a in raw_input().split()]

B = range(N)
for a in A[::-1]:
  B[a+1], B[a] = B[a], B[a+1]

C = range(N)
while D>0:
  if D&1:
    Cp = C
    C = [0]*N
    for i in range(N):
      C[i] = Cp[B[i]]
  D >>= 1  
  Bp = B
  B = [0]*N
  for i in range(N):
    B[i] = Bp[Bp[i]]

for c in C:
  print c+1
