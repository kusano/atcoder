N = input()
x = [0]*N
y = [0]*N
for i in range(N):
  x[i], y[i] = map(int, raw_input().split())

mina = 10**10
maxa = -10**10
minb = 10**10
maxb = -10**10
for i in range(N):
  mina = min(mina, x[i]+y[i])
  maxa = max(maxa, x[i]+y[i])
  minb = min(minb, x[i]-y[i])
  maxb = max(maxb, x[i]-y[i])

w = maxa-mina
h = maxb-minb

if w>h:
  if any(x[i]-y[i]==minb and x[i]+y[i] not in (mina, maxa) for i in range(N)):
    maxb = minb + w
  else:
    minb = maxb - w
if w<h:
  if any(x[i]+y[i]==mina and x[i]-y[i] not in (minb, maxb) for i in range(N)):
    maxa = mina + h
  else:
    mina = maxa - h

oa = (maxa+mina)/2
ob = (maxb+minb)/2
ox = (oa+ob)/2
oy = oa - ox

print ox, oy

"""
def check(ox, oy):
  d = abs(x[0]-ox)+abs(y[0]-oy)
  ok = True
  for i in range(1, N):
    if abs(x[i]-ox)+abs(y[i]-oy)!=d:
      ok = False
  return ok

for tx in range(ox-2, ox+3):
  for ty in range(oy-2, oy+3):
    if check(tx, ty):
      print tx, ty
      exit(0)
"""
