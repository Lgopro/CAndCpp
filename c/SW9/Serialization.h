

#ifndef __GRADES_H__
#define __GRADES_H__


typedef struct Humanistic human_t;
typedef struct Exact exact_t;
typedef struct Student student_t;


struct Exact
{
	unsigned int physics;
	unsigned int mathematics;
	unsigned int computer_science;
};

struct Humanistic
{
	unsigned int literature;
	unsigned int psychology;
	unsigned int history;
	unsigned int politics;
	unsigned int law;
};

struct Student
{
	char name[20];
	char family_name[20];
	human_t human_grade;
	exact_t exact_grade;
	float sports;
};


/*
Description: Add to all the data of the student to the file.
Receive: Student pointer, file pointer.
Return: return 1 on success and 0 on fail.
*/
int AddToFile(student_t *student, FILE *filename);
/*
Description: Load from the file to a student struct.
Receive: Student pointer, file pointer.
Return: return 1 on success and 0 on fail.
*/
int LoadFromFile(student_t *student, FILE *filename,size_t person_number);



#endif /*__GRADES_H__*/

