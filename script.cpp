#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip> 

using namespace std;

struct Student{
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

void add(vector<Student>* input);
void remove(vector<Student>& input);
void print(vector<Student> input);

int main(){
  bool run = true;
  vector<Student> students;
  char input[7];
  while(run){
    cout << "Input a valid command (ADD, PRINT, DELETE, QUIT)" << endl;
    cin >> input;
    if(strcmp(input,"ADD") == 0){
      add(&students);
    }
    else if(strcmp(input,"PRINT") == 0){
      print(students);
    }
    else if(strcmp(input,"DELETE") == 0){
      remove(students);
    }
    else if(strcmp(input,"QUIT") == 0){
      run = false;
    }
  }
  return 0;
}

void add(vector<Student>* input){
  Student temp;
  int id = 0;
  float gpa= 0;
  char firstName[100];
  char lastName[100];
  cout << "Input First Name" << endl;
  cin >> firstName;
  cout << "Input Last Name" << endl;
  cin >> lastName;
  cout << "Input Student ID" << endl;
  cin >> id;
  cout << "Input GPA" << endl;
  cin >> gpa;
  temp.gpa = gpa;
  temp.id = id;
  memcpy(temp.firstName, firstName, 100);
  memcpy(temp.lastName, lastName, 100);
  input->push_back(temp);
}

void remove(vector<Student>& input){
  int removeID= 0;
  cout << "Input ID of desired student" << endl;
  cin >> removeID;
  for(int i = 0; i < input.size(); i++){
    if(input[i].id == removeID){
      input.erase(input.begin() + i);
      return;
    }
  }
}

void print(vector<Student> input){
  for(int i = 0; i < input.size(); i++){
    float gpa = input[i].gpa;
    cout << input[i].firstName << " " << input[i].lastName << " ID: " << 
      input[i].id << " GPA: " << setprecision(2) << fixed << gpa << endl;
  }
}
