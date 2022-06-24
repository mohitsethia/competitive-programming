arr = [3,7,1,5,9,2,6,4,9]

1, 7, 3, 2, 9, 5, 9, 4, 6

3, 7, 1

3, 7, 1         1, 7, 3     i = 0
5, 9, 2         2, 9, 5     i = 3
6, 4, 9         9, 4, 6     i = 6
vector<int> ReverseArrayinGroup(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i += 3) {
        swap(arr[i], arr[i+2]);
    }
    return arr;
}


//second highest salary

SELECT
    MAX(salary)
FROM
    EMPLOYEE
WHERE 
    salary IS NOT IN (SELECT MAX(salary) FROM EMPLOYEE)
LIMIT 1;
