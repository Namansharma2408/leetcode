import os
import requests
from pathlib import Path

LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")
LEETCODE_CSRF_TOKEN = os.getenv("LEETCODE_CSRF_TOKEN")

SAVE_DIR = Path("leetcode")
SAVE_DIR.mkdir(exist_ok=True)

url = "https://leetcode.com/api/submissions/"

cookies = {
    "LEETCODE_SESSION": LEETCODE_SESSION,
    "csrftoken": LEETCODE_CSRF_TOKEN
}

headers = {
    "x-csrftoken": LEETCODE_CSRF_TOKEN,
    "referer": "https://leetcode.com/",
    "user-agent": "Mozilla/5.0"
}

response = requests.get(url, cookies=cookies, headers=headers)

if response.status_code != 200:
    print("Request failed:", response.status_code)
    exit()

data = response.json()
submissions = data.get("submissions_dump", [])

for sub in submissions:
    if sub["status_display"] != "Accepted":
        continue

    title = sub["title"]
    slug = sub["title_slug"]
    lang = sub["lang"]

    file_path = SAVE_DIR / f"{slug}.md"

    if file_path.exists():
        continue

    content = f"""# {title}

Slug: {slug}
Language: {lang}
Status: Accepted
"""

    file_path.write_text(content, encoding="utf-8")
    print("Saved:", slug)
