N, K = map(int, raw_input().split())
A = [int(a)-1 for a in raw_input().split()]

T = [0]*N
for a in A:
  T[a] += 1
T.sort()
print sum(T[:N-K])
