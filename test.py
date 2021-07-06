import os

count = 0
function = 1
a = 0

os.system('gcc -ansi -Wall -pedantic-errors the3.c test.c -o samp')
while function < 8:
    os.system('rm -r difference/func'+str(function)+'/*')
    os.system('rm -r outputs/func'+str(function)+'/*')
    DIRi = 'inputs/func'+str(function)+'/'
    DIRe = 'expected/func'+str(function)+'/'
    DIRo = 'outputs/func'+str(function)+'/'
    while a < 100:
        n = str(a)
        os.system('./samp <'+DIRi+'input'+n+'.txt>'+DIRo+'output'+n+'.txt')
        f1 = open(DIRe+"case"+n+".txt", "r").read()
        f2 = open(DIRo+"output"+n+".txt", "r").read() 
        if f1 == f2:
            print("Test "+n+" Passed!")
            count += 1
        else:
            print("Test "+n+" Failed!")
            fa = open("difference/func"+str(function)+"/difference"+n+".txt", "w")
            fa.write("Expected Output:\n"+f1+"\n"+"Given Output:\n"+f2)
            fa.close()
        a +=1
    a = 0
    function += 1

print("\nGrade: "+str(count)+"/"+str(700)+"\n")
print("Check 'difference' folder for differences between expected output and your output (if there are any).")