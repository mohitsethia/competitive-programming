Time Complexity: O((n^3)*logn), where n->number of customers
Summary:
    Finds out the profit earned in each combination of customer for each product and storing the result for the maximum profit.
How the code works:
    INPUT: 
        1. First four Integers are the profits from ith product
        2. Second Line of Input represents the total numbmer of customer
        3. Next four lines contains the cost of cpu and gpu for ith product (0 if product doesn't require CPU/GPU)
        4. Two Integer containing total units of CPU and GPU.
    
    OUTPUT:
        4 lines with a text "Selling Product i to j customers" representing ith product to be sold to j customers for maximum profit.
    
    WORKING:
        Checking for the profit for each combination of customer for each product within given cost of CPU and GPU. Checking the maximum number of products that can be sold 
            -3 loops [0,50] for first 3 products
            -4th inner loop is binary search for last product
        A vector storing result for the maximum profit earned
The Given code can be execute with the given input.txt file and the output is stored in output.txt file
