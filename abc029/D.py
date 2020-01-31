N = input()

ans = 0
for d in range(10)[::-1]:
  t = 10**d
  for i in range(N/t%10):
    ans += str(N/t/10*10+i).count("1")*t
    ans += d*(t/10)
print ans+str(N).count("1")
