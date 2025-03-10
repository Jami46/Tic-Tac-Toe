#include <stdio.h>

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char currentPlayer = 'X';

void printBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1; // Horizontal
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1; // Vertical
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1; // Diagonal
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1; // Diagonal
    return 0;
}

int main() {
    int row, col, moves = 0;
    while(1) {
        printBoard();
        printf("Player %c, enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        if(checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        
        if(moves == 9) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
    }
    return 0;
}
