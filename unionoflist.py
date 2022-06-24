print("Mohit Sethia, 11500118090")
list1 =[]
list2 = []
number = int(input("Enter how many values you want in list 1 :"))
for i in range(0, number):
    numbers = int(input("Enter the element :"))
    list1.append(numbers)
number = int(input("Enter how many values you want in list 2 :"))
for i in range(0, number):
    numbers = int(input("Enter the element :"))
    list2.append(numbers)
for i in range(len(list2)):
    if list2[i] not in list1:
        list1.append(list2[i])
print(list1)
