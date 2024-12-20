#ifndef _COURSE_H
#define _COURSE_H

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "filerw.h"
#include "accountsystem.h"
#include "student.h"
#include "teacher.h"
#include "course.h"
#include "main.h"

void exchange(struct coursestruct *,int,int);
void arrangecourse();
void schedule(int);
void scheduleout(int);
void listcourse();
int listcoursewithoutm();

#endif