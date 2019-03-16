N = input()
a, b = map(int, raw_input().split())
a -= 1
b -= 1
M = input()
x = [0]*M
y = [0]*M
for i in range(M):
  x[i], y[i] = map(int, raw_input().split())
  x[i] -= 1
  y[i] -= 1

for i in range(M):
  x += [y[i]]
  y += [x[i]]
D = [-1]*N
T = [0]*N
D[a] = 0
T[a] = 1
for d in range(N):
  for i in range(2*M):
    if D[x[i]]==d and D[y[i]] in (-1, d+1):
      D[y[i]] = d+1
      T[y[i]] += T[x[i]]
      T[y[i]] %= 10**9+7
print T[b]
