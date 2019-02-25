N = input()
S = raw_input()

s = 0
a = "b"
while True:
  if a==S:
    print s
    break
  if len(a)>=len(S):
    print -1
    break
  s += 1
  if s%3==1:
    a = "a"+a+"c"
  if s%3==2:
    a = "c"+a+"a"
  if s%3==0:
    a = "b"+a+"b"
