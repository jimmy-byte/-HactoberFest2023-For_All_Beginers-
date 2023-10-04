import random

# List of words to choose from
words = ["python", "hangman", "programming", "computer", "gaming"]

# Select a random word from the list
word = random.choice(words)

# Create a list to store the guessed letters
guessed_letters = []

# Number of attempts allowed
max_attempts = 6

# Initialize the display word as underscores
display_word = ['_'] * len(word)

# Function to display the current state of the word
def display_current_word(word, guessed_letters):
    display = ""
    for letter in word:
        if letter in guessed_letters:
            display += letter
        else:
            display += "_"
    return display

# Main game loop
while True:
    print("\n" + display_current_word(word, guessed_letters))
    
    # Ask the player to guess a letter
    guess = input("Guess a letter: ").lower()
    
    # Check if the guess is valid
    if len(guess) != 1 or not guess.isalpha():
        print("Invalid input. Please enter a single letter.")
        continue
    
    # Check if the letter has already been guessed
    if guess in guessed_letters:
        print("You've already guessed that letter.")
        continue
    
    # Add the guessed letter to the list
    guessed_letters.append(guess)
    
    # Check if the guessed letter is in the word
    if guess in word:
        print("Good guess!")
    else:
        print("Wrong guess!")
        max_attempts -= 1
        
    # Check if the player has won or lost
    if set(word) == set(guessed_letters):
        print("Congratulations! You've won. The word is:", word)
        break
    elif max_attempts == 0:
        print("You've run out of attempts. The word was:", word)
        break
