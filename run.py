import subprocess
import os
import time
from datetime import datetime

# Path of your repository
repo_path = r"C:\Users\HP\OneDrive\Desktop\DSA"

while True:
    try:
        os.chdir(repo_path)

        # Add all files
        subprocess.run(["git", "add", "."])

        # Check if there are changes
        status = subprocess.run(
            ["git", "status", "--porcelain"],
            capture_output=True,
            text=True
        ).stdout

        if status.strip():
            commit_msg = "Auto commit " + datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            subprocess.run(["git", "commit", "-m", commit_msg])
            subprocess.run(["git", "push", "origin", "main"])
            print("✅ Changes pushed to GitHub")
        else:
            print("No changes to push")

    except Exception as e:
        print("Error:", e)

    # Run every 10 seconds
    time.sleep(10)