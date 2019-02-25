N,M,X = map(int, raw_input().split())
A = map(int, raw_input().split())

T = [0]*(N+1)
for a in A:
  T[a] = 1
print min(sum(T[:X]), sum(T[X:]))
