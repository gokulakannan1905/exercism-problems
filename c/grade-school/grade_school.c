#include "grade_school.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void quick_sort(student_t*, uint8_t,uint8_t);
uint8_t pivot(student_t*, uint8_t,uint8_t);
void swap(student_t*,uint8_t,uint8_t);

// swaps two elements in an array
void swap(student_t* students, uint8_t i, uint8_t j){
    student_t temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

// quick sort helper function
uint8_t pivot(student_t* students, uint8_t start, uint8_t end){
    uint8_t pivot_index = start;
    student_t current = students[pivot_index];
    for(uint8_t i = start+1; i<=end; i++){
        if(students[i].grade < current.grade || (students[i].grade == current.grade && strcmp(students[i].name,current.name)<0)){
            pivot_index++;
            swap(students,i,pivot_index);
        }
    }
    if(start!=pivot_index)
    swap(students,start,pivot_index);
    return pivot_index;
}

//quick sort algorithm
void quick_sort(student_t* students, uint8_t start, uint8_t end){
    if(start < end){
        uint8_t pivot_index = pivot(students,start,end);
        if(pivot_index != 0)
        quick_sort(students,start,pivot_index-1);
        quick_sort(students,pivot_index+1,end);
    }
}



// initialize the roster 
void init_roster(roster_t* roster){
    roster->count = 0;
}

// add new student to the roster
bool add_student(roster_t* actual, char* name, uint8_t grade){

    if(name == NULL || strlen(name) == 0 || strlen(name) > MAX_NAME_LENGTH)
    return false;
    
    // create a new student from the input
    student_t student;
    strcpy(student.name,name);
    student.grade = grade;

    //check whether the student is already present
    if (actual->count != 0){
        for(uint8_t i=0;i<actual->count;i++){
            if(actual->students[i].grade == grade){
                if(strcmp(actual->students[i].name,name) == 0)
                return false;
            }else if(strcmp(actual->students[i].name,name)==0){
                return false;
            }
        }
    }

    // insert the new student into the actual roster input
    actual->students[actual->count] = student;
    actual->count++;

    //sort the roster
    if (actual->count != 0 && actual->count != 1)
    quick_sort(actual->students,0,actual->count - 1);

    return true;
}

// return the roster with specific grade
roster_t get_grade(roster_t* roster, uint8_t grade){
    roster_t result;
    uint8_t count = 0;
    init_roster(&result);
    
    for(uint8_t i=0; i< roster->count;i++){
        if (roster->students[i].grade == grade){
           result.students[count] = roster->students[i];
           count++; 
           result.count = count;
        }
    }
    return result;
}
