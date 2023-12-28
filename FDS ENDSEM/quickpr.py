def quicksort(marks):
    if len(marks) <= 1:
        return marks
    pivot = marks[len(marks)//2]
    left = [x for x in marks if x<pivot]
    middle = [x for x in marks if x==pivot]
    right = [x for x in marks if x>pivot]
    return quicksort(left)+middle+quicksort(right)

def get(size):
    print("Enter the marks : ")
    marks=[]
    for i in range(size):
        x=float(input("Enter the marks for student {} : ".format(i+1)))
        marks.append(x)
    return marks

def display_top_scores(marks):
    ans=quicksort(marks)
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