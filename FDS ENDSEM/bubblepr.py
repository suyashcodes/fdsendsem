def bubblesort(marks):
    n = len(marks)
    for i in range(n):
        for j in range(0,n-i-1):
            if marks[j]>marks[j+1]:
                marks[j],marks[j+1]=marks[j+1],marks[j]
    return marks

def get(size):
    print("Enter the marks : ")
    marks=[]
    for i in range(size):
        x=float(input("Enter the marks for student {} : ".format(i+1)))
        marks.append(x)
    return marks

def display_top_scores(marks):
    ans=bubblesort(marks)
    j=1
    print("Top 5 scores : ")
    for i in range(len(ans)-1,len(ans)-6,-1):
        print("{}. {:.2f}".format(j,ans[i]))
        j+=1

def main():
    while True:
        n = int(input("Enter the number of students : "))
        if n < 1 or n < 5:
            print("Size should be atleast 5 student")
        else:
            break
    marks = get(n)
    display_top_scores(marks)

if __name__=="__main__":
    main()