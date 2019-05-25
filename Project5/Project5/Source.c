#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COURSES_COUNT 5

typedef struct Student
{
	char name[30];
	char email[12];
	int course;
	char group[7];
	int scores[MAX_COURSES_COUNT];
	int score_count;
} STUDENT, *PSTUDENT;
typedef struct SessionResult
{
	//Кількість "добре" та відмінно
	int good_pass_count;
	//Кількість "задовільно", "добре" та відмінно
	int all_pass_count;
	//Кількість "незадовільно"
	int not_pass_count;
} SESSION_RESULT, *PSESSION_RESULT;
int get_session_item(PSTUDENT);
void process_session_item(const PSTUDENT, PSESSION_RESULT);
void process_result(PSESSION_RESULT);
int main()
{
	printf("Format: <NAME> <EMAIL> <COURSE> <GROUP>\
<[Score1, ...]>\n");
	STUDENT student;
	SESSION_RESULT result = { 0, 0, 0 };
	do
	{
		if (!get_session_item(&student))
		{
				process_session_item(&student, &result);
		}
		else
		{
			break;
		}
		printf("Continue - any key, stop - \'S\': ");
		getchar();
		if (toupper(getchar()) == 'S')
		{
			break;
		}
	} while (1);
	process_result(&result);
	return 0;
}
void extract_scores(char* from, int* to, int max_sz,
	int* count)
{
	int offs = 0;
	float sum = 0.0f;
	for (*count = 0; *count < max_sz; ++(*count))
	{
		if (sscanf(from, "%d%n", &to[*count], &offs) != 1)
		{
			break;
		}
		printf("\tScore: %d\n", to[*count]);
		sum += to[*count];
		from += offs;
	}
	printf("\tTotal scores: %d\n", *count);
	printf("\tAverage score: %d\n", (int)sum / (*count));
}
int get_session_item(PSTUDENT pstud)
{
	static int count = 0;
	if (!pstud)
	{
		return -1;
	}
	printf("Enter session info: ");
		char score_line[128];
	memset(score_line, 0, sizeof(score_line));
	static char* fmt = "%s %s %d %s %[^\n]s";
	int ret = scanf(fmt, pstud->name, pstud->email,
		&(pstud->course),
		pstud->group, score_line);
	if (ret != 5)
	{
		return -1;
	}
	extract_scores(score_line, pstud->scores,
		MAX_COURSES_COUNT, &(pstud->score_count));
	++count;
	printf("Processed %d\n", count);
	return 0;
}
void process_session_item(const PSTUDENT pstud,
	PSESSION_RESULT pres)
{
	if (!pstud || !pres)
	{
		return;
	}
	int i;
	for (i = 0; i < pstud->score_count; ++i)
	{
		int score = pstud->scores[i];
		if (score < 60)
		{
			++(pres->not_pass_count);
		}
		else if (score >= 60 && score < 75)
		{
			++(pres->all_pass_count);
		}
		else
		{
			++(pres->good_pass_count);
		}
	}
}
void process_result(PSESSION_RESULT pres)
{
		if (!pres)
		{
			return;
		}
	int total = pres->all_pass_count +
		pres->good_pass_count +
		pres->not_pass_count;
	int achives = pres->all_pass_count +
		pres->good_pass_count;
	achives = (int)100.0f*achives / total;
	int quality = pres->good_pass_count;
	quality = (int)100.0f*quality / total;
	printf("Total statistic:\n");
	printf("\tAchievements: %d%%\n", achives);
	printf("\tQuality: %d%%\n", quality);
}