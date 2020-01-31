N, A, B = map(int, raw_input().split())
v = map(int, raw_input().split())

v.sort()
print "%.8f"%(float(sum(v[-A:]))/A)

x = v[-A]
ans = 0
for b in range(A, B+1):
  if v[-b]!=x:
    break
  if b!=A and v[-1]!=x:
    break
  n1 = v.count(x)
  n2 = v[-b:].count(x)
  a = 1
  for i in range(n2):
    a *= n1-i
  for i in range(n2):
    a /= i+1
  ans += a
print ans
