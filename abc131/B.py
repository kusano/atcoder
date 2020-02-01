N, L = map(int, raw_input().split())

A = [L+i for i in range(N)]
d = 99999999
for i in range(N):
  if abs(A[i])<d:
    d = abs(A[i])
    ans = sum(A)-A[i]
print ans
