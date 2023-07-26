#include<iostream>
using namespace std;

class Teacher
{
    private:
    char name[30];
    int age;
    char degree[15];
    char major[20];
    float salary;
    public:
    void Import()
    {
        cout << "Nhap ten giao vien: ";cin.ignore(); cin.getline(name, 30); 
        cout << "Nhap tuoi giao vien: "; cin >> age;
        cout << "Nhap bang cap giao vien: "; cin.ignore(); cin.getline(degree, 15); 
        cout << "Nhap chuyen nganh giao vien: "; cin >> major;
        cout << "Nhap bac luong giao vien: "; cin >> salary;
    }
    void Export()
    {
        cout << "Ten Giao Vien: " << name << endl;
        cout << "Tuoi Giao Vien: " << age << endl;
        cout << "Bang Cap Giao Vien: " << degree << endl;
        cout << "Chuyen Nganh Giao Vien: " << major << endl;
        cout << "Bac Luong Giao Vien: " << salary << endl;
    }
    float Basic_Salary()
    {
        return salary*610;
    }
};
void ImportT(Teacher arr[], int &n)
{
    for(int i = 0; i < n; i++)
    {   
        cout << "\tGiao vien thu " << i + 1 << endl;
        arr[i].Import();
    }
}
void ExportT(Teacher arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i].Export();
    }
}
void Salary(Teacher arr[], int n)
{   
    cout << "\n\n\t\tGiao Vien Luong < 2000\n\n";
    for(int i = 0; i < n; i++)
    {
        if(arr[i].Basic_Salary() < 2000)
        arr[i].Export();
    }
}
int main()
{
    int n;
    cout << "Nhap so luong giao vien: "; cin >> n;
    Teacher *arr = new Teacher[n];
    ImportT(arr, n);
    Salary(arr, n);
}