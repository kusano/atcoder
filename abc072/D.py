N = input()
p = [int(x)-1 for x in raw_input().split()]

ans = 0
for i in range(N-1):
  if p[i]==i:
    p[i],p[i+1] = p[i+1],p[i]
    ans += 1
if p[-1]==N-1:
  ans += 1
print ans
