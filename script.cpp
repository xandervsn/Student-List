/* Xander Siruno-Nebel
   11/2/22
   Galbraith, C++/Data Structures
   Student-List: adds, removes, and prints students as structs from a list
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip> 

using namespace std;

struct Student{//creates new student struct
  char firstName[80];
  char lastName[80];
  float gpa;
  int id;
};

void add(vector<Student>* input);
void remove(vector<Student>& input);
void print(vector<Student> input);

int main(){
  vector<Student> students;//vector of students
  char input[7];
  while(true){
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
      return 0;
      //cout << "i shouldnt run";
    }
  }
  return 0;
}

void add(vector<Student>* input){
  Student temp;//creates new student
  int id = -1;
  float gpa= -1;
  char firstName[80];
  char lastName[80];
  cout << "Input First Name" << endl;
  cin >> firstName;
  cout << "Input Last Name" << endl;
  cin >> lastName;
  cout << "Input Student ID" << endl;
  cin >> id;
  cout << "Input GPA" << endl;
  cin >> gpa;
  //cout << "1";
  temp.gpa = gpa;//sets gpa of new student
  temp.id = id;//sets id of new student
  //cout << "2";
  memcpy(temp.firstName, firstName, 80);//sets first name of student
  memcpy(temp.lastName, lastName, 80);//sets last name of student
  //cout << "3";
  input->push_back(temp);//pushes info to vector
  //cout << "4";
}

void remove(vector<Student>& input){
  int removeID = -1;
  cout << "Input ID of desired student" << endl;
  cin >> removeID;
  for(int i = 0; i < input.size(); i++){//goes through all vectors, if the input and id match, removes student from vector
    if(input[i].id == removeID){
      input.erase(input.begin() + i);
      return;
    }
  }
}

void print(vector<Student> input){
  for(int i = 0; i < input.size(); i++){//goes through all vectors, prints them out
    float gpa = input[i].gpa;//formats gpa with decimals
    cout << input[i].firstName << " " << input[i].lastName << " | ID: " << input[i].id << " GPA: " << setprecision(2) << fixed << gpa << endl;
  }
}
