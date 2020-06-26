if __name__ == '__main__':
	while True:
	  try:
	  	t = int(input())
	  	a,c = [],[]
	  	for i in range(t):
	  		exp = input().strip().split(" ")
	  		lexp = exp[1].split("=")
	  		x, y, z = exp[0], lexp[0], lexp[1]
	  		a.append((x, y, z))
	  	for i in range(t):
	  		res = input().split(" ")
	  		eq = eval(str(a[int(res[1])-1][0])+str(res[2])+str(a[int(res[1])-1][1]))
	  		if(str(eq)==str(a[int(res[1])-1][2])): c.append(res[0])
	  	if len(c)==0:
	  		print("None Shall Pass!")
	  	elif len(c)==t:
	  		print("You Shall All Pass!")
	  	else:
	  		print(" ".join(sorted(c)))
	  except EOFError:
	    break