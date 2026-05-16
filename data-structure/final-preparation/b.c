typedef struct{
    int id;
    int score;
}Student;

void initstudent(Student *p){
    p -> id = 1001;
    p -> score = 0;
}

int main(){
    Student stu;
    initstudent(&stu);
    printf("id = %d, score = %d\n", stu.id, stu.score);
    return 0;
}