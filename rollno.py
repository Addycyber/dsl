import random

def linear_search(roll_numbers, target):
    for i in range(len(roll_numbers)):
        if roll_numbers[i] == target:
            return True
    return False

def sentinel_search(roll_numbers, target):
    # Adding a sentinel at the end of the array
    roll_numbers.append(target)

    i = 0
    while roll_numbers[i] != target:
        i += 1

    # Removing the sentinel
    roll_numbers.pop()
    
    return i < len(roll_numbers)

# Main program
if __name__ == "__main__":
    # Generating random roll numbers
    roll_numbers = random.sample(range(1000, 2000), 20)

    print("Roll Numbers of Students who attended the training program:")
    print(roll_numbers)

    # Asking user for input
    target_roll = int(input("Enter the roll number to search: "))

    # Linear Search
    linear_result = linear_search(roll_numbers, target_roll)
    if linear_result:
        print(f"{target_roll} attended the training program (Linear Search)")
    else:
        print(f"{target_roll} did not attend the training program (Linear Search)")

    # Sentinel Search
    sentinel_result = sentinel_search(roll_numbers, target_roll)
    if sentinel_result:
        print(f"{target_roll} attended the training program (Sentinel Search)")
    else:
        print(f"{target_roll} did not attend the training program (Sentinel Search)")
