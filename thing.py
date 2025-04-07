def solve_n_queens(n):
    def is_safe(board, row, col):
        # Check this column on the upper side
        for i in range(row):
            if board[i][col] == 1:
                return False

        # Check upper diagonal on the left side
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        # Check upper diagonal on the right side
        for i, j in zip(range(row, -1, -1), range(col, n)):
            if board[i][j] == 1:
                return False

        return True

    def solve(board, row):
        if row >= n:
            solutions.append(["".join("Q" if cell == 1 else "." for cell in row) for row in board])
            return

        for col in range(n):
            if is_safe(board, row, col):
                board[row][col] = 1
                solve(board, row + 1)
                board[row][col] = 0

    solutions = []
    board = [[0 for _ in range(n)] for _ in range(n)]
    solve(board, 0)
    return solutions

# Example usage
if __name__ == "__main__":
    solutions = solve_n_queens(8)
    print(f"Number of solutions: {len(solutions)}")
    for solution in solutions[:3]:  # Print the first 3 solutions
        for row in solution:
            print(row)
        print()


