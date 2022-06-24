print("Mohit Sethia, 11500118090")
list1 = []
number = int(input("How many values you want in list :"))
for i in range(0, number):
    numbers = input("Enter your choice :")
    list1.append(numbers)
for j in list1:
    stri=""
    k = 0
    for i in range(len(j)-1, -1, -1):
        stri = stri + j[i]
        k = k + 1
    if k%2!=0 and stri == j:
        print(j)




