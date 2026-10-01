import requests
import time
from collections import defaultdict


BASE = "https://kenkoooo.com/atcoder/resources"
API = "https://kenkoooo.com/atcoder/atcoder-api/v3"


def get_json(url):
    r = requests.get(url)
    r.raise_for_status()
    return r.json()


# ------------------------------------------------------------
# Difficulty -> AtCoder Problems colour
# ------------------------------------------------------------

def colour(d):
    if d < 400:
        return "Grey"
    if d < 800:
        return "Brown"
    if d < 1200:
        return "Green"
    if d < 1600:
        return "Cyan"
    if d < 2000:
        return "Blue"
    if d < 2400:
        return "Yellow"
    if d < 2800:
        return "Orange"
    return "Red"


colours = [
    "Grey",
    "Brown",
    "Green",
    "Cyan",
    "Blue",
    "Yellow",
    "Orange",
    "Red",
]


# ------------------------------------------------------------
# Username
# ------------------------------------------------------------

user = input("AtCoder username: ").strip()

if not user:
    raise SystemExit("Username cannot be empty.")


# ------------------------------------------------------------
# Problem models
# ------------------------------------------------------------

print("Downloading problem models...")

problem_models = get_json(
    f"{BASE}/problem-models.json"
)

difficulty = {}

for problem_id, model in problem_models.items():

    d = model.get("difficulty")

    if d is not None:
        difficulty[problem_id] = d


# ------------------------------------------------------------
# Contest/problem mapping
# ------------------------------------------------------------

print("Downloading contest/problem data...")

contest_problems = get_json(
    f"{BASE}/contest-problem.json"
)

problem_letter = {}

for p in contest_problems:

    contest_id = p["contest_id"]
    problem_id = p["problem_id"]
    index = p["problem_index"]

    if not contest_id.startswith("abc"):
        continue

    problem_letter[problem_id] = index


# ------------------------------------------------------------
# Get all ABC problem letters
# ------------------------------------------------------------

letters = sorted(
    set(problem_letter.values()),
    key=lambda x: (
        len(x),
        x
    )
)


# ------------------------------------------------------------
# User submissions
# ------------------------------------------------------------

print(f"Downloading submissions for {user}...")

submissions = []

from_second = 0

while True:

    url = (
        f"{API}/user/submissions"
        f"?user={user}"
        f"&from_second={from_second}"
    )

    data = get_json(url)

    if not data:
        break

    submissions.extend(data)

    print(
        f"  downloaded {len(submissions)} submissions"
    )

    if len(data) < 500:
        break

    from_second = data[-1]["epoch_second"] + 1

    time.sleep(1)


print(f"Total submissions: {len(submissions)}")


# ------------------------------------------------------------
# Find AC'd problems
# ------------------------------------------------------------

ac_problems = set()

for submission in submissions:

    if submission["result"] == "AC":
        ac_problems.add(submission["problem_id"])


print(f"Unique AC'd problems: {len(ac_problems)}")


# ------------------------------------------------------------
# Count ALL ABC problems
# ------------------------------------------------------------

total = {
    letter: defaultdict(int)
    for letter in letters
}

missing_total = defaultdict(int)

for problem_id, letter in problem_letter.items():

    if problem_id not in difficulty:
        missing_total[letter] += 1
        continue

    d = difficulty[problem_id]

    total[letter][colour(d)] += 1


# ------------------------------------------------------------
# Count AC'd ABC problems
# ------------------------------------------------------------

solved = {
    letter: defaultdict(int)
    for letter in letters
}

missing_solved = defaultdict(int)

for problem_id in ac_problems:

    if problem_id not in problem_letter:
        continue

    letter = problem_letter[problem_id]

    if problem_id not in difficulty:
        missing_solved[letter] += 1
        continue

    d = difficulty[problem_id]

    solved[letter][colour(d)] += 1


