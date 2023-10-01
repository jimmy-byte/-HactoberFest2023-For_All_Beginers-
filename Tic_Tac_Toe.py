# Initialize the Tic-Tac-Toe board
board = [[' ' for _ in range(3)] for _ in range(3)]

# Function to print the current state of the board
def print_board(board):
    for row in board:
        print('|'.join(row))
        print('-' * 5)

# Function to check if a player has won
def check_win(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

# Function to check if the board is full (a draw)
def check_draw(board):
    return all(cell != ' ' for row in board for cell in row)

# Main game loop
current_player = 'X'
while True:
    print_board(board)
    row, col = map(int, input(f"Player {current_player}, enter row and column (0-2) separated by space: ").split())

    # Check if the chosen cell is valid
    if 0 <= row < 3 and 0 <= col < 3 and board[row][col] == ' ':
        board[row][col] = current_player
        if check_win(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            break
        elif check_draw(board):
            print_board(board)
            print("It's a draw!")
            break
        else:
            current_player = 'O' if current_player == 'X' else 'X'
    else:
        print("Invalid move. Try again.")
