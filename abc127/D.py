N, M = map(int, raw_input().split())
A = map(int, raw_input().split())
B = [0]*M
C = [0]*M
for i in range(M):
  B[i], C[i] = map(int, raw_input().split())

A.sort()
BC = [(C[i], B[i]) for i in range(M)]
BC.sort()

p = 0
for c, b in BC[::-1]:
  for i in range(b):
    if A[p]>c:
      break
    A[p] = c
    p += 1
    if p>=N:
      break
  else:
    continue
  break
print sum(A)