# ------------------------------------------------------------
# Print distribution + AC count
# ------------------------------------------------------------

print()
print(f"ABC difficulty distribution for {user}")

problem_width = 12
column_width = 11

table_width = (
    problem_width
    + (len(letters) + 1) * column_width
)

print("=" * table_width)

print(
    f"{'Difficulty':<{problem_width}}"
    + "".join(
        f"{letter:>{column_width}}"
        for letter in letters
    )
    + f"{'Total':>{column_width}}"
)

print("-" * table_width)

for c in colours:

    row = f"{c:<{problem_width}}"

    row_total = 0
    row_solved = 0

    for letter in letters:

        t = total[letter][c]
        s = solved[letter][c]

        row += f"{f'{t}({s})':>{column_width}}"

        row_total += t
        row_solved += s

    row += f"{f'{row_total}({row_solved})':>{column_width}}"

    print(row)

print("-" * table_width)

row = f"{'Total':<{problem_width}}"

grand_total = 0
grand_solved = 0

for letter in letters:

    t = sum(total[letter].values())
    s = sum(solved[letter].values())

    row += f"{f'{t}({s})':>{column_width}}"

    grand_total += t
    grand_solved += s

row += f"{f'{grand_total}({grand_solved})':>{column_width}}"

print(row)

print("=" * table_width)

# ------------------------------------------------------------
# Print percentage of each colour within each problem
# ------------------------------------------------------------

print()
print("Percentage of colour difficulty within each problem")

problem_width = 12
column_width = 11

table_width = (
    problem_width
    + (len(letters) + 1) * column_width
)

print("=" * table_width)

print(
    f"{'Difficulty':<{problem_width}}"
    + "".join(
        f"{letter:>{column_width}}"
        for letter in letters
    )
    + f"{'Total':>{column_width}}"
)

print("-" * table_width)

grand_total = sum(
    sum(total[letter].values())
    for letter in letters
)

for c in colours:

    row = f"{c:<{problem_width}}"

    colour_total = 0

    for letter in letters:

        problem_total = sum(total[letter].values())
        n = total[letter][c]

        colour_total += n

        if problem_total == 0:
            value = "-"
        else:
            value = f"{100 * n / problem_total:.1f}%"

        row += f"{value:>{column_width}}"

    if grand_total == 0:
        value = "-"
    else:
        value = f"{100 * colour_total / grand_total:.1f}%"

    row += f"{value:>{column_width}}"

    print(row)

print("=" * table_width)


# ------------------------------------------------------------
# Print percentage solved
# ------------------------------------------------------------

print()
print("Percentage of each difficulty bucket that you have AC'd")

problem_width = 12
column_width = 11

table_width = (
    problem_width
    + (len(letters) + 1) * column_width
)

print("=" * table_width)

print(
    f"{'Difficulty':<{problem_width}}"
    + "".join(
        f"{letter:>{column_width}}"
        for letter in letters
    )
    + f"{'Total':>{column_width}}"
)

print("-" * table_width)

for c in colours:

    row = f"{c:<{problem_width}}"

    row_total = 0
    row_solved = 0

    for letter in letters:

        n = total[letter][c]
        s = solved[letter][c]

        row_total += n
        row_solved += s

        if n == 0:
            value = "-"
        else:
            value = f"{100 * s / n:.1f}%"

        row += f"{value:>{column_width}}"

    if row_total == 0:
        value = "-"
    else:
        value = f"{100 * row_solved / row_total:.1f}%"

    row += f"{value:>{column_width}}"

    print(row)

print("=" * table_width)


# ------------------------------------------------------------
# Problems without estimated difficulty
# ------------------------------------------------------------

print()
print("Problems without an estimated difficulty")
print("=" * 60)

for letter in letters:

    print(
        f"{letter}: "
        f"{missing_total[letter]} total, "
        f"{missing_solved[letter]} AC'd"
    )

print("=" * 60)
