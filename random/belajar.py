
for j in range(1,6):
    for u in range(1,6):
            print("*", end="")
    print()
j=0
u=0
for j in range(1,6):
    for u in range(j):
            if(u<j):
                print(" ")
                
            else:
                print("*", end="")
    print()