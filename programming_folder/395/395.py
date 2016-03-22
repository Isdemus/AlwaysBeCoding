# Problem 395
# Ivens Portugal

# Global Variables

BOARD_SIZE  = 8
PIECE_O     = 'O'
PIECE_X     = 'X'
PIECE_EMPTY = '.'
NO_MOVES    = "No moves are possible"
TO_LETTER   = 64

board = []

def main():

	# Input

	finished_board = False

	while True:

		# resets variables
		num_pieces_horizontal      = [0] * BOARD_SIZE
		num_pieces_vertical        = [0] * BOARD_SIZE
		num_pieces_diagonal_fslash = [0] * (2*BOARD_SIZE - 1)
		num_pieces_diagonal_bslash = [0] * (2*BOARD_SIZE - 1)

		global board
		board = []


		for i in range(0, BOARD_SIZE):
			try:
				row = raw_input()
			except EOFError:
				return

			# print a blank like between outpus
			if finished_board:
				finished_board = False
				print" "

			for j, pos in enumerate(row):
				if pos == PIECE_O or pos == PIECE_X:
					num_pieces_horizontal[i] += 1
					num_pieces_vertical[j]   += 1
					num_pieces_diagonal_bslash[BOARD_SIZE-i+j] += 1
					num_pieces_diagonal_fslash[i+j] += 1

			board.append(row)

		piece = raw_input()
		piece = piece[0]


		# Processing

		has_moves = False
		output = []

		for i in range(0, BOARD_SIZE):
			for j in range(0, BOARD_SIZE):

				if board[i][j] != piece:
					continue

				initial_pos = get_pos(i, j)

				# horizontal
				pos_left = j - num_pieces_horizontal[i]
				if can_move_left(i, j, pos_left, piece):
					output.append(initial_pos + "-" + get_pos(i, pos_left))
					has_moves = True

				pos_right = j + num_pieces_horizontal[i]
				if can_move_right(i, j, pos_right, piece):
					output.append(initial_pos + "-" + get_pos(i, pos_right))
					has_moves = True


				# vertical
				pos_up = i - num_pieces_vertical[j]
				if can_move_up(i, j, pos_up, piece):
					output.append(initial_pos + "-" + get_pos(pos_up, j))
					has_moves = True

				pos_down = i + num_pieces_vertical[j]
				if can_move_down(i, j, pos_down, piece):
					output.append(initial_pos + "-" + get_pos(pos_down, j))
					has_moves = True


				# diagonal backward slash
				pos_up_diag_bslash_i = i - num_pieces_diagonal_bslash[BOARD_SIZE-i+j]
				pos_up_diag_bslash_j = j - num_pieces_diagonal_bslash[BOARD_SIZE-i+j]
				if can_move_up_diag_bslash(i, j, pos_up_diag_bslash_i, pos_up_diag_bslash_j, num_pieces_diagonal_bslash[BOARD_SIZE-i+j], piece):
					output.append(initial_pos + "-" + get_pos(pos_up_diag_bslash_i, pos_up_diag_bslash_j))
					has_moves = True

				pos_down_diag_bslash_i = i + num_pieces_diagonal_bslash[BOARD_SIZE-i+j]
				pos_down_diag_bslash_j = j + num_pieces_diagonal_bslash[BOARD_SIZE-i+j]
				if can_move_down_diag_bslash(i, j, pos_down_diag_bslash_i, pos_down_diag_bslash_j, num_pieces_diagonal_bslash[BOARD_SIZE-i+j], piece):
					output.append(initial_pos + "-" + get_pos(pos_down_diag_bslash_i, pos_down_diag_bslash_j))
					has_moves = True


				# diagonal forward slash
				pos_up_diag_fslash_i = i - num_pieces_diagonal_fslash[i+j]
				pos_up_diag_fslash_j = j + num_pieces_diagonal_fslash[i+j]
				if can_move_up_diag_fslash(i, j, pos_up_diag_fslash_i, pos_up_diag_fslash_j, num_pieces_diagonal_fslash[i+j], piece):
					output.append(initial_pos + "-" + get_pos(pos_up_diag_fslash_i, pos_up_diag_fslash_j))
					has_moves = True

				pos_down_diag_fslash_i = i + num_pieces_diagonal_fslash[i+j]
				pos_down_diag_fslash_j = j - num_pieces_diagonal_fslash[i+j]
				if can_move_down_diag_fslash(i, j, pos_down_diag_fslash_i, pos_down_diag_fslash_j, num_pieces_diagonal_fslash[i+j], piece):
					output.append(initial_pos + "-" + get_pos(pos_down_diag_fslash_i, pos_down_diag_fslash_j))
					has_moves = True

		if has_moves:
			for out in sorted(output):
				print out
		else:
			print NO_MOVES

		finished_board = True



