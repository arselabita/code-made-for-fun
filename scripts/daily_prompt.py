# scripts/daily_prompt.py

import requests, os
from datetime import date

today = date.today().isoformat()
folder_prompts = "prompts"
folder_code = "snippets"
md_file = f"{folder_prompts}/{today}.md"
c_file = f"{folder_code}/{today}.c"

os.makedirs(folder_prompts, exist_ok=True)
os.makedirs(folder_code, exist_ok=True)

if not os.path.exists(md_file):
    url = "https://leetcode.com/graphql"
    query = {
        "query": """
        query questionOfToday {
          activeDailyCodingChallengeQuestion {
            date
            link
            question {
              title
              difficulty
            }
          }
        }
        """
    }
    res = requests.post(url, json=query).json()
    q = res["data"]["activeDailyCodingChallengeQuestion"]

    # Save Markdown prompt
    with open(md_file, "w") as f:
        f.write(f"# {today}\n\n")
        f.write(f"**{q['question']['title']}** ({q['question']['difficulty']})\n\n")
        f.write(f"[Solve on LeetCode](https://leetcode.com{q['link']})\n")

    # Save starter C file
    with open(c_file, "w") as f:
        f.write(f"// {today} - {q['question']['title']} ({q['question']['difficulty']})\n")
        f.write("// Prompt: see corresponding markdown file in prompts/\n\n")
        f.write("#include <stdio.h>\n\n")
        f.write("int main() {\n")
        f.write("    // Your solution here\n")
        f.write("    return 0;\n")
        f.write("}\n")

    print(f"✅ Created {md_file} and {c_file}")
else:
    print(f"ℹ️ {md_file} already exists")
