#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct
{
	int x;
	int y;
	int second;
} coor;

int n;
int ans = 0;
int shark = 2; //상어의 크기
int grow_cnt = 0; //먹은 물고기 카운트
int pos[2]; //상어의 위치 기록
int fish[7]; //물고기 크기별 마리수
int map[MAX][MAX];
int x_arr[4] = {-1, 1, 0, 0};
int y_arr[4] = {0, 0, -1, 1};
int visited[MAX][MAX];
int front = 0, rear = 0;
coor cur, next, feed;
coor queue[MAX * MAX];

void bfs()
{
	cur.x = pos[0];
	cur.y = pos[1];
	cur.second = 0;
	queue[rear++] = cur;

	feed.second = -1;

	while(front < rear)
	{
		cur = queue[front++];

		for(int i = 0; i < 4; i++)
		{
			next.x = cur.x + x_arr[i];
			next.y = cur.y + y_arr[i];
			next.second = cur.second + 1;

			if(next.x < 0 || next.y < 0 || next.x >= n || next.y >= n)
				continue;

			//방문한 적 없고 지나갈 수 있는 곳이면
			if((!map[next.x][next.y] || map[next.x][next.y] == shark) && !visited[next.x][next.y])
			{
				visited[next.x][next.y]++;
				queue[rear++] = next;
			}

			//먹을 수 있는 물고기를 발견하면
			if((map[next.x][next.y] != 0 && map[next.x][next.y] < shark))
			{
				//처음 발견한 먹이거나 새로 발견한 먹이가 더 가까우면
				if(feed.second == -1)
					feed = next;

				//거리가 같으면
				else if(feed.second == next.second)
				{
					//더 위에 있는 먹이 저장
					if(feed.x > next.x)
						feed = next;

					//같은 높이라면 제일 왼쪽 먹이 저장
					else if(feed.x == next.x && feed.y > next.y)
						feed = next;
				}

				visited[next.x][next.y]++;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);

			if(map[i][j] == 9)
			{
				pos[0] = i;
				pos[1] = j;
				map[i][j] = 0;
			}
			
			else if(map[i][j])
				fish[map[i][j]]++;
		}

	for(int i = 1; i <= 6; i++)
	{
		if(shark == i)
			break;

		//상어보다 작은 크기의 물고기가 남아있는동안 반복
		while(fish[i])
		{
			front = rear = 0;
			for(int i = 0; i < MAX; i++)
				memset(visited[i], 0, sizeof(int) * MAX);

			bfs();

			//먹을 수 있는 물고기는 있는데 길이 막혔을 때
			if(feed.second == -1)
				break;
			
			/*
			가장 가까운 물고기를 먹었으면,
			걸린 시간만큼 ans에 증가.
			먹은 물고기 크기에 해당하는 fish 인덱스 값 감소.
			상어의 위치 재설정.
			먹은 물고기 수 증가.
			*/
			ans += feed.second;
			fish[map[feed.x][feed.y]]--;
			map[feed.x][feed.y] = 0;
			pos[0] = feed.x;
			pos[1] = feed.y;
			grow_cnt++;

			//물고기를 현재 상어 크기만큼 먹으면 상어 크기 +1
			if(grow_cnt == shark)
			{
				shark++;
				grow_cnt = 0;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}