# Math Quiz

A C++ console-based Math Quiz game where the player answers randomly generated arithmetic questions based on the selected difficulty level and operation type.

## Features

- Choose the number of questions
- Choose the question difficulty:
  - Easy
  - Medium
  - Hard
  - Mix
- Choose the operation type:
  - Addition
  - Subtraction
  - Multiplication
  - Division
  - Mix
- Randomly generates numbers based on the selected difficulty
- Randomly selects operations when using Mix
- Checks the player's answers
- Displays the correct answer when the player gives a wrong answer
- Tracks the number of correct answers
- Tracks the number of wrong answers
- Determines whether the player passed or failed
- Displays the final game results
- Option to play the game again

## Difficulty Levels

The game supports four difficulty options:

```text
1 - Easy
2 - Medium
3 - Hard
4 - Mix
```

The generated numbers are based on the selected level:

- **Easy:** 1 - 10
- **Medium:** 10 - 50
- **Hard:** 50 - 100
- **Mix:** Randomly selects Easy, Medium, or Hard for each question

## Operation Types

```text
1 - Addition
2 - Subtraction
3 - Multiplication
4 - Division
5 - Mix
```

When **Mix** is selected, the program randomly chooses one of the four operations for each question.

## Game Result

After answering all questions, the program displays:

- Pass or Fail status
- Number of questions
- Selected question level
- Selected operation type
- Number of correct answers
- Number of wrong answers

The player passes when the number of correct answers is greater than half of the total questions.

## Technologies

- **C++**
- Enums
- Structs
- Functions
- Loops
- Switch statements
- Conditional statements
- Random number generation
- User input
- Console output

## Project Structure

```text
Math-Quiz/
│
├── math_quiz_project.cpp
└── README.md
```

## How to Run

Make sure you have a C++ compiler such as `g++` installed.

Compile the program:

```bash
g++ math_quiz_project.cpp -o math_quiz
```

Run the program:

```bash
./math_quiz
```

## How It Works

The game starts by asking the player how many questions they want to answer.

The player then selects:

1. The difficulty level.
2. The operation type.

For every question, the program:

1. Generates two random numbers according to the selected difficulty.
2. Selects the operation.
3. Calculates the correct answer.
4. Displays the question.
5. Reads the player's answer.
6. Checks whether the answer is correct.
7. Updates the correct or wrong answer count.
8. Displays the result.

After all questions are completed, the program displays the final result and allows the player to start another game.

## Purpose

This project was built to practice C++ programming concepts by creating a complete console-based Math Quiz application using enums, structs, functions, loops, conditions, and random number generation.

## Author

**Mohamed**
