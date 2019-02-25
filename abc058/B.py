O = raw_input()
E = raw_input()
print "".join([O,E][i%2][i/2] for i in range(len(O)+len(E)))
