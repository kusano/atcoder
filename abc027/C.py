N = input()

b = 0
t = N
while t>0:
  b += 1
  t /= 2

t = 1<<(b-1)
for i in range(1,b-1,2):
  t |= 1<<i

if b%2==0 and N>=t or b%2!=0 and N<t:
  print "Takahashi"
else:
  print "Aoki"
