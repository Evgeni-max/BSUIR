import zipfile
import os

def read_text(path):
    """Read and return text from file."""
    with open(path, 'r', encoding='utf-8') as f:
        return f.read()

def write_results(path, data):
    """Write string data to a file."""
    with open(path, 'w', encoding='utf-8') as f:
        f.write(data)

def archive_file(file_path, archive_name):
    """Archive a single file and return info."""
    with zipfile.ZipFile(archive_name, 'w') as zf:
        zf.write(file_path, arcname=os.path.basename(file_path))
        info = zf.getinfo(os.path.basename(file_path))
    return info