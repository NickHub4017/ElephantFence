x=open("report7n60sensor.txt")
data=x.readlines()
cnt=0;
for i in data:
    i=int(i)
    if(i>1500):
        cnt=cnt+1
        print ""+str(i) +" "
        
print()
print(len(data))
print(cnt)

