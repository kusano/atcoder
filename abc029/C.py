import itertools

N = input()
for p in itertools.product("abc", repeat=N):
  print "".join(p)
