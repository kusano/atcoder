N = input()

T = [[[0]*4 for i in range(4)] for j in range(4)]
for c1 in range(4):
  for c2 in range(4):
    for c3 in range(4):
      if (0, 1, 2) not in [
        (c1, c2, c3),
        (c2, c1, c3),
        (c1, c3, c2),
      ]:
        T[c1][c2][c3] = 1

for i in range(3, N):
  P = T
  T = [[[0]*4 for i in range(4)] for j in range(4)]
  for c1 in range(4):
    for c2 in range(4):
      for c3 in range(4):
        for c4 in range(4):
          if (0, 1, 2) not in [
            (c2, c3, c4),
            (c3, c2, c4),
            (c2, c4, c3),
            (c1, c3, c4),
            (c1, c2, c4),
          ]:
            T[c2][c3][c4] += P[c1][c2][c3]
            T[c2][c3][c4] %= 1000000007
print sum(sum(sum(t2) for t2 in t1) for t1 in T) % 1000000007
