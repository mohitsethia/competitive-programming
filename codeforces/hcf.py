print("Mohit Sethia, 11500118090")
def hcf(a, b):
    for i in range(1, min(a,b)+1):
        if a%i==0 and b%i==0:
            k = i
        return k
a = int(input("Enter 1st number "))
b = int(input("Enter 2nd number "))
c = int(input("Enter 3rd number "))
lcm=((a*b*c)*hcf(hcf(a,b),c))//(hcf(a,b)*hcf(b,c)*hcf(a,c))
print("lcm=",lcm)