def can_move_left(i, j, pos_left, piece):

	if pos_left >= 0:
		if board[i][pos_left] != piece:
			for k in reversed(range(pos_left+1, j)):
				if board[i][k] != piece and board[i][k] != PIECE_EMPTY:
					return False
			return True
	return False

def can_move_right(i, j, pos_right, piece):

	if pos_right < BOARD_SIZE:
		if board[i][pos_right] != piece:
			for k in range(j+1, pos_right):
				if board[i][k] != piece and board[i][k] != PIECE_EMPTY:
					return False
			return True
	return False


def can_move_up(i, j, pos_up, piece):

	if pos_up >= 0:
		if board[pos_up][j] != piece:
			for k in reversed(range(pos_up+1, i)):
				if board[k][j] != piece and board[k][j] != PIECE_EMPTY:
					return False
			return True
	return False

def can_move_down(i, j, pos_down, piece):

	if pos_down < BOARD_SIZE:
		if board[pos_down][j] != piece:
			for k in range(i+1, pos_down):
				if board[k][j] != piece and board[k][j] != PIECE_EMPTY:
					return False
			return True
	return False


def can_move_up_diag_bslash(i, j, pos_up_diag_bslash_i, pos_up_diag_bslash_j, moves, piece):

	if pos_up_diag_bslash_i >= 0 and pos_up_diag_bslash_j >= 0:
		if board[pos_up_diag_bslash_i][pos_up_diag_bslash_j] != piece:
			for k in range(1, moves):
				if board[i-k][j-k] != piece and board[i-k][j-k] != PIECE_EMPTY:
					return False
			return True
	return False

def can_move_down_diag_bslash(i, j, pos_down_diag_bslash_i, pos_down_diag_bslash_j, moves, piece):

	if pos_down_diag_bslash_i < BOARD_SIZE and pos_down_diag_bslash_j < BOARD_SIZE:
		if board[pos_down_diag_bslash_i][pos_down_diag_bslash_j] != piece:
			for k in range(1, moves):
				if board[i+k][j+k] != piece and board[i+k][j+k] != PIECE_EMPTY:
					return False
			return True
	return False

def can_move_up_diag_fslash(i, j, pos_up_diag_fslash_i, pos_up_diag_fslash_j, moves, piece):

	if pos_up_diag_fslash_i >= 0 and pos_up_diag_fslash_j < BOARD_SIZE:
		if board[pos_up_diag_fslash_i][pos_up_diag_fslash_j] != piece:
			for k in range(1, moves):
				if board[i-k][j+k] != piece and board[i-k][j+k] != PIECE_EMPTY:
					return False
			return True
	return False

def can_move_down_diag_fslash(i, j, pos_down_diag_fslash_i, pos_down_diag_fslash_j, moves, piece):

	if pos_down_diag_fslash_i < BOARD_SIZE and pos_down_diag_fslash_j >= 0:
		if board[pos_down_diag_fslash_i][pos_down_diag_fslash_j] != piece:
			for k in range(1, moves):
				if board[i+k][j-k] != piece and board[i+k][j-k] != PIECE_EMPTY:
					return False
			return True
	return False


def get_pos(i, j):
	return chr(i+1+TO_LETTER) + str(j+1)


if __name__ == '__main__':
	main()