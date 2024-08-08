#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void Bai2(int year)
{   
    cout << "Nhap nam can kiem tra: "; cin >> year;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    cout << "Nam nay la nam nhuan !\n";
    else
    cout << "Nam nay la nam khong nhuan !";
}
void Bai5(int x, int y, int z)
{   
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
    cout << "Nhap z: "; cin >> z;
    int max = x;int min = x;
    if(max < y)     // So sanh max voi y
    max = y;
    if(max < z)     // Tiep tuc so sanh voi z
    max = z;
    if(min > z)     // So sanh voi z de tim min
    min = z;        
    cout << "So nho nhat la: " << min << endl;
    cout << "So lon nhat la: " << max << endl;
}
void Bai6(double a, double b, double c)
{
    double index;
    cout << "Nhap canh a: "; cin >> a;
    cout << "Nhap canh b: "; cin >> b;
    cout << "Nhap canh c: "; cin >> c;
    if(a + b > c && b + c > a && a + c > b && a != 0 && b != 0 && c != 0)
    {
        double p = (a + b + c) / 2;
        cout << "3 canh tao thanh tam giac thuong !\n" << "Chu vi tam giac la: " << p * 2 << "\nDien tich tam giac la: " << setprecision(2) << fixed << 2 * (sqrt(p * (p - a)*(p - b)*(p - c)) / a);    
        if(a == b == c)
    {
        cout << "3 canh tao thanh tam giac deu !\n" << "Chu vi tam giac la: " << 3 * a << "\nDien tich tam giac la: " << pow(a, 2) * (sqrt(3)/4);
    }
        else if(a == b)
    {   
        index = sqrt(pow(a, 2)) - sqrt(pow((c/2), 2));
        cout << "3 canh tao thanh tam can !\n" << "Chu vi tam giac la: " << a * b + c << "\nDien tich tam giac la: " << (a * index) / 2; 
    }
        else if(a == c)
    {   
        index = sqrt(pow(a, 2)) - sqrt(pow((b/2), 2));
        cout << "3 canh tao thanh tam can !\n" << "Chu vi tam giac la: " << a * c + b << "\nDien tich tam giac la: " << (a * index) / 2; 
    }
        else if(c == b)
    {   
        index = sqrt(pow(b, 2)) - sqrt(pow((a/2), 2));
        cout << "3 canh tao thanh tam can !\n" << "Chu vi tam giac la: " << c * b + a << "\nDien tich tam giac la: " << (b * index) / 2; 
    }
}
    else
    {
        cout << "3 canh khong tao thanh tam giac !";
    } 
}
void Bai7(double dkt, double dgk, double dck)
{   
    double dtb;
    do
    {
        cout << "Nhap diem kiem tra: "; cin >> dkt;
    } while(dkt < 0 || dkt > 10);
    do
    {
        cout << "Nhap diem giua ky: "; cin >> dgk;
    } while(dgk < 0 || dgk > 10);
    do
    {
        cout << "Nhap diem cuoi ky: "; cin >> dck;
    } while(dck < 0 || dck > 10);
    dtb = (dkt + dgk + dck) / 3;
    if(dtb >= 9 && dtb <= 10)
    cout << "Dat Hang A !\n";
    else if(dtb >= 7)
    cout << "Dat Hang B !\n";
    else if(dtb >= 5)
    cout << "Dat Hang C !";
    else
    cout << "Dat Hang F !";
}
int main()
{
    // int year;
    // Bai2(year);
    // int x, y, z;
    // Bai5(x, y, z);
    // double a, b, c;
    // Bai6(a, b, c);
    // double dkt, dgk, dck;
    // Bai7(dkt, dgk, dck);
}