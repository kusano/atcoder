B = [list(input()) for _ in range(8)]

dx = [-1,-1, 0, 1, 1, 1, 0,-1]
dy = [ 0,-1,-1,-1, 0, 1, 1, 1]

def check(x, y):
  for d in range(8):
    tx = x
    ty = y
    while True:
      tx += dx[d]
      ty += dy[d]
      if not (0<=tx<8 and 0<=ty<8):
        break
      if B[ty][tx]=="Q":
        return False
  return True

def f(y):
  if y==8:
    for b in B:
      print("".join(b))
    exit(0)

  for x in range(8):
    if check(x, y):
      old = B[y][x]
      B[y][x] = "Q"
      f(y+1)
      B[y][x] = old
f(0)
print("No Answer")
