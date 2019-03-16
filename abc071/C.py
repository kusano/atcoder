N = input()
A = map(int, raw_input().split())

M = {}
for a in A:
  if a not in M:
    M[a] = 0
  M[a] += 1

V = [0, 0]
for a in M:
  if M[a]>=4:
    V += [a, a]
  elif M[a]>=2:
    V += [a]
V.sort()
print V[-1]*V[-2]
