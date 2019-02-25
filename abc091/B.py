A = {}

N = input()
for i in range(N):
  s = raw_input()
  if s not in A:
    A[s] = 0
  A[s] += 1
M = input()
for i in range(M):
  t = raw_input()
  if t not in A:
    A[t] = 0
  else:
    A[t] -= 1
print max(A.values()+[0])
