A, B, C = map(int, raw_input().split())
print min(A%2*B*C, B%2*C*A, C%2*A*B)