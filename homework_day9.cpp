#include<iostream>
#include<algorithm>
using namespace std;

class DocGia
{   
    protected:
    int ma_sach;
    string ten_sach, tac_gia, hoten;
    int tuoi;
    int ngay_thue, ngay_tra;
    int thanh_tien;
    public:
    virtual void Nhap()
    {
        cout << "Nhap ma sach: "; cin >> ma_sach;
        cout << "Nhap ten sach: "; cin.ignore(); getline(cin, ten_sach);
        cout << "Nhap ten tac gia: "; getline(cin, tac_gia);
        cout << "Nhap ten doc gia: "; getline(cin, hoten);
        cout << "Nhap tuoi: ";cin >> tuoi;
        cout << "Nhap ngay thue: ";cin >> ngay_thue;
        cout << "Nhap ngay tra: ";cin >> ngay_tra;
    }
    virtual void Xuat()
    {
        cout << "Ma sach: "<< ma_sach << endl;
        cout << "Ten sach: " << ten_sach << endl;
        cout << "Ten tac gia: " << tac_gia << endl;
        cout << "Ten doc gia: " << hoten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Ngay thue: " << ngay_thue << endl;
        cout << "Ngay tra: " << ngay_tra << endl;
    }
    virtual int ThanhTien() = 0;
    int get_ngay_tra()
    {
        return this->ngay_tra;
    }
    int get_ngay_thue()
    {
        return this->ngay_thue;
    }
    virtual bool phan_loai() = 0;
    string get_tacgia()
    {
        return this->tac_gia;
    }
};

class TreEm : public DocGia
{
    private:
    string ten_giamho;
    public:
    int ThanhTien()
    {
        return 2 * (get_ngay_tra() - get_ngay_thue());
    }
    void Nhap()
    {   
        DocGia::Nhap();
        cout << "Nhap ten giam ho: ";cin.ignore(); getline(cin, ten_giamho);
    }
    void Xuat()
    {   
        DocGia::Xuat();
        cout << "Ten giam ho: " << ten_giamho << endl;
    //    cout << "Thanh tien: " << thanh_tien << endl;
    }
    
    bool phan_loai()
    {
        return true;
    }
};
class NguoiLon : public DocGia
{
    public:
    int ThanhTien()
    {
        return 3 * (get_ngay_tra() - get_ngay_thue());
    }
    void Nhap()
    {
        DocGia::Nhap();
    }
    void Xuat()
    {
        DocGia::Xuat();
     //   cout << "Thanh tien: " << thanh_tien << endl;
    }
    
    bool phan_loai()
    {
        return false;
    }
};

class QuanLy
{
    private:
    DocGia *qly[100];
    int n;
    public:
    void qly_Nhap()
    {   
        int lc;
        cout << "\n\tNhap so doc gia can quan ly: "; cin >> n;
        for(int i = 0; i < n; i++)
        {
            cout << "Nhap ho so benh nhan thu " << i + 1 << endl;
            cout << "[.] Chon lua doc gia " << endl
                 << "1. Doc Gia Tre Em.\n"
                 << "2. Doc Gia Nguoi Lon.\n";
            do
            {  
                cout << "Nhap lua chon cua ban: ";
                cin >> lc;
            }while(lc < 1 || lc > 2);
            if(lc == 1)
                qly[i] = new TreEm;
            else
                qly[i] = new NguoiLon;
            qly[i]->Nhap();
        }
    }
    void qly_Xuat()
    {
        for(int i = 0; i < n; i++)
        {
            cout << "\n\tDoc Gia So " << i + 1  << (qly[i]->phan_loai() ? " 'Tre Em' " : " 'Nguoi Lon' ") << endl;
            qly[i]->Xuat();
            cout << "Thanh tien: " << qly[i]->ThanhTien() << endl;
        }
    }
    void Tong()
    {
        int tong_tt = 0, tong_nl = 0;
        for(int i = 0 ; i < n; i++)
        {
            qly[i]->phan_loai() ? tong_tt += qly[i]->ThanhTien() : tong_nl += qly[i]->ThanhTien();
        }
        cout << "Tong tien doc gia tre em: " << tong_tt << endl;
        cout << "Tong tien doc gia nguoi lon: " << tong_nl << endl;
    }
    void Sapxep()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(qly[i]->get_tacgia().compare(qly[j]->get_tacgia()) > 0)
                swap(qly[i], qly[j]);
            }
        }
        cout << "\n\n\t\tDanh Sach Sau Khi Sap Xep\n";
        qly_Xuat();
    }
};
int main()
{
    QuanLy *qly = new QuanLy;
    qly->qly_Nhap();
    system("cls");
    qly->qly_Xuat();
    qly->Tong();
    qly->Sapxep();
}