from urllib.request import Request, urlopen
from urllib.parse import quote
from pathlib import Path
from bs4 import BeautifulSoup
import json
from datetime import datetime, timedelta
import logging
from typing import Tuple, Dict, List

DIFFICULTY_IMAGES = {
    "Easy": "https://github.com/ejrcarr/Kattis/assets/110308975/31c14685-cac9-4880-9e82-4a745ddafa96",
    "Medium": "https://github.com/ejrcarr/Kattis/assets/110308975/81add9d4-3812-4669-8e32-f06635bf042a",
    "Hard": "https://github.com/ejrcarr/Kattis/assets/110308975/93294158-642c-4787-9811-99e1a2be8307"
}
LANGUAGES = {
    "py": "Python", "cpp": "C++", "java": "Java", "js": "JavaScript", "c":"C", 
    "cs":"C#", "html":"HTML", "css":"CSS", "php":"PHP", "rb":"Ruby", "go":"Go", 
    "kt":"Kotlin", "swift":"Swift"
}
LANGUAGES_EXTENSIONS = {v.lower(): k for k, v in LANGUAGES.items()}
USER_AGENT = 'Mozilla/5.0'
URL_BASE = "https://open.kattis.com/problems/"
URL_SUFFIX = "?tab=metadata"
UPDATE_THRESHOLD_DAYS = 7

SCRIPT_DIR = Path(__file__).resolve().parent
BASE_DIR = SCRIPT_DIR.parent
PROBLEM_FILE_NAME = BASE_DIR / "problems.json"
README_FILE_NAME = BASE_DIR / "README.md"
SOLUTION_DIR_NAME = BASE_DIR / "Solutions"

DATE_FORMAT = "%Y-%m-%d"
LOG_FORMAT = '%(asctime)s - %(levelname)s - %(message)s'

logging.basicConfig(level=logging.INFO, format=LOG_FORMAT)

def _load_json_data(file_path: Path) -> List[Dict]:
    with open(file_path, "r") as f:
        return json.load(f)

def _save_json_data(file_path: Path, data: List[Dict]) -> None:
    with open(file_path, "w") as f:
        json.dump(data, f, indent=4)

def _fetch_website_data(problem_name: str, url_base: str, url_suffix: str) -> Tuple[str, str]:
    url = f"{url_base}{quote(problem_name)}{url_suffix}"
    req = Request(url=url, headers={'User-Agent': 'Mozilla/5.0'})
    with urlopen(req) as html:
        html_content = html.read()
    soup = BeautifulSoup(html_content, 'html.parser')
    return _parse_problem_data(soup)

def _parse_problem_data(soup: BeautifulSoup) -> Tuple[str, str]:
    difficulty_rating_span = soup.find('div', class_='metadata-difficulty-card').find('span', class_=lambda value: value and 'difficulty_number' in value)
    difficulty_rating = difficulty_rating_span.text.strip() if difficulty_rating_span else 'Not found'
    
    difficulty_name_div = soup.find('div', class_='metadata-difficulty-card').find_all('div')[0]
    difficulty_name_span = difficulty_name_div.find_all('span')[-1] if difficulty_name_div else None
    difficulty_name = difficulty_name_span.text.strip() if difficulty_name_span else 'Not found'
    
    return difficulty_name, difficulty_rating

def _parse_rating(rating_str: str) -> float:
    if '-' in rating_str:
        try:
            lower_bound, upper_bound = map(float, rating_str.split('-'))
            return (lower_bound + upper_bound) / 2
        except ValueError:
            return float('inf')
    else:
        try:
            return float(rating_str)
        except ValueError:
            return float('inf')

