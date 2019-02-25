n = input()

T = [0]*(n+1)
if n>=3:
  T[3] = 1
for i in range(4, n+1):
  T[i] = sum(T[i-3:i])%10007
print T[n]
