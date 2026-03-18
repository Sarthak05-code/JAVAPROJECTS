import random

students = {
    1: "Aarya", 2: "Aayush D", 3: "Abhishek K", 4: "Abhishek P",
    5: "Anjal", 6: "Anuja", 7: "Ayush C", 8: "Bishal",
    9: "Bisistha", 10: "Dikshant", 11: "Joel", 12: "Kajal",
    13: "Kelvin", 14: "Kritan", 15: "Kshitiz", 16: "Manendra",
    17: "Navraj", 18: "Pradosh", 19: "Prasun", 20: "Rashik",
    21: "Rehan", 22: "Rohan", 23: "Sadiksha", 24: "Saisha",
    25: "Saqullie", 26: "Saroj", 27: "Sarthak",
    28: "Simron", 29: "Sujal"
}

def main():
    group_size = 5

    # Get list of student IDs
    student_ids = list(students.keys())

    # Shuffle IDs
    random.shuffle(student_ids)

    groups = []

    # Split into groups
    for i in range(0, len(student_ids), group_size):
        group_ids = student_ids[i:i + group_size]

        # Convert IDs to names
        group_names = [students[id] for id in group_ids]

        groups.append(group_names)

    # Print groups
    for index, group in enumerate(groups, start=1):
        print(f"Group {index}: {group}")

main()