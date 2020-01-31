A = input()
B = input()
C = input()

M = 10**9+7

def inv(x):
  return pow(x, M-2, M)

BA = B*inv(A)
CA = C*inv(A)

print (BA*inv(BA+CA-CA*BA)-1)%M, (CA*inv(BA+CA-CA*BA)-1)%M
