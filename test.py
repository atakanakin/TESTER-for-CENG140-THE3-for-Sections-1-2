import os

count = 0
function = 1
a = 0
f_count = 0
DIR = 'inputs/func1/'
num_of = len([name for name in os.listdir(DIR) if os.path.isfile(os.path.join(DIR, name))])

os.system('gcc -ansi -Wall -pedantic-errors the3.c test.c -o samp')
while function < 8:
    os.system('rm -r difference/func'+str(function)+'/*')
    os.system('rm -r outputs/func'+str(function)+'/*')
    DIRi = 'inputs/func'+str(function)+'/'
    DIRe = 'expected/func'+str(function)+'/'
    DIRo = 'outputs/func'+str(function)+'/'
    while a < num_of:
        n = str(a)
        os.system('./samp <'+DIRi+'input'+n+'.txt>'+DIRo+'output'+n+'.txt')
        f1 = open(DIRe+"case"+n+".txt", "r").read()
        f2 = open(DIRo+"output"+n+".txt", "r").read() 
        if f1 == f2:
            f_count += 1
            count += 1
        else:
            print("Test "+n+" Failed!")
            fa = open("difference/func"+str(function)+"/difference"+n+".txt", "w")
            fa.write("Expected Output:\n"+f1+"\n"+"Given Output:\n"+f2)
            fa.close()
        a +=1
    a = 0
    
    print("Function "+str(function)+": "+str(f_count)+"/"+str(num_of))
    function += 1
    f_count = 0

print("\nGrade: "+str(count)+"/"+str(7*num_of)+"\n")
print("Check 'difference' folder for differences between expected output and your output (if there are any).")