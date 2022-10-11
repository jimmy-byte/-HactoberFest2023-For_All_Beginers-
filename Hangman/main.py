import random
from hangman_art import stages
from hangman_art import logo
from hangman_words import word_list

print(logo)

chosen_word = random.choice(word_list)
word_len = len(chosen_word)
lives = 6

display = []
for i in range(0,word_len):
    display.append("_")
print(display)
print(chosen_word)
end_of_game = False
while not end_of_game:
    guess = (input("Guess a letter : ")).lower()
    if guess in display:
        print(f"You have already guessed {guess}")
    for position in range(0,word_len):
        letter = chosen_word[position]
        #print(f"Current position : {position}\nCurrent letter : {letter}\nGuessed letter : {guess}")
        if letter == guess:
           display[position] = letter 
    if guess not in chosen_word:
        print(f"You guesses {guess} that's not in the word")
        lives -= 1
        if lives == 0:
            end_of_game = True
            print('''
 __     ______  _    _   _      ____   _____ ______ 
 \ \   / / __ \| |  | | | |    / __ \ / ____|  ____|
  \ \_/ / |  | | |  | | | |   | |  | | (___ | |__   
   \   /| |  | | |  | | | |   | |  | |\___ \|  __|  
    | | | |__| | |__| | | |___| |__| |____) | |____ 
    |_|  \____/ \____/  |______\____/|_____/|______|
            ''')
    if "_" not in display:
        end_of_game = True
        print('''
 __     ______  _    _  __          _______ _   _ 
 \ \   / / __ \| |  | | \ \        / /_   _| \ | |
  \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| |
   \   /| |  | | |  | |   \ \/  \/ /   | | | . ` |
    | | | |__| | |__| |    \  /\  /   _| |_| |\  |
    |_|  \____/ \____/      \/  \/   |_____|_| \_|
        ''')
print(stages[lives])