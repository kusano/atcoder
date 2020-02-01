N, M = map(int, raw_input().split())
L = [0]*M
R = [0]*M
for i in range(M):
  L[i], R[i] = map(int, raw_input().split())
  L[i] -= 1

print max(0, min(R)-max(L))
