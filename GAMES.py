mul = [10,10,5,10,5,2,5,10,5,10]
t = int(input())
for i in xrange(0,t):
	s = raw_input()
	if not '.' in s:
		print 1
	else:
		n = float(s)
		ans = 1
		while True:
			pq = repr(n).split('.')[1]
			if(pq == '0' or int(pq) == 0):
				break;
			dig = int(pq[len(pq)-1])
			n = round(n*mul[dig],4)
			ans *= mul[dig]
		print ans