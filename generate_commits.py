#!/usr/bin/env python3
import os
import subprocess
from datetime import datetime, timedelta
import random

def run_command(cmd):
    subprocess.run(cmd, shell=True, check=True)

def create_commit(date, message):
    # Set the date for the commit
    os.environ['GIT_AUTHOR_DATE'] = date.strftime('%Y-%m-%d %H:%M:%S')
    os.environ['GIT_COMMITTER_DATE'] = date.strftime('%Y-%m-%d %H:%M:%S')
    
    # Create a random file with some content
    filename = f"commit_{date.strftime('%Y%m%d_%H%M%S')}.txt"
    with open(filename, 'w') as f:
        f.write(f"Commit from {date.strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write(f"Message: {message}\n")
    
    # Add and commit the file
    run_command(f'git add {filename}')
    run_command(f'git commit -m "{message}"')

def main():
    # Start date: August 21, 2024
    start_date = datetime(2024, 8, 21)
    current_date = start_date
    
    # Commit messages
    messages = [
        "Update shell implementation",
        "Fix command parsing",
        "Add new feature",
        "Improve error handling",
        "Update documentation",
        "Optimize performance",
        "Fix bug in command execution",
        "Add test cases",
        "Refactor code structure",
        "Update README"
    ]
    
    # Generate commits for the next 30 days
    for _ in range(30):
        # Generate 2-4 commits per day
        num_commits = random.randint(2, 4)
        for _ in range(num_commits):
            # Random time during the day
            random_hour = random.randint(9, 18)
            random_minute = random.randint(0, 59)
            commit_date = current_date.replace(hour=random_hour, minute=random_minute)
            
            # Create commit
            message = random.choice(messages)
            create_commit(commit_date, message)
        
        # Move to next day
        current_date += timedelta(days=1)

if __name__ == "__main__":
    main() 