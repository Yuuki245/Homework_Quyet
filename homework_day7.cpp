#include<iostream>
using namespace std;

class BenhNhan
{   
    private:
    string ma_hoso, hoten, benh;
    int ngaysinh;
    public:
    int get_ngaysinh()
    {
        return this->ngaysinh;
    }
    virtual bool phan_loai() = 0;
    virtual void Nhap()
    {
        cout << "Nhap ma ho so benh nhan: "; cin >> ma_hoso;
        cout << "Nhap ho ten benh nhan: ";cin.ignore(); getline(cin, hoten);
        cout << "Nhap ngay sinh benh nhan: "; cin >> ngaysinh;
        cout << "Nhap chuan doan benh: "; cin.ignore(); getline(cin, benh);     
    }
    virtual void Xuat()
    {
        cout << "Ma ho so benh nhan: " << ma_hoso << endl;
        cout << "Ho ten benh nhan: " << hoten << endl;
        cout << "Ngay sinh benh nhan: " << ngaysinh << endl;
        cout << "Chuan doan benh: " << benh << endl;     
    }
};
class NoiTru : public BenhNhan
{   
    private:
    int ngay_nhapvien, ngay_xuatvien;
    string khoa;
    int so_giuong;
    public:
    void Nhap()
    {
        BenhNhan::Nhap();
        cout << "Nhap ngay nhap vien: "; cin >> ngay_nhapvien;
        cout << "Nhap ngay xuat vien: "; cin >> ngay_xuatvien;
        cout << "Nhap khoa dieu tri: "; cin.ignore(); getline(cin, khoa);
        cout << "Nhap so giuong: "; cin >> so_giuong;
    }
    void Xuat()
    {
        BenhNhan::Xuat();
        cout << "Ngay nhap vien: " << ngay_nhapvien << endl;
        cout << "Ngay xuat vien: " << ngay_xuatvien << endl;
        cout << "Khoa dieu tri: " << khoa << endl;;
        cout << "So giuong: " << so_giuong << endl;
    }
    bool phan_loai()
    {
        return true;
    }
};
class NgoaiTru : public BenhNhan
{
    private:
    int ngay_chuyen;
    string noi_chuyen;
    public:
    void Nhap()
    {
        BenhNhan::Nhap();
        cout << "Nhap ngay chuyen: "; cin >> ngay_chuyen;
        cout << "Nhap noi chuyen: ";cin.ignore(); cin >> noi_chuyen;
    }
    void Xuat()
    {
        BenhNhan::Xuat();
        cout << "Ngay chuyen: " << ngay_chuyen << endl;
        cout << "Noi chuyen: " << noi_chuyen << endl;
    }
    bool phan_loai()
    {
        return false;
    }
};
class Manager
{   
    private:
    BenhNhan *mger[100];
    int n;
    public:
    void mger_Nhap()
    {   
        cout << "Nhap so benh nhan can quan ly: "; cin >> n;
        for(int i = 0; i < n; i++)
        {
            cout << "\t\nNhap ho so benh nhan thu " << i + 1 << endl;
            cout << "[.] Chon loai ho so benh nhan" << endl
                 << "1. Benh Nhan Noi Tru.\n"
                 << "2. Benh Nhan Ngoai Tru.\n";
            int lc;
            do
            {  
                cout << "Nhap lua chon cua ban: ";
                cin >> lc;
            }while(lc < 1 || lc > 2);
            if(lc == 1)
                mger[i] = new NoiTru;
            else
                mger[i] = new NgoaiTru;
            mger[i]->Nhap();
        }
    }
    void mger_Xuat()
    {
        for(int i = 0; i < n; i++)
        {   
            cout << "\n\tBenh Nhan So " << i + 1  << (mger[i]->phan_loai() ? " 'Noi Tru' " : " 'Ngoai Tru' ") << endl;
            mger[i]->Xuat();
        }
    }
    
    void Count()
    {   
        int x, count_true = 0, count_false = 0;
        cout << "Nhap ngay sinh X: "; cin >> x;
        for(int i = 0; i < n; i++)
        {
            if(mger[i]->get_ngaysinh() > x)
            mger[i]->phan_loai() ? count_true++ : count_false++;
        }
        cout << "Ho so noi tru: " << count_true << endl
             << "Ho so ngoai tru: " << count_false << endl;
    }
};

int main()
{
    Manager *mger = new Manager;
    mger->mger_Nhap();
    system("cls");
    mger->mger_Xuat();
    mger->Count();
}