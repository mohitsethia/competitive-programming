def rotate( arr, n):
    l=[arr[-1]]
    l+=arr[0:n-1]
    arr=l
def main():
    T = int(input())
    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        rotate(a, n)
        print(*a)
        
        T -= 1
    
if __name__ == "__main__":
    main()
