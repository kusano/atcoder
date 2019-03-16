N = input()

T = [0]*1000
for i in range(1, N+1):
  f = 2
  while i>1:
    if i%f==0:
      T[f] += 1
      i /= f
    else:
      f += 1
ans = 1
for t in T:
  ans *= t+1
  ans %= 10**9+7
print ans
