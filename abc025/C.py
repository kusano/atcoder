b = [map(int, raw_input().split()) for _ in range(2)]
c = [map(int, raw_input().split()) for _ in range(3)]

A = [[" "]*3 for _ in range(3)]
memo = {}

def f(s):
  if s==9:
    r = 0
    for y in range(2):
      for x in range(3):
        if A[y][x]==A[y+1][x]:
          r += b[y][x]
    for y in range(3):
      for x in range(2):
        if A[y][x]==A[y][x+1]:
          r += c[y][x]
    return r

  a = ""
  for y in range(3):
    for x in range(3):
      a += A[y][x]
  if a in memo:
    return memo[a]

  if s%2==0:
    r = 0
    for y in range(3):
      for x in range(3):
        if A[y][x]==" ":
          A[y][x] = "o"
          r = max(r, f(s+1))
          A[y][x] = " "
  else:
    r = 9999
    for y in range(3):
      for x in range(3):
        if A[y][x]==" ":
          A[y][x] = "x"
          r = min(r, f(s+1))
          A[y][x] = " "
  memo[a] = r
  return r

t = f(0)
print t
print sum(sum(x) for x in b) + sum(sum(x) for x in c) - t
