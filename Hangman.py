#Hangman game is a guessing game.
#You have given a word from an unknown list and you have to guess the word by entering characters

import random

friends_name = ["divyanshu", "nirmal", "palash", "priyanshu", "rahul", "tanushree", "zuber"]
avengers_name = ["blackwidow", "captainamerica", "captainmarvel", "doctorstrange", "hulk", "ironman", "spiderman", "thor"]
language_name = ["dutch", "english", "french", "hindi", "sanskrit"]
list_of_words = [friends_name, avengers_name, language_name]

#--------------------------------------------------------------------------------------#
def hangman() :
    #selecting random word
    list = random.choice(list_of_words)
    word = random.choice(list)
    
    #guessed characters are stored in 'guess' for future reference
    guess = ""
    #updated guessed word
    guess_word = ""
    #list of valid characters
    valid_char = "abcdefghijklmnopqrstuvwxyz"

    live = 10
    print("Guess the word : ", end = "")
    for i in word :
        print("_", end = " ")
    print()

    while True :
        char = input("\nEnter a character : ")
        if char not in valid_char :
            print("  You entered an invalid character!!!")
            continue
        else :
            if char in word:
                if char not in guess :
                    guess += char
            else :
                print("Your guess is wrong.")
                live -= 1
                

        #You win if you guess all letters from the word
        if set(guess) == set(word) :
            print("  YOU WIN (*_*) __CONGRATULATIONS__")
            print("The word you guess is : " + word)
            print("Thanks for saving Lokesh's life, You are such a true friend.")
            break
        
        #printing guessed letters
        print("Your guess : ", end = " ")
        for letter in word :
            if letter in guess :
                print(letter, end = " ")
            else :
                print("_", end = " ")
        print()


        print("Remainig Lives = " + str(live))

        print("_______________")
        if live == 9 :
            print("|     O     |")
            print("|           |")
            print("|           |")
            print("|           |")
        elif live == 8 :
            print("|     O     |")
            print("|     |     |")
            print("|           |")
            print("|           |")
        elif live == 7 :
            print("|   \ O     |")
            print("|     |     |")
            print("|           |")
            print("|           |")
        elif live == 6 :
            print("|   \ O /   |")
            print("|     |     |")
            print("|           |")
            print("|           |")
        elif live == 5 :
            print("|   \ O /   |")
            print("|     |     |")
            print("|    /      |")
            print("|           |")
        elif live == 4 :
            print("|   \ O /   |")
            print("|     |     |")
            print("|    / \    |")
            print("|           |")
        elif live == 3 :
            print("|   \ O /|  |")
            print("|     |     |")
            print("|    / \    |")
            print("|           |")
        elif live == 2 :
            print("|   \ O /_| |")
            print("|     |     |")
            print("|    / \    |")
            print("|           |")
        elif live == 1 :
            print("|   \ O__|  |")
            print("|     |     |")
            print("|    / \    |")
            print("|           |")
            print("Last breath, be carefull (o_o)")
        elif live == 0 :
            print("|     O__|  |")
            print("|    /|\    |")
            print("|    / \    |")
            print("|           |")
            print("You killed Lokesh. (+_+)")


#________________________________________________________________________________#
print("\tHANGMAN(LOKESH) GAME\n")
print("A boy named Lokesh is tired from his boring life. He wants some kick in his life like devilal.")
print("So he decided to hang from ceil. But he gives a chance to his friends who can save his life.")
print("Lokesh gives a length of word and his friends have to guess the word.")
print("If friends did not guessed, he will hang like hangman.")
print("\nGUIDLINES and RULES :")
print("1.A random word is given to you, you have to guess the word by entering letters of word.")
print("2.You have only 10 lives to guess the word, in each wrong guess the lives will decrease by 1.")
print("3.You have to use only 26 letters of alphabets.")
print("4.You have to guess all unique letters in the word.")
print("5.A word may be a friend's name, international language or any avenger's name.")
print("You have to save LOKESH before he hangs.")

name = input("\nEnter Your name : ")
print("Welcome in my game " + name + " (^_^)")
print()

while True :
    hangman()
    choice = input("\nWant to play again (y/n): ")
    if choice != 'y' :
        print()
        break

print("\nThanks for playing " + name + " (^_^)")
