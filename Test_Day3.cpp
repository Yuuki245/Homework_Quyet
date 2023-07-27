#include<iostream>
#include<string.h>
using namespace std;

class Person
{   
    private:
    char name[30];
    int age;
    float mark;
    public:
    Person()
    {
        strcpy(name, "Chua Nhap");
        age = 0;
        mark = 0.0;
    }
    Person(char name[30], int age, float mark)
    {
        strcpy(this->name, name);
        this->age = age;
        this->mark = mark;
    }
    void import()
    {
        cout << "Nhap ten: "; cin.ignore(); cin.getline(name, 30);
        cout << "Nhap tuoi: "; cin >> age;
        do
        {
            cout << "Nhap diem trung binh: "; cin >> mark;
        } while (mark < 0 || mark > 10);
        
    }
    void exportt()
    {
        cout << "Ten: " << name << endl;
        cout << "Tuoi: " << age << endl;
        cout << "Diem Trung Binh: " << mark << endl;
        cout << "Xep Loai: ";
    }
    float get_mark()
    {
        return this -> mark;
    }
    char* get_name()
    {
        return this->name;
    }
    void set_mark(float mark)
    {
        this->mark = mark;
    }
};
void Import(Person arr[], int &n)
{
    for(int i = 0; i < n; i++)
    {   
        cout << "\tSinh Vien " << i + 1 << endl;
        arr[i].import();
    }
}
void Export(Person arr[], int &n)
{
    for(int i = 0; i < n; i++)
    {   
        cout << "\tSinh Vien " << i + 1 << endl;
        arr[i].exportt();
        if(arr[i].get_mark() >= 8)
        cout << "Gioi\n";
        else if(arr[i].get_mark() >= 7)
        cout << "Kha\n";
        else if(arr[i].get_mark() >= 5)
        cout << "Trung Binh\n";
        else cout << "Kem\n";
    }
    
}
void Sort(Person arr[], int &n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(arr[i].get_name(),arr[j].get_name()))
            swap(arr[i], arr[j]);
        }
    }
}
void Find(Person arr[], int &n)
{   
    bool check = false;
    for(int i = 0; i < n; i++)
    {
        if(strcmpi(arr[i].get_name(), "Nguyen Van A") == 0)
        {   
            check = true;
            arr[i].set_mark(10);
        }
    }
    if(!check)
    cout << "Khong Tim Thay Sinh Vien Ten 'Nguyen Van A' !\n";
}
int main()
{
    int n;
    cout << "Nhap so sinh vien: "; cin >> n;
    Person *arr = new Person[n];
    Import(arr, n);
    system("cls");
    Sort(arr, n);
    Find(arr, n);
    Export(arr, n);
}
