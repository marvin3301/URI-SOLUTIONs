m = int(input())
li = input()

for i in range(m):
	tmp = input()
	if(li=="A" and tmp=="1"): li="B"
	elif(li=="A" and tmp=="2"): li="A"
	elif(li=="A" and tmp=="3"): li="C"
	elif(li=="B" and tmp=="1"): li="A"
	elif(li=="B" and tmp=="2"): li="C"
	elif(li=="B" and tmp=="3"): li="B"
	elif(li=="C" and tmp=="1"): li="C"
	elif(li=="C" and tmp=="2"): li="B"
	elif(li=="C" and tmp=="3"): li="A"
print(li)