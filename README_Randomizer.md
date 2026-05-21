# Exercise Randomizer

A simple Python utility to randomly select math exercises from the organized repository.

## Features
- **Topic Filtering:** Select questions from a specific topic (e.g., Vectors, Matrices).
- **Flexible Count:** Choose exactly how many questions you want to retrieve.
- **Smart Fallback:** Searches all available questions if a specific topic folder isn't found.
- **Obsidian Support:** Outputs links in `[[Internal Link]]` format for easy copy-pasting into Obsidian.

## Requirements
- Python 3.x

## Usage

Run the script from the root of the repository:

```bash
python3 randomizer.py [topic] [-n NUMBER]
```

### Examples

| Goal | Command |
| :--- | :--- |
| **Get 5 random questions (Default)** | `python3 randomizer.py` |
| **Get 3 random questions** | `python3 randomizer.py -n 3` |
| **Get 5 questions from Vectors** | `python3 randomizer.py vectors` |
| **Get 2 questions from Matrices** | `python3 randomizer.py matrices -n 2` |

## Directory Structure Compatibility

The script expects questions to be located in sub-folders named `Questions` within topic directories:

```text
02_Exercises/
└── [TopicName]/
    └── Questions/
        └── Q_*.md
```

## Future Expansion
As you add more topics (e.g., `02_Exercises/Calculus/Questions/`), the script will automatically include them in its search without any configuration changes.
