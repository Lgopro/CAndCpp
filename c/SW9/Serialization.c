/*
Rev: Bar Shadkhin
Dev: Leonid Golovko
status: finished
date:11/04/23
*/



#include <stdio.h> /*printf*/
#include <string.h> /*strcpy*/
#include <assert.h> /*assert*/



#include "Grades.h"

#define SIZE 72

static void AddToStudent(student_t *student, FILE *file);
static void AddToHuman(student_t *student, FILE *file);
static void AddToExact(student_t *student, FILE *file);
static void LoadFromStudent(student_t *student, FILE *file);
static void LoadFromHuman(student_t *student, FILE *file);
static void LoadFromExact(student_t *student, FILE *file);


int AddToFile(student_t *student, FILE *file)
{
	
	assert(NULL != student && NULL != file);
	
	
	AddToStudent(student, file);
	if(EOF == fclose(file))
	{
		return 0;
	}
	return 1;	
}

static void AddToStudent(student_t *student, FILE *file)
{
	fwrite(&student->name, sizeof(student->name), 1, file);
	fwrite(&student->family_name, sizeof(student->family_name), 1, file);
	fwrite(&student->sports, sizeof(student->sports), 1, file);
	AddToHuman(student, file);
	AddToExact(student, file);
}

static void AddToHuman(student_t *student, FILE *file)
{
	fwrite(&student->human_grade.literature, sizeof(student->human_grade.literature), 1, file);
	fwrite(&student->human_grade.psychology, sizeof(student->human_grade.psychology), 1, file);
	fwrite(&student->human_grade.history, sizeof(student->human_grade.history), 1, file);
	fwrite(&student->human_grade.politics, sizeof(student->human_grade.politics), 1, file);
}

static void AddToExact(student_t *student, FILE *file)
{
	fwrite(&student->exact_grade.physics, sizeof(student->exact_grade.physics), 1, file);
	fwrite(&student->exact_grade.mathematics, sizeof(student->exact_grade.mathematics), 1, file);
	fwrite(&student->exact_grade.computer_science, sizeof(student->exact_grade.computer_science), 1, file);
}

static void LoadFromStudent(student_t *student, FILE *file)
{
	fread(&student->name, sizeof(student->name), 1, file);
	fread(&student->family_name, sizeof(student->family_name), 1, file);
	fread(&student->sports, sizeof(student->sports), 1, file);
	LoadFromHuman(student, file);
	LoadFromExact(student, file);
}

static void LoadFromHuman(student_t *student, FILE *file)
{
	fread(&student->human_grade.literature, sizeof(student->human_grade.literature), 1, file);
	fread(&student->human_grade.psychology, sizeof(student->human_grade.psychology), 1, file);
	fread(&student->human_grade.history, sizeof(student->human_grade.history), 1, file);
	fread(&student->human_grade.politics, sizeof(student->human_grade.politics), 1, file);
}

static void LoadFromExact(student_t *student, FILE *file)
{
	fread(&student->exact_grade.physics, sizeof(student->exact_grade.physics), 1, file);
	fread(&student->exact_grade.mathematics, sizeof(student->exact_grade.mathematics), 1, file);
	fread(&student->exact_grade.computer_science, sizeof(student->exact_grade.computer_science), 1, file);
}


int LoadFromFile(student_t *student, FILE *file, size_t person_number)
{
	
	assert(NULL != student && NULL != file);
	fseek(file, SIZE * (person_number - 1), SEEK_SET);
	LoadFromStudent(student, file);
	if(EOF == fclose(file))
	{
		return 0;
	}
	return 1;
}

