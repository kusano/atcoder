r1, c1 = map(int, input().split())
r2, c2 = map(int, input().split())

if (r1, c1)==(r2, c2):
  print(0)
  exit(0)

if r1+c1==r2+c2 or r1-c1==r2-c2 or abs(r1-r2)+abs(c1-c2)<=3:
  print(1)
  exit(0)

if (r1+c1)%2==(r2+c2)%2:
  print(2)
  exit(0)

for dr in range(-3, 4):
  for dc in range(-3, 4):
    r3 = r1+dr
    c3 = c1+dc
    if abs(r3-r1)+abs(c3-c1)<=3:
      if r3+c3==r2+c2 or r3-c3==r2-c2 or abs(r3-r2)+abs(c3-c2)<=3:
        print(2)
        exit(0)

print(3)
