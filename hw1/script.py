import os

def rename_files(directory):
    for filename in os.listdir(directory):
        if filename.startswith(""):
            new_filename = filename.replace("", "", 1)
            os.rename(os.path.join(directory, filename), os.path.join(directory, new_filename))
            print(f"Renamed '{filename}' to '{new_filename}'")

# Replace 'directory_path' with the path to the directory containing the files you want to rename
directory_path = ""
rename_files(directory_path)
