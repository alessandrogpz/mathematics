import os
import random
import argparse

def get_random_questions(count=5, topic=None, base_path="02_Exercises"):
    questions = []
    
    # Path to search
    search_path = base_path
    if topic:
        # Check if the topic directory exists
        potential_path = os.path.join(base_path, topic.capitalize())
        if os.path.exists(potential_path):
            search_path = potential_path
        else:
            print(f"Warning: Topic folder '{topic}' not found in {base_path}. Searching all topics instead.")

    # Walk through the directory structure
    for root, dirs, files in os.walk(search_path):
        # Only look inside folders named 'Questions'
        if os.path.basename(root) == "Questions":
            for file in files:
                if file.endswith(".md") and file.startswith("Q_"):
                    questions.append(os.path.join(root, file))
    
    if not questions:
        print("No questions found.")
        return

    # Ensure we don't try to pick more than we have
    sample_size = min(count, len(questions))
    selected = random.sample(questions, sample_size)
    
    topic_str = f"Topic: {topic.capitalize()}" if topic else "All Topics"
    print(f"--- Random Selection ({sample_size} questions from {topic_str}) ---")
    for i, path in enumerate(selected, 1):
        print(f"{i}. [[{os.path.basename(path)}]] (Path: {path})")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Pick random math questions.")
    parser.add_argument("topic", nargs="?", default=None, help="Optional topic folder to search within (e.g., Vectors)")
    parser.add_argument("-n", "--number", type=int, default=5, help="Number of questions to pick (default: 5)")
    args = parser.parse_args()
    
    get_random_questions(args.number, args.topic)
