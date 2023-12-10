
'''
Write Python program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using quick sort and display top five
scores.

'''



def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

# Function to display the top five scores
def display_top_five(arr):
    print("Top five scores:")
    for i in range(min(5, len(arr))):
        print(f"{i + 1}. {arr[i]}%")

# Main program
if __name__ == "__main__":
    # Input: first-year percentages of students
    percentages = [89.5, 76.8, 92.3, 85.0, 78.2, 95.1, 88.7, 91.5, 82.4, 79.9]

    print("First Year Percentages:")
    print(percentages)

    # Sorting using Quicksort
    sorted_percentages = quicksort(percentages)
    print("\nAfter Quicksort:")
    print(sorted_percentages)

    # Display top five scores
    print("\n")
    display_top_five(sorted_percentages)
