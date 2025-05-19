#include <stdio.h>

char board[51][51] = {0,};

int main()
{
	int H, W;
	int count = 0;
	int min = 32;

	scanf("%d %d", &H, &W);

	for(int i = 0; i < H; i++)
		scanf("%s", board[i]);

	for(int line = 0; line < H - 7; line++)
	{
		for(int space = 0; space < W - 7; space++)
		{
			char criteria = board[line][space];

			for(int i = 0; i < 8; i++)
			{
				int x = line + i;
				for(int j = 0; j < 8; j++)
				{
					int y = space + j;
					if(i % 2 == 0 && j % 2 == 0) //짝수 줄, 짝수 칸이면 같아야 함
						if(board[x][y] != criteria) count++;

					if(i % 2 == 0 && j % 2 == 1) //짝수 줄, 홀수 칸이면 달라야 함
						if(board[x][y] == criteria) count++;

					if(i % 2 == 1 && j % 2 == 0) //홀수 줄, 짝수 칸이면 달라야 함
						if(board[x][y] == criteria) count++;

					if(i % 2 == 1 && j % 2 == 1) //홀수 줄, 홀수 칸이면 같아야 함
						if(board[x][y] != criteria) count++;
				}
			}
			if(64 - count < count)
				count = 64 - count;
			if(count < min)
				min = count;
			count = 0;
		}
	}

	printf("%d", min);
	return 0;
}