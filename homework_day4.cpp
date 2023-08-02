#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

class Teacher
{   
    private:
    char name[30];
    int age;
    char degree[15];
    char major[20];
    float wage;
    public:
    friend istream& operator >> (istream& in, Teacher &a)
    {
        cout << "Enter teacher name: "; in.ignore(); in.getline(a.name, 30);
        cout << "Enter teacher age: "; in >> a.age;
        cout << "Enter teacher degree: "; in.ignore(); in.getline(a.degree, 15); // bang cap
        cout << "Enter teacher major: "; in.getline(a.major, 15); // chuyen nganh
        cout << "Enter teacher wage: "; in >> a.wage; // bac luong
        return in;
    }
    friend ostream& operator << (ostream& out, Teacher &a)
    {
        cout << "Teacher name: " << a.name << endl;
        cout << "Teacher age: " << a.age << endl;
        cout << "Teacher degree: " << a.degree << endl;
        cout << "Teacher major: " << a.major << endl;
        cout << "Teacher wage: " << a.wage << endl;
        return out;
    }
    float get_salary()
    {
        return this->wage;
    }
    bool operator == (Teacher a)
    {
        return strcmpi(this->degree,a.degree) == 0;
    }
    char* get_degree()
    {
        return this->degree;
    }
};
void Import(Teacher arr[], int &n)
{
    for(int i = 0; i < n; i++)
    {   
        cout << "\n\t\tEnter Teacher Information " << i + 1 << endl;
        cin >> arr[i];
    }
}
void Export(Teacher arr[], int &n)
{   
    for(int i = 0; i < n; i++)
    {   
        cout << "\n\t\tTeacher Information " << i + 1 << endl;
        cout << arr[i];
    }
}
void Salary(Teacher arr[], int n)
{
    for(int i = 0; i < n; i++)
    {   
        cout << "\n\t\tSalary Teacher Information " << i + 1 << endl;
        cout << arr[i] << "Basic Salary: " << arr[i].get_salary()*610 << " vnd" <<  endl;
    }
}
void Sort(Teacher arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmpi(arr[i].get_degree(), arr[j].get_degree()))
            swap(arr[i], arr[j]);
        }
    }
}
int main()
{   
    int n; cout << "Enter the number of teacher: "; cin >> n;
    Teacher *arr = new Teacher[n];
    Import(arr, n);
    system("cls");
    Salary(arr, n);
    Sort(arr, n);
    cout << "\n\t\tList Teacher After Sort\n";
    Export(arr, n);
}