def binary_search(roll_numbers, target):
    low, high = 0, len(roll_numbers) - 1

    while low <= high:
        mid = (low + high) // 2
        if roll_numbers[mid] == target:
            return True
        elif roll_numbers[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return False

def fibonacci_search(roll_numbers, target):
    def fibonacci_gen(n):
        fib = [0, 1]
        while fib[-1] < n:
            fib.append(fib[-1] + fib[-2])
        return fib

    n = len(roll_numbers)
    fib = fibonacci_gen(n)

    offset = 0
    while fib[-2] > 1:
        i = min(offset + fib[-2], n - 1)
        if roll_numbers[i] < target:
            fib = fib[:-2]
            offset = i
        elif roll_numbers[i] > target:
            fib = fib[:-1]
        else:
            return True

    if fib[0] and roll_numbers[offset] == target:
        return True

    return False

# Main program
if __name__ == "__main__":
    # Assuming the roll numbers are sorted
    roll_numbers = [1002, 1204, 1306, 1508, 1710, 1912, 2114, 2316, 2518, 2720]

    print("Roll Numbers of Students who attended the training program:")
    print(roll_numbers)

    # Asking user for input
    target_roll = int(input("Enter the roll number to search: "))

    # Binary Search
    binary_result = binary_search(roll_numbers, target_roll)
    if binary_result:
        print(f"{target_roll} attended the training program (Binary Search)")
    else:
        print(f"{target_roll} did not attend the training program (Binary Search)")

    # Fibonacci Search
    fibonacci_result = fibonacci_search(roll_numbers, target_roll)
    if fibonacci_result:
        print(f"{target_roll} attended the training program (Fibonacci Search)")
    else:
        print(f"{target_roll} did not attend the training program (Fibonacci Search)")
