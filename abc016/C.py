N, M = map(int, raw_input().split())
E = [[] for _ in range(N)]
for _ in range(M):
  A, B = map(int, raw_input().split())
  E[A-1] += [B-1]
  E[B-1] += [A-1]

for i in range(N):
  S1 = set()
  S2 = set([i])
  for e1 in E[i]:
    S2.add(e1)
    for e2 in E[e1]:
      S1.add(e2)
  print len(S1-S2)
