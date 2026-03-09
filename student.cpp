#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
// Student Class
class Student{
    public:
    int id;
    string name;
    int age;
    string branch;
    void input(){
        cout<<"Enter ID:";
        cin>>id;
        cout<<"Enter Name:";
        cin>>name;
        cout<<"Enter Age:";
        cin>>age;
        cout<<"Enter Branch:";
        cin>>branch;
    }
    void display(){
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"Branch:"<<branch<<endl;
        cout<<"--------------------"<<endl;
    }
};
// Add Student 
vector<Student>students;
void addStudent()
{
    Student s;
    s.input();
    students.push_back(s);
    cout<<"Student added successfully\n";
}
//Display Students
void displayStudent()
{
    if(students.empty()){
        cout<<"No Students found\n";
        return;
    }
    for(Student &s:students){
        s.display();
    }
}
//Search Student 
void searchStudent(){
    int id;
    cout<<"Enter Student ID:";
    cin>>id;
    for(Student &s:students){
        if(s.id==id){
            s.display();
            return;
        }
    }
    cout<<"Student not found\n";
}
//Delete Student
void deleteStudent(){
    int id;
     cout<<"Enter Student ID to delete:";
     cin>>id;
    for(size_t i=0;i<students.size();i++){
        if(students[i].id==id){
            students.erase(students.begin()+i);
            cout<<"Student deleted\n";
            return;
        }
    }
cout<<"Student not found\n";
}
//Main Menu
int main(){
    int choice;
    while(true){
        cout<<"\n===== Student Management System =====\n";
        cout<<"1.Add Student\n";
        cout<<"2.Display Students\n";
        cout<<"3.Search Student\n";
        cout<<"4.Delete Student\n";
        cout<<"5.Exit\n";
        cout<<"Enter choice:";
        cin>>choice;
        switch(choice){
            case 1:
            addStudent();
            break;
            case 2:
            displayStudent();
            break;
            case 3:
            searchStudent();
            break;
            case 4:
            deleteStudent();
            break;
            case 5:
            exit(0);
            default:
            cout<<"Invalid choice\n";
        }
    }
}