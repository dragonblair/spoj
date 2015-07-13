while True:
	x = input()
	f = x.split()
	n,d = int(f[0]),int(f[1])
	if(n==0 and d==0):
		break
	if(d==0):
		print('0')
	else:
		print(n**d)
