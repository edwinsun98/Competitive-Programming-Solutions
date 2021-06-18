str1 = input()
str2 = input()
goal = input()
d = {}
l = list(str1)
l2 = list(str2)
for i in range (0, len(l2),1):
    if(l2[i] not in d):
        d.update({l2[i]:l[i]})
    
for x in range (0, len(goal),1):
    if(goal[x] in d):
        print(d.get(goal[x]),end = "")
    else:
        print(".", end = "")
