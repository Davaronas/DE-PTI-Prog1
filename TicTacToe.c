#include <stdio.h>

#define BOARD_SIZE 8 // Must be betweeen 3 and 8 for playable experience. Must be higher than(or equal to) SCORE.
#define SCORE 5 // The amount of X or O needed to win the game. Must be between 3 and 5. Cannot be higher than BOARD_SIZE.

// TODO Look for bugs (especially cross win shenanigans)

int index[BOARD_SIZE*BOARD_SIZE];

int drawBoard(int boardArray[BOARD_SIZE * BOARD_SIZE])
{
	int j = 1;
	printf("\n\n\n");


	for (; j <= BOARD_SIZE * BOARD_SIZE; j++)
	{
		if (boardArray[j - 1] != 88 && boardArray[j - 1] != 79)
		{
			boardArray[j - 1] = j;
			printf("%10d", boardArray[j - 1]);
		}
		else if (boardArray[j - 1] == 88)
		{
			printf("%10c", 'X');
		}
		else if (boardArray[j - 1] == 79)
		{
			printf("%10c", 'O');
		}

		if (j % BOARD_SIZE == 0)
		{
			printf("\n\n");
		}
	}
	for (int i = 0; i <= BOARD_SIZE * BOARD_SIZE; i++)
	{
		index[i] = i;
	}
	return boardArray;
}

