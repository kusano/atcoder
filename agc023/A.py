N = input()
A = map(int, raw_input().split())

M = {}
s = 0
for a in A:
  s += a
  if s not in M:
    M[s] = 0
  M[s] += 1

ans = 0
s = 0
for a in A:
  if s in M:
    ans += M[s]
  s += a
  M[s] -= 1
print ans
