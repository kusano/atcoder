N,T = map(int, raw_input().split())
A = [input() for _ in range(N)]

ans = 0
for i in range(N):
  if i<N-1:
    ans += min(T, A[i+1]-A[i])
  else:
    ans += T
print ans
