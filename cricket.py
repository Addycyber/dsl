# Function to find and display students who play either cricket or badminton or both
def either_cricket_or_badminton(cricket_players, badminton_players):
    either_set = cricket_players.union(badminton_players)
    print("A. Set of students who play either cricket or badminton or both:")
    print(either_set)

# Function to find and display students who play both cricket and badminton
def both_cricket_and_badminton(cricket_players, badminton_players):
    both_set = cricket_players.intersection(badminton_players)
    print("\nB. Set of students who play both cricket and badminton:")
    print(both_set)

# Function to find and display students who play only cricket
def only_cricket(cricket_players, badminton_players):
    only_cricket_set = cricket_players.difference(badminton_players)
    print("\nC. Set of students who play only cricket:")
    print(only_cricket_set)

# Function to find and display students who play only badminton
def only_badminton(cricket_players, badminton_players):
    only_badminton_set = badminton_players.difference(cricket_players)
    print("\nD. Set of students who play only badminton:")
    print(only_badminton_set)

# Function to find and display the number of students who play neither cricket nor badminton
def neither_cricket_nor_badminton(total_students, cricket_players, badminton_players):
    neither_set = total_students.difference(cricket_players.union(badminton_players))
    print("\nE. Number of students who play neither cricket nor badminton:", len(neither_set))

# Example sets of students
total_students = set(range(1, 21))  # Assuming 20 students in the class
cricket_players = {2, 4, 6, 8, 10}
badminton_players = {1, 3, 6, 9, 12}

# Display the results
either_cricket_or_badminton(cricket_players, badminton_players)
both_cricket_and_badminton(cricket_players, badminton_players)
only_cricket(cricket_players, badminton_players)
only_badminton(cricket_players, badminton_players)
neither_cricket_nor_badminton(total_students, cricket_players, badminton_players)
