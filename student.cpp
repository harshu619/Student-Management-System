#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<sstream>
using namespace std;
struct Student{
    int id;
    string name;
    int age;
    string branch;
};
vector<Student> students;
// Save to file
void savetofile(){
    ofstream file("students.txt", ios::out);
    for(const auto &s : students){
        file << s.id << "|" << s.name << "|" << s.age << "|" << s.branch << endl;
    }
    file.close();
}
// Load from file
void loadfromfile(){
    ifstream file("students.txt");
    if(!file){
        return;
    }
    students.clear();
    Student s;
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string temp;
        getline(ss,temp,'|');
        s.id = stoi(temp);
        getline(ss,s.name,'|');
        getline(ss,temp,'|');
        s.age = stoi(temp);
        getline(ss,s.branch,'|');
        students.push_back(s);
    }
    file.close();
}
// Check duplicate ID
bool isDuplicateID(int id){
    for(const auto &s : students){
        if(s.id == id){
            return true;
        }
    }
    return false;
}
// Add Student
void addStudent(){
    Student s;
    cout<<"Enter ID: ";
    cin>>s.id;
    if(isDuplicateID(s.id)){
        cout<<"Student with this ID already exists\n";
        return;
    }
    cout<<"Enter Name: ";
    cin.ignore();
    getline(cin,s.name);
    cout<<"Enter Age: ";
    cin>>s.age;
    cout<<"Enter Branch: ";
    cin.ignore();
    getline(cin,s.branch);
    students.push_back(s);
    savetofile();
    cout<<"Student added successfully\n";
}
// Display Students
void displayStudent(){
    if(students.empty()){
        cout<<"No records found\n";
        return;
    }
    for(const auto &s : students){
        cout<<"\n---------------------\n";
        cout<<"ID: "<<s.id<<endl;
        cout<<"Name: "<<s.name<<endl;
        cout<<"Age: "<<s.age<<endl;
        cout<<"Branch: "<<s.branch<<endl;
    }
}
// Search Student
void searchStudent(){
    int id;
    cout<<"Enter ID to search: ";
    cin>>id;
    for(const auto &s : students){
        if(s.id==id){
            cout<<"\nStudent Found\n";
            cout<<"---------------------\n";
            cout<<"ID: "<<s.id<<endl;
            cout<<"Name: "<<s.name<<endl;
            cout<<"Age: "<<s.age<<endl;
            cout<<"Branch: "<<s.branch<<endl;
            return;
        }
    }
    cout<<"Student not found\n";
}
// Delete Student
void deleteStudent(){
    int id;
    cout<<"Enter ID to delete: ";
    cin>>id;
    for(size_t i=0;i<students.size();i++){
        if(students[i].id==id){
            students.erase(students.begin()+i);
            savetofile();
            cout<<"Student deleted successfully\n";
            return;
        }
    }
    cout<<"Student not found\n";
}
// Update Student
void updateStudent(){
    int id;
    cout<<"Enter Student ID to update: ";
    cin>>id;
    for(auto &s : students){
        if(s.id==id){
            cout<<"Enter New Name: ";
            cin.ignore();
            getline(cin,s.name);
            cout<<"Enter New Age: ";
            cin>>s.age;
            cout<<"Enter New Branch: ";
            cin.ignore();
            getline(cin,s.branch);
            savetofile();
            cout<<"Student updated successfully\n";
            return;
        }
    }
    cout<<"Student not found\n";
}
// Sort Students
void sortStudents(){
    sort(students.begin(),students.end(),[](Student a,Student b){
        return a.id < b.id;
    });
    savetofile();
    cout<<"Students sorted by ID successfully\n";
}
// Main Menu
int main(){
    loadfromfile();
    int choice;
    while(true){
        cout<<"\n===== Student Management System =====\n";
        cout<<"1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Search Student\n";
        cout<<"4. Delete Student\n";
        cout<<"5. Update Student\n";
        cout<<"6. Sort Students\n";
        cout<<"7. Exit\n";
        cout<<"Enter choice: ";
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
                updateStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
}
