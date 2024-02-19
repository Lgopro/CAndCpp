/*
Rev: Bar Shadkhin
Dev: Leonid Golovko
status: finished
date:11/04/23
*/


#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*memset*/
#include <assert.h> /*assert*/

#include "Grades.h"

int CreateStudent(student_t *student, char* name, char * last_name, float sports, unsigned int phys_score,unsigned int math_score, unsigned int comp_score, unsigned int liter_score, unsigned int phychol_score, unsigned int hist_score, unsigned int polit_score, unsigned int law_score);
int Print(student_t *student);
int check();

int main()
{	
	check();
	return 0;
}


int check()
{
	FILE * work = NULL;
	char name[20] = "Harry";
	char family_name[20] = "Potter";
	float sports = 20;
	unsigned int physics = 50;
	unsigned int mathematics = 75;
	unsigned int computer_science = 0;
	unsigned int literature = 50;
	unsigned int psychology = 30;
	unsigned int history = 90;
	unsigned int politics = 0;
	unsigned int law = 100;
	
	char name1[20] = "Super";
	char family_name1[20] = "Man";
	float sports1 = 100;
	unsigned int physics1 = 100;
	unsigned int mathematics1 = 0;
	unsigned int computer_science1 = 0;
	unsigned int literature1 = 50;
	unsigned int psychology1 = 80;
	unsigned int history1 = 90;
	unsigned int politics1 = 85;
	unsigned int law1 = 0;
	
	student_t harry, superman , from_file;
	memset(&harry, 0, sizeof(harry));
	memset(&superman, 0, sizeof(superman));
	memset(&from_file, 0, sizeof(from_file));
	CreateStudent(&harry,name, family_name, sports, physics, mathematics , computer_science, literature, psychology, history, politics, law);
	CreateStudent(&superman,name1 , family_name1, sports1, physics1, mathematics1 , computer_science1, literature1, psychology1, history1, politics1, law1);
	work = fopen("student.bin", "ab");
	if(NULL == work)
	{
		return 0;
	}
	AddToFile(&harry, work);
	work = fopen("student.bin", "ab");
	if(NULL == work)
	{
		return 0;
	}
	AddToFile(&superman, work);
	work = fopen("student.bin", "rb");
	if(NULL == work)
	{
		return 0;
	}
	LoadFromFile(&from_file, work, 1);
	Print(&from_file);
	work = fopen("student.bin", "rb");
	if(NULL == work)
	{
		return 0;
	}
	LoadFromFile(&from_file, work, 2);
	Print(&from_file);
	return 1;

}

int Print(student_t *student)
{
	assert(NULL != student);
	printf("The name is: %s\n", student->name);
	printf("The family name is: %s\n", student->family_name);
	printf("The sports score is: %f\n", student->sports);
	printf("The literature score is: %d\n", student->human_grade.literature);
	printf("The psychology score is: %d\n", student->human_grade.psychology);
	printf("The history score is: %d\n", student->human_grade.history);
	printf("The politics score is: %d\n", student->human_grade.politics);
	printf("The physics score is: %d\n", student->exact_grade.physics);
	printf("The mathematics score is: %d\n", student->exact_grade.mathematics);
	printf("The computer science score is: %d\n\n", student->exact_grade.computer_science);
	return 1;

}
int CreateStudent(student_t *student, char* name, char * last_name, float sports, unsigned int phys_score,unsigned int math_score, unsigned int comp_score, unsigned int liter_score, unsigned int phychol_score, unsigned int hist_score, unsigned int polit_score, unsigned int law_score)
{
	assert(NULL != student || NULL != name || NULL != last_name);
	strcpy(student->name, name);
	strcpy(student->family_name, last_name);
	student->sports = sports;
	student->human_grade.literature = liter_score;
	student->human_grade.psychology = phychol_score;
	student->human_grade.history = hist_score;
	student->human_grade.politics = polit_score;
	student->human_grade.law = law_score;
	student->exact_grade.physics = phys_score;
	student->exact_grade.mathematics = math_score;
	student->exact_grade.computer_science = comp_score;
	return 1;
}

