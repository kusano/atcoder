N = input()
color = [input() for _ in range(N)]

if color.count(0)==N or color.count(1)==N:
  print -1
  exit(0)

color += color
m = 0
c = 1
for i in range(1, 2*N):
  if color[(i-1)%N]==color[i%N]:
    c += 1
  else:
    m = max(m, c)
    c = 1
print (m+1)/2
