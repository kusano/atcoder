N = input()
a = map(int, raw_input().split())
ans = 99999999
for t in range(-100,101):
  ans = min(ans, sum((t-x)**2 for x in a))
print ans
