def selection_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if the element found is greater than the next element
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Function to display the top five scores
def display_top_five(arr):
    print("Top five scores:")
    for i in range(min(5, len(arr))):
        print(f"{i+1}. {arr[i]}%")

# Main program
if __name__ == "__main__":
    # Input: first year percentages of students
    percentages = [89.5, 76.8, 92.3, 85.0, 78.2, 95.1, 88.7, 91.5, 82.4, 79.9]

    # Sorting using Selection Sort
    selection_sort_percentages = percentages.copy()
    selection_sort(selection_sort_percentages)
    print("After Selection Sort:")
    print(selection_sort_percentages)

    # Sorting using Bubble Sort
    bubble_sort_percentages = percentages.copy()
    bubble_sort(bubble_sort_percentages)
    print("\nAfter Bubble Sort:")
    print(bubble_sort_percentages)

    # Display top five scores
    print("\n")
    display_top_five(bubble_sort_percentages)
