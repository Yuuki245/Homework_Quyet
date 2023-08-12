#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

class Nguoi
{	
	protected:
	string name;
	int year;
	public:
    Nguoi()
    {
        name = "";
        year = 0;
    }
    Nguoi(string name, int year)
    {
        this->name = name;
        this->year = year;
    }
    ~Nguoi(){}
	void Nhap()
	{
		cout << "Nhap ho ten thi sinh: "; cin.ignore(); getline(cin, name);
		cout << "Nhap nam sinh thi sinh: "; cin >> year;
	}
	void Xuat()
	{
		cout << "Ho ten thi sinh: " << name << endl
			 << "Nam sinh: " << year << endl;
	}
};

class ThiSinh : public Nguoi
{	
	private:
	int sbd;
	float toan, ly, hoa;
	public:
    ThiSinh():Nguoi()
    {
        sbd = 0;
        toan = ly = hoa = 0.0;
    }
    ThiSinh(string name, int year, int sbd, float toan, float ly, float hoa):Nguoi(name, year)
    {
        this->sbd = sbd;
        this->toan = toan;
        this->ly = ly;
        this->hoa = hoa;
    }
    ~ThiSinh(){}
	float get_tong()
	{
		return this->toan + this->ly + this->hoa;
	}
	int get_sbd()
	{
		return this->sbd;
	}
    float get_toan()
    {
        return this->toan;
    }
    float get_ly()
    {
        return this->ly;
    }
    float get_hoa()
    {
        return this->ly;
    }
	void Nhap()
	{
		Nguoi::Nhap();
		cout << "Nhap so bao danh: "; cin >> sbd;
		cout << "Nhap diem toan: "; cin >> toan;
		cout << "Nhap diem ly: "; cin >> ly;
		cout << "Nhap diem hoa: "; cin >> hoa;
	}
	void Xuat()
	{
		Nguoi::Xuat();
		cout << "So bao danh: " << sbd << endl;
		cout << "Diem toan: " << toan << endl;
		cout << "Diem ly: " << ly << endl;
		cout << "Diem hoa: " << hoa << endl;
		cout << "-> Tong diem: " << toan + ly + hoa << endl;
	}
};

void Nhap(ThiSinh arr[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Thi Sinh " << i + 1 << endl;
		arr[i].Nhap();
	}
}
void Xuat(ThiSinh arr[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\tThi Sinh " << i + 1 << endl;
		arr[i].Xuat();
	}
}
float cmp(ThiSinh a, ThiSinh b)
{
	return a.get_tong() < b.get_tong();
}
void SapXep(ThiSinh arr[], int n)
{
	sort(arr, arr + n, cmp);
	cout << "\n\t\tTong Diem Thi Sinh Tang Dan\n";
	for(int i = 0; i < n; i++)
	{
		cout << "\n\tThi Sinh " << i + 1 << endl;
		arr[i].Xuat();
	}
}
void Tim(ThiSinh arr[], int n)
{
	int index, count = 0;
	cout << "Nhap so bao danh can tim: "; cin >> index;
	for(int i = 0; i < n; i++)
	{
		if(index == arr[i].get_sbd())
		{
			cout << "\n\tThi Sinh Can Tim\n";
			arr[i].Xuat();
			count++;
		}
	}
	if(count == 0)
	cout << "Khong co thi sinh can tim!";
}
void ThongKe(ThiSinh arr[], int &n)
{   
    float index = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].get_toan() >= 5 && arr[i].get_ly() >= 5 && arr[i].get_hoa() >= 5)
        index++;
    }
    cout << "Ti le thi sinh dat yeu cau la: " << fixed << setprecision(0) << (index / n) * 100 << "%" << endl;
}
int main()
{
	int n; cout << "Nhap so thi sinh: "; cin >> n;
	ThiSinh arr[n];
	Nhap(arr, n);
    system("cls");
	Xuat(arr, n);
	SapXep(arr, n);
    cout << "\n------------------\n";
	Tim(arr, n);
    cout << "\n------------------\n";
    ThongKe(arr, n);
}
