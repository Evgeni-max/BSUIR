import re

def is_valid_plate(seq):
    """Check if seq matches car plate pattern: e.g. 3 letters + 3 digits."""
    return bool(re.match(r"^[A-Z]{3}\d{3}$", seq))