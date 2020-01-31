Ax, Ay, Bx, By = map(int, raw_input().split())
A = complex(Ax, Ay)
B = complex(Bx, By)

N = input()
P = [0]*N
for i in range(N):
  X, Y = map(int, raw_input().split())
  P[i] = complex(X, Y)

def cross(a, b):
  return a.real*b.imag - a.imag*b.real

c = 0
for i in range(N):
  if (cross(B-A, P[i]-A) * cross(B-A, P[(i+1)%N]-A) < 0 and
      cross(P[(i+1)%N]-P[i], A-P[i]) * cross(P[(i+1)%N]-P[i], B-P[i]) < 0):
    c += 1
print c/2+1