def _create_readme_content(problems: List[Dict]) -> str:
    readme = "<h1 float='left'> Kattis <img align='right' width='100px' src='https://github.com/ejrcarr/Kattis/assets/110308975/dc33e524-954b-4edf-a8ac-c96072230cc8' alt='Kattis logo'/> </h1>\n\n"
    readme += "A collection of my various solutions to problems found on Kattis.\n\n"

    readme += "<!--\n"
    for img_url in DIFFICULTY_IMAGES.values():
        readme += f"<img height='27px' src='{img_url}'/>\n"
    readme += "-->\n"

    sorting_options = {
        "Alphabetical [A-Z]": lambda p: p["name"].lower(),
        "Alphabetical [Z-A]": lambda p: p["name"].lower(),
        "Rating ↓": lambda p: -_parse_rating(p["difficulty_rating"]),
        "Rating ↑": lambda p: _parse_rating(p["difficulty_rating"]),
    }

    readme += "## Sort\n"
    for option, sort_key in sorting_options.items():
        sorted_problems = sorted(problems, key=sort_key, reverse=option in ["Alphabetical [Z-A]"])

        readme += f"<details{' open' if option == 'Alphabetical [A-Z]' else ''}>\n"
        readme += f"  <summary>{option}</summary>\n"
        readme += "  <br>\n  <br>\n"
        readme += "  <div align='center'>\n\n"
        readme += "| Problem Name | Problem ID | Difficulty | Rating | Solution |\n"
        readme += "| :---         | :---       |  :----:    | :-:    | ---      |\n"

        for problem in sorted_problems:
            difficulty_img = DIFFICULTY_IMAGES.get(problem["difficulty_name"], "")
            solutions_links = []
            for lang in problem['languages']:
                lang_name = lang
                lang_extension = LANGUAGES_EXTENSIONS.get(lang_name.lower(), '')
                solution_file_path = f"{problem['name']}/{problem['filename']}.{lang_extension}"
                solution_url_encoded = quote(solution_file_path)
                solution_url = f"./Solutions/{solution_url_encoded}"
                solutions_links.append(f"<a href='{solution_url}'>{lang_name}</a>")

            solutions_str = ', '.join(solutions_links)
            readme += f"| <a href='{problem['url']}'>{problem['name']}</a> | {problem['filename']} | <img height='27px' src='{difficulty_img}'/> | {problem['difficulty_rating']} | {solutions_str} |\n"

        readme += "\n  </div>\n"
        readme += "</details>\n\n"
    return readme

def _save_readme_content(content: str) -> None:
    with open(README_FILE_NAME, "w") as f:
        f.write(content)

def update_problems() -> None:
    current_dir = Path(__file__).parent.absolute()
    solution_dir = current_dir / SOLUTION_DIR_NAME
    problems_file = current_dir / PROBLEM_FILE_NAME
    old_problems = _load_json_data(problems_file)
    
    update_threshold = timedelta(days=UPDATE_THRESHOLD_DAYS)
    current_date = datetime.now()
    
    updated_problems = []
    for child in solution_dir.iterdir():
        if not child.is_dir():
            continue
        
        problem_languages = [LANGUAGES[file.suffix] for file in child.iterdir() if file.is_file() and file.suffix in LANGUAGES]
        filename = child.name

        existing_problem = next((item for item in old_problems if item["name"] == child.name), None)
        if existing_problem and set(problem_languages) == set(existing_problem["languages"]):
            last_updated = datetime.strptime(existing_problem.get("last_updated", "1970-01-01"), "%Y-%m-%d")
            if current_date - last_updated < update_threshold:
                logging.info(f"Skipped {filename} as it was recently updated.")
                updated_problems.append(existing_problem)
                continue
        
        try:
            difficulty_name, difficulty_rating = _fetch_website_data(filename, URL_BASE, URL_SUFFIX)
        except Exception as e:
            logging.error(f"Error fetching data for {filename}: {e}")
            continue

        problem = {
            "name": filename, 
            "filename": filename, 
            "languages": problem_languages, 
            "url": URL_BASE + filename,
            "difficulty_name": difficulty_name, 
            "difficulty_rating": difficulty_rating,
            "last_updated": current_date.strftime("%Y-%m-%d")
        }
        updated_problems.append(problem)
        logging.info(f"Updated {filename}")

    updated_problems.sort(key=lambda x: x["name"])
    _save_json_data(problems_file, updated_problems)
    logging.info("Updated problems.json")

def update_readme() -> None:
    try:
        problems = _load_json_data(PROBLEM_FILE_NAME)
        readme_content = _create_readme_content(problems)
        _save_readme_content(readme_content)
        logging.info("Successfully updated README.md")
    except Exception as e:
        logging.error(f"Failed to update README.md: {e}")

if __name__ == "__main__":
    update_problems()
    update_readme()