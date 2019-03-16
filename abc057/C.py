N = input()

i = 1
ans = 99
while i*i<=N:
  if N%i==0:
    ans = min(ans, max(len(str(i)), len(str(N/i))))
  i += 1
print ans
