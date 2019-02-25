a, b, x = map(int, raw_input().split())
a = (a+x-1)/x*x
b = b/x*x
print (b-a)/x+1
