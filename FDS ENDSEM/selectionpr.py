def selectionsort(arr):
    n=len(arr)
    for i in range(n):
        min = i
        for j in range(i+1,n):
            if arr[j]<arr[min]:
                min = j
        arr[i],arr[min]=arr[min],arr[i]
    return arr

def get(size):
    print("Enter the marks : ")
    marks=[]
    for i in range(size):
        x=float(input("Enter the marks for student {} : ".format(i+1)))
        marks.append(x)
    return marks

def display_top_scores(marks):
    ans=selectionsort(marks)
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