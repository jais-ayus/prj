import os
import json

class TaskManager:
    def __init__(self, filename="tasks.json"):
        self.filename = filename
        self.tasks = self.load_tasks()

    def load_tasks(self):
        if os.path.exists(self.filename):
            with open(self.filename, 'r') as file:
                try:
                    tasks = json.load(file)
                except json.JSONDecodeError:
                    tasks = []
        else:
            tasks = []
        return tasks

    def save_tasks(self):
        with open(self.filename, 'w') as file:
            json.dump(self.tasks, file, indent=2)

    def display_tasks(self):
        if not self.tasks:
            print("No tasks available.")
        else:
            for index, task in enumerate(self.tasks, start=1):
                print(f"{index}. {task}")

    def add_task(self, task):
        self.tasks.append(task)
        self.save_tasks()
        print("Task added successfully.")

    def delete_task(self, task_index):
        if 1 <= task_index <= len(self.tasks):
            deleted_task = self.tasks.pop(task_index - 1)
            self.save_tasks()
            print(f"Task '{deleted_task}' deleted successfully.")
        else:
            print("Invalid task index.")

def main():
    task_manager = TaskManager()

    while True:
        print("\n=== Task Manager ===")
        print("1. View Tasks")
        print("2. Add Task")
        print("3. Delete Task")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == '1':
            task_manager.display_tasks()
        elif choice == '2':
            new_task = input("Enter the task: ")
            task_manager.add_task(new_task)
        elif choice == '3':
            task_manager.display_tasks()
            task_index = int(input("Enter the task index to delete: "))
            task_manager.delete_task(task_index)
        elif choice == '4':
            print("Exiting Task Manager. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 4.")

if __name__ == "__main__":
    main()