_Bool checkForDraw(int boardArray[])
{
	int board_size = 0;
	for (int i = 0; i <= BOARD_SIZE * BOARD_SIZE; i++)
	{
		if (boardArray[i] == 88 || boardArray[i] == 79)
		{
			board_size++;
		}
	}
	if (board_size > (BOARD_SIZE * BOARD_SIZE) - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{

	enum players { Player1, Player2 };
	enum players currentPlayer = Player1;
	int board[BOARD_SIZE * BOARD_SIZE];
	int player1Base;
	int player2Base;
	int p1_Left_Right = 0;
	int p2_Left_Right = 0;
	int p1_Up_Down = 0;
	int p2_Up_Down = 0;
	int p1_Up_L_Down_R = 0;
	int p2_Up_L_Down_R = 0;
	int p1_Up_R_Down_L = 0;
	int p2_Up_R_Down_L = 0;

	while (1) //--------------------------------------GAME STARTS-------------------------------------------
	{
		printf("\n\t\t\t    Tic Tac Toe\n\n\tPlayer 1 (X) \t\t\t\tPlayer 2 (O)");
		drawBoard(board);
		int number = 0;
		switch (currentPlayer)
		{
		case Player1:
			printf("Player 1\n");
			break;
		case Player2:
			printf("Player 2\n");
			break;
		}

		p1_Left_Right = 0;
		p2_Left_Right = 0;
		p1_Up_Down = 0;
		p2_Up_Down = 0;
		p1_Up_L_Down_R = 0;
		p2_Up_L_Down_R = 0;
		p1_Up_R_Down_L = 0;
		p2_Up_R_Down_L = 0;

		printf("Give the number of the spot you want to capture!\n");
		scanf("%d", &number);
		if (number < 1 || number >(BOARD_SIZE * BOARD_SIZE) || number == NULL)// --------------------------------CHECK IF IN LIMITS-------------------------------
		{
			printf("Invalid number!\n");
			continue;
		}
		else if (board[number - 1] == 88 /* X */ || board[number - 1] == 79 /* O */) // ----------------------------CHECK IF SPOT IS ALREADY TAKEN -----------------------------
		{
			printf("That spot is already taken!\n");
			continue;
		}
		else if (currentPlayer == Player1) // -------------------------------------PLAYER 1 TURN--------------------------------------------
		{
			player1Base = number - 1;
			board[player1Base] = 88;
			// printf("PLAYER 1 BASE: %d\n", player1Base);

			// ---------------------------------------------------------------------RIGHT SIDE CHECK----------------------------------------------------------------------
			if (index[player1Base + 1] % BOARD_SIZE != 0) // If it is equal then it's the last in a line
			{
				//printf("RIGHT: %d\n", board[player1Base + 1]);
				if (board[player1Base + 1] == 88) // if it is an X to the right
				{
					p1_Left_Right++; // + one neighbour
					// printf("LEFT-RIGHT %d\n", p1_Left_Right);


					if (board[player1Base + 2])
					{
						if (index[player1Base + 2] % BOARD_SIZE != 0 && board[player1Base + 2] == 88)
						{
							p1_Left_Right++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (right)\n");
								break;
							}
							if (index[player1Base + 3] % BOARD_SIZE != 0 && board[player1Base + 3] == 88)
							{
								p1_Left_Right++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (right)\n");
									break;
								}
								if (index[player1Base + 4] % BOARD_SIZE != 0 && board[player1Base + 4] == 88)
								{
									drawBoard(board);
									printf("Player 1 won (right)\n");
									break;
								}
							}
						}
					}
				}
				if (p1_Left_Right == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------LEFT SIDE CHECK--------------------------------------------------------------------- 
			if ((index[player1Base - 1] + 1) % BOARD_SIZE != 0)
			{
				//printf("LEFT: %d\n", board[player1Base - 1]);
				if (board[player1Base - 1] == 88)
				{
					p1_Left_Right++;
					//printf("LEFT-RIGHT: %d\n", p1_Left_Right);

					if (board[player1Base - 2])
					{
						if ((index[player1Base - 2] + 1) % BOARD_SIZE != 0 && board[player1Base - 2] == 88)
						{
							p1_Left_Right++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (left)\n");
								break;
							}
							if ((index[player1Base - 3] + 1) % BOARD_SIZE != 0 && board[player1Base - 3] == 88)
							{
								p1_Left_Right++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (left)\n");
									break;
								}
								if ((index[player1Base - 4] + 1) % BOARD_SIZE != 0 && board[player1Base - 4] == 88)
								{
									drawBoard(board);
									printf("Player 1 won (left)\n");
									break;
								}
							}
						}
					}
				}
				if (p1_Left_Right == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}
			}

			//----------------------------------------------------------------------UP RIGHT CHECK----------------------------------------------------------------------
			if (index[player1Base + 1] % BOARD_SIZE != 0 && index[player1Base] > BOARD_SIZE)
			{
				//printf("UP RIGHT: %d\n", board[player1Base - BOARD_SIZE + 1]);
				if (board[player1Base - BOARD_SIZE + 1] == 88)
				{
					p1_Up_R_Down_L++;
					//printf("UP-RIGHT-DOWN-LEFT %d\n",p1_Up_R_Down_L);


					if (board[player1Base - (2 * BOARD_SIZE) + 2])
					{
						if (index[player1Base - (2 * BOARD_SIZE) + 2] % BOARD_SIZE != 0 && board[player1Base - (2 * BOARD_SIZE) + 2] == 88)
						{
							p1_Up_R_Down_L++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (up right)\n");
								break;
							}
							if (index[player1Base - (3 * BOARD_SIZE) + 3] % BOARD_SIZE != 0 && board[player1Base - (3 * BOARD_SIZE) + 3] == 88)
							{
								p1_Up_R_Down_L++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (up right)\n");
									break;
								}
								if (index[player1Base - (4 * BOARD_SIZE) + 4] % BOARD_SIZE != 0 && board[player1Base - (4 * BOARD_SIZE) + 4] == 88)
								{
									drawBoard(board);
									printf("Player 1 won(up right)\n");
									break;
								}
							}
						}
					}
				}
				if (p1_Up_R_Down_L == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------UP LEFT CHECK----------------------------------------------------------------------
			if ((index[player1Base - 1] + 1) % BOARD_SIZE != 0 && index[player1Base - 1] >= BOARD_SIZE)
			{
				// printf("NOT IN THE FIRST COLUMN AND NOT IN THE FIRST LINE\n");
				//printf("UP LEFT: %d\n", board[player1Base - BOARD_SIZE] - 1);
				if (board[player1Base - BOARD_SIZE - 1] == 88)
				{

					p1_Up_L_Down_R++;
					//printf("UP-LEFT-DOWN-RIGHT %d\n", p1_Up_L_Down_R);


					if (board[player1Base - (2 * BOARD_SIZE) - 2])
					{
						// printf("2. %d NOT IN THE LAST COLUMN %d AND IS AN X\n", index[player1Base - (2 * BOARD_SIZE) - 2] % BOARD_SIZE != 0, board[player1Base - (2 * BOARD_SIZE) - 2] == 88);
						if ((index[player1Base - (2 * BOARD_SIZE) - 2] % BOARD_SIZE != 0) && board[player1Base - (2 * BOARD_SIZE) - 2] == 88)
						{

							p1_Up_L_Down_R++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (up left)\n");
								break;
							}
							// printf("3. %d NOT IN THE LAST COLUMN %d AND IS AN X\n", index[player1Base - (3 * BOARD_SIZE) - 3] % BOARD_SIZE != 0, board[player1Base - (3 * BOARD_SIZE) - 3] == 88);
							if ((index[player1Base - (3 * BOARD_SIZE) - 3] % BOARD_SIZE != 0) && board[player1Base - (3 * BOARD_SIZE) - 3] == 88)
							{

								p1_Up_L_Down_R++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (up left)\n");
									break;
								}
								// printf("4. %d NOT IN THE LAST COLUMN %d AND IS AN X\n", index[player1Base - (4 * BOARD_SIZE) - 4] % BOARD_SIZE != 0, board[player1Base - (4 * BOARD_SIZE) - 4] == 88);
								if ((index[player1Base - (4 * BOARD_SIZE) - 4] % BOARD_SIZE != 0) || index[player1Base - (4 * BOARD_SIZE) - 4] < BOARD_SIZE)
								{
									if (board[player1Base - (4 * BOARD_SIZE) - 4] == 88)
									{
										drawBoard(board);
										printf("Player 1 won (up left)\n");
										break;


									}
								}
							}
						}
					}
				}
				if (p1_Up_L_Down_R == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------UP SIDE CHECK----------------------------------------------------------------------
			if (index[player1Base] > BOARD_SIZE)
			{
				//printf("UP: %d\n", board[player1Base - BOARD_SIZE]);
				if (board[player1Base - BOARD_SIZE] == 88)
				{
					p1_Up_Down++;
					//printf("UP-DOWN: %d\n", p1_Up_Down);


					if (board[player1Base - (2 * BOARD_SIZE)])
					{
						if (board[player1Base - (2 * BOARD_SIZE)] == 88)
						{
							p1_Up_Down++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (up)\n");
								break;
							}
							if (board[player1Base - (3 * BOARD_SIZE)] == 88)
							{
								p1_Up_Down++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (up)\n");
									break;
								}
								if (board[player1Base - (4 * BOARD_SIZE)] == 88)
								{
									drawBoard(board);
									printf("Player won (up)\n");
									break;
								}
							}
						}
					}
				}
				if (p1_Up_Down == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------DOWN RIGHT----------------------------------------------------------------------
			if ((index[player1Base] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE) && index[player1Base + 1] % BOARD_SIZE != 0)
			{
				//printf("DOWN RIGHT: %d\n", board[player1Base + BOARD_SIZE + 1]);
				if (board[player1Base + BOARD_SIZE + 1] == 88)
				{
					p1_Up_L_Down_R++;
					//printf("UP-LEFT-DOWN-RIGHT: %d\n", p1_Up_L_Down_R);


					if (board[player1Base + (2 * BOARD_SIZE) + 2])
					{
						if (board[player1Base + (2 * BOARD_SIZE) + 2] == 88 && index[player1Base + (2 * BOARD_SIZE) + 2] % BOARD_SIZE != 0)
						{
							p1_Up_L_Down_R++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (Down right)\n");
								break;
							}
							if (board[player1Base + (3 * BOARD_SIZE) + 3] == 88 && index[player1Base + (3 * BOARD_SIZE) + 3] % BOARD_SIZE != 0)
							{
								p1_Up_L_Down_R++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (Down right)\n");
									break;
								}
								if (board[player1Base + (4 * BOARD_SIZE) + 4] == 88 && index[player1Base + (4 * BOARD_SIZE) + 4] % BOARD_SIZE != 0)
								{
									drawBoard(board);
									printf("Player 1 won (Down right)\n");
									break;
								}
							}
						}
					}
				}
				if (p1_Up_L_Down_R == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------DOWN LEFT----------------------------------------------------------------------
			if ((index[player1Base] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE) && (index[player1Base - 1] + 1) % BOARD_SIZE != 0)
			{
				if (board[player1Base + BOARD_SIZE - 1] == 88 && (index[player1Base + BOARD_SIZE - 1] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE))
				{
					p1_Up_R_Down_L++;
					if (board[player1Base + (2 * BOARD_SIZE) - 2])
					{
						if ((index[player1Base + (2 * BOARD_SIZE) - 2] + 1) % BOARD_SIZE != 0 && board[player1Base + (2 * BOARD_SIZE) - 2] == 88 && index[player1Base] > index[1])
						{
							p1_Up_R_Down_L++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (Down left)\n");
								break;
							}
							if ((index[player1Base + (3 * BOARD_SIZE) - 3] + 1) % BOARD_SIZE != 0 && board[player1Base + (3 * BOARD_SIZE) - 3] == 88 && index[player1Base] > index[1])
							{
								p1_Up_R_Down_L++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (Down left)\n");
									break;
								}
								if ((index[player1Base + (4 * BOARD_SIZE) - 4] + 1) % BOARD_SIZE != 0 && board[player1Base + (4 * BOARD_SIZE) - 4] == 88 && index[player1Base] > index[1])
								{
									drawBoard(board);
									printf("Player 1 won (Down left)\n");
									break;
								}
							}
						}
					}
				}
				if (p1_Up_R_Down_L == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}
			}

			//----------------------------------------------------------------------DOWN CHECK----------------------------------------------------------------------
			if (index[player1Base] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE)
			{
				//printf("DOWN: %d\n", board[player1Base + BOARD_SIZE]);
				if (board[player1Base + BOARD_SIZE] == 88)
				{
					p1_Up_Down++;
					//printf("UP-DOWN: %d\n", p1_Up_Down);

					if (board[player1Base + (2 * BOARD_SIZE)])
					{
						if (board[player1Base + (2 * BOARD_SIZE)] == 88)
						{
							p1_Up_Down++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 1 won (Down)\n");
								break;
							}
							if (board[player1Base + (3 * BOARD_SIZE)] == 88)
							{
								p1_Up_Down++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 1 won (Down)\n");
									break;
								}
								if (board[player1Base + (4 * BOARD_SIZE)] == 88)
								{
									drawBoard(board);
									printf("Player 1 won (Down)\n");
									break;
								}
							}
						}
					}
				}
				if (p1_Up_Down == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 1 won (middle)\n");
					break;
				}

			}

			currentPlayer = Player2;
			if (checkForDraw(board) == 1)
			{
				drawBoard(board);
				printf("Draw! Out of field.\n");
				break;
			}
		}

		else if (currentPlayer == Player2)// -------------------------------------PLAYER 2 TURN-----------------------------------------------
		{
			player2Base = number - 1;
			board[player2Base] = 79;
			// printf("PLAYER 1 BASE: %d\n", player1Base);

			// ---------------------------------------------------------------------RIGHT SIDE CHECK----------------------------------------------------------------------|
			if (index[player2Base + 1] % BOARD_SIZE != 0) // If it is equal then it's the last in a line
			{
				//printf("RIGHT: %d\n", board[player1Base + 1]);
				if (board[player2Base + 1] == 79) // if it is an X to the right
				{
					p2_Left_Right++; // + one neighbour
					// printf("LEFT-RIGHT %d\n", p1_Left_Right);


					if (board[player2Base + 2])
					{
						if (index[player2Base + 2] % BOARD_SIZE != 0 && board[player2Base + 2] == 79)
						{
							p2_Left_Right++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (right)\n");
								break;
							}
							if (index[player2Base + 3] % BOARD_SIZE != 0 && board[player2Base + 3] == 79)
							{
								p2_Left_Right++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (Down right)\n");
									break;
								}
								if (index[player2Base + 4] % BOARD_SIZE != 0 && board[player2Base + 4] == 79)
								{
									drawBoard(board);
									printf("Player 2 won (right)\n");
									break;
								}
							}
						}
					}
				}
				if (p2_Left_Right == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------LEFT SIDE CHECK---------------------------------------------------------------------|
			if ((index[player2Base - 1] + 1) % BOARD_SIZE != 0)
			{
				//printf("LEFT: %d\n", board[player1Base - 1]);
				if (board[player2Base - 1] == 79)
				{
					p2_Left_Right++;
					//printf("LEFT-RIGHT: %d\n", p1_Left_Right);

					if (board[player2Base - 2])
					{
						if ((index[player2Base - 2] + 1) % BOARD_SIZE != 0 && board[player2Base - 2] == 79)
						{
							p2_Left_Right++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (left)\n");
								break;
							}
							if ((index[player2Base - 3] + 1) % BOARD_SIZE != 0 && board[player2Base - 3] == 79)
							{
								p2_Left_Right++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (left)\n");
									break;
								}
								if ((index[player2Base - 4] + 1) % BOARD_SIZE != 0 && board[player2Base - 4] == 79)
								{
									drawBoard(board);
									printf("Player 2 won (left)\n");
									break;
								}
							}
						}
					}
				}
				if (p2_Left_Right == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}
			}

			//----------------------------------------------------------------------UP RIGHT CHECK----------------------------------------------------------------------|
			if (index[player2Base + 1] % BOARD_SIZE != 0 && index[player2Base] > BOARD_SIZE)
			{
				//printf("UP RIGHT: %d\n", board[player1Base - BOARD_SIZE + 1]);
				if (board[player2Base - BOARD_SIZE + 1] == 79)
				{
					p2_Up_R_Down_L++;
					//printf("UP-RIGHT-DOWN-LEFT %d\n",p1_Up_R_Down_L);


					if (board[player2Base - (2 * BOARD_SIZE) + 2])
					{
						if (index[player2Base - (2 * BOARD_SIZE) + 2] % BOARD_SIZE != 0 && board[player2Base - (2 * BOARD_SIZE) + 2] == 79)
						{
							p2_Up_R_Down_L++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (up right)\n");
								break;
							}
							if (index[player2Base - (3 * BOARD_SIZE) + 3] % BOARD_SIZE != 0 && board[player2Base - (3 * BOARD_SIZE) + 3] == 79)
							{
								p2_Up_R_Down_L++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (up right)\n");
									break;
								}
								if (index[player2Base - (4 * BOARD_SIZE) + 4] % BOARD_SIZE != 0 && board[player2Base - (4 * BOARD_SIZE) + 4] == 79)
								{
									drawBoard(board);
									printf("Player 2 won(up right)\n");
									break;
								}
							}
						}
					}
				}
				if (p2_Up_R_Down_L == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}
			}


			// ---------------------------------------------------------------------UP LEFT CHECK----------------------------------------------------------------------|
			if ((index[player2Base - 1] + 1) % BOARD_SIZE != 0 && index[player2Base - 1] >= BOARD_SIZE)
			{
				// printf("NOT IN THE FIRST COLUMN AND NOT IN THE FIRST LINE\n");
				//printf("UP LEFT: %d\n", board[player1Base - BOARD_SIZE] - 1);
				if (board[player2Base - BOARD_SIZE - 1] == 79)
				{
					p2_Up_L_Down_R++;
					//printf("UP-LEFT-DOWN-RIGHT %d\n", p1_Up_L_Down_R);
					if (board[player2Base - (2 * BOARD_SIZE) - 2])
					{
						if ((index[player2Base - (2 * BOARD_SIZE) - 2] % BOARD_SIZE != 0) && board[player2Base - (2 * BOARD_SIZE) - 2] == 79)
						{
							p2_Up_L_Down_R++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (up left)\n");
								break;
							}
							if ((index[player2Base - (3 * BOARD_SIZE) - 3] % BOARD_SIZE != 0) && board[player2Base - (3 * BOARD_SIZE) - 3] == 79)
							{
								p2_Up_L_Down_R++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (up left)\n");
									break;
								}
								if ((index[player2Base - (4 * BOARD_SIZE) - 4] % BOARD_SIZE != 0) || (index[player2Base - (4 * BOARD_SIZE) - 4] < BOARD_SIZE))
								{
									if (board[player2Base - (4 * BOARD_SIZE) - 4] == 79)
									{
										drawBoard(board);
										printf("Player 2 won (up left)\n");
										break;
									}
								}
							}
						}
					}
				}
				if (p2_Up_L_Down_R == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------UP SIDE CHECK----------------------------------------------------------------------|
			if (index[player2Base] > BOARD_SIZE)
			{
				//printf("UP: %d\n", board[player1Base - BOARD_SIZE]);
				if (board[player2Base - BOARD_SIZE] == 79)
				{
					p2_Up_Down++;
					//printf("UP-DOWN: %d\n", p1_Up_Down);


					if (board[player2Base - (2 * BOARD_SIZE)])
					{
						if (board[player2Base - (2 * BOARD_SIZE)] == 79)
						{
							p2_Up_Down++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (up)\n");
								break;
							}
							if (board[player2Base - (3 * BOARD_SIZE)] == 79)
							{
								p2_Up_Down++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (up)\n");
									break;
								}
								if (board[player2Base - (4 * BOARD_SIZE)] == 79)
								{
									drawBoard(board);
									printf("Player 2 won (up)\n");
									break;
								}
							}
						}
					}
				}
				if (p2_Up_Down == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------DOWN RIGHT----------------------------------------------------------------------|
			if ((index[player2Base] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE) && index[player2Base + 1] % BOARD_SIZE != 0)
			{
				//printf("DOWN RIGHT: %d\n", board[player1Base + BOARD_SIZE + 1]);
				if (board[player2Base + BOARD_SIZE + 1] == 79)
				{
					p2_Up_L_Down_R++;
					//printf("UP-LEFT-DOWN-RIGHT: %d\n", p1_Up_L_Down_R);


					if (board[player2Base + (2 * BOARD_SIZE) + 2])
					{
						if (board[player2Base + (2 * BOARD_SIZE) + 2] == 79 && index[player2Base + (2 * BOARD_SIZE) + 2] % BOARD_SIZE != 0)
						{
							p2_Up_L_Down_R++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (Down right)\n");
								break;
							}
							if (board[player2Base + (3 * BOARD_SIZE) + 3] == 79 && index[player2Base + (3 * BOARD_SIZE) + 3] % BOARD_SIZE != 0)
							{
								p2_Up_L_Down_R++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (Down right)\n");
									break;
								}
								if (board[player2Base + (4 * BOARD_SIZE) + 4] == 88 && index[player2Base + (4 * BOARD_SIZE) + 4] % BOARD_SIZE != 0)
								{
									drawBoard(board);
									printf("Player 2 won (Down right)\n");
									break;
								}
							}
						}
					}
				}
				if (p2_Up_L_Down_R == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}
			}

			// ---------------------------------------------------------------------DOWN LEFT----------------------------------------------------------------------|
			if ((index[player2Base] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE) && (index[player2Base - 1] + 1) % BOARD_SIZE != 0)
			{
				if (board[player2Base + BOARD_SIZE - 1] == 79 && (index[player2Base + BOARD_SIZE - 1] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE))
				{
					p2_Up_R_Down_L++;
					if (board[player2Base + (2 * BOARD_SIZE) - 2])
					{
						if ((index[player2Base + (2 * BOARD_SIZE) - 2] + 1) % BOARD_SIZE != 0 && board[player2Base + (2 * BOARD_SIZE) - 2] == 79 && index[player2Base] > index[1])
						{
							p2_Up_R_Down_L++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (Down)\n");
								break;
							}
							if ((index[player2Base + (3 * BOARD_SIZE) - 3] + 1) % BOARD_SIZE != 0 && board[player2Base + (3 * BOARD_SIZE) - 3] == 79 && index[player2Base] > index[1])
							{
								p2_Up_R_Down_L++;
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (Down)\n");
									break;
								}
								if ((index[player2Base + (4 * BOARD_SIZE) - 4] + 1) % BOARD_SIZE != 0 && board[player2Base + (4 * BOARD_SIZE) - 4] == 79 && index[player2Base] > index[1])
								{
									drawBoard(board);
									printf("Player 2 won (Down left)\n");
									break;
								}
							}
						}
					}
				}
				if (p2_Up_R_Down_L == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}
			}

			//----------------------------------------------------------------------DOWN CHECK----------------------------------------------------------------------
			if (index[player2Base] < (BOARD_SIZE * BOARD_SIZE) - BOARD_SIZE)
			{
				//printf("DOWN: %d\n", board[player1Base + BOARD_SIZE]);
				if (board[player2Base + BOARD_SIZE] == 79)
				{
					p2_Up_Down++;
					//printf("UP-DOWN: %d\n", p1_Up_Down);

					if (board[player2Base + (2 * BOARD_SIZE)])
					{
						if (board[player2Base + (2 * BOARD_SIZE)] == 79)
						{
							p2_Up_Down++;
							if (SCORE == 3)
							{
								drawBoard(board);
								printf("Player 2 won (Down)\n");
								break;
							}

							if (board[player2Base + (3 * BOARD_SIZE)] == 79)
							{
								if (SCORE == 4)
								{
									drawBoard(board);
									printf("Player 2 won (Down)\n");
									break;
								}
								p2_Up_Down++;
								if (board[player2Base + (4 * BOARD_SIZE)] == 79)
								{
									drawBoard(board);
									printf("Player 2 won (Down)\n");
									break;
								}
							}
						}
					}
				}
				if (p2_Up_Down == SCORE - 1)
				{
					drawBoard(board);
					printf("Player 2 won (middle)\n");
					break;
				}

			}

			currentPlayer = Player1;
			if (checkForDraw(board) == 1)
			{
				drawBoard(board);
				printf("Draw! Out of field.\n");
				break;
			}

		}
	}
}
