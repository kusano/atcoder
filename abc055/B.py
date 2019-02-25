N = input()
p = 1
for i in range(N):
  p = p*(i+1)%1000000007
print p
