#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct Gambar
{
    Gambar *prev;
    string namaFile;
    string jenisFile;
    int besar;
    Gambar *next;
} *head = NULL, *tail = NULL, *bantuan = NULL;

int counGambars(struct Gambar *p)
{
    int count{};
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

int isEmpty()
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

 void cariData (string key1,string key2)
{
     string flag1{}, flag2{};
     struct Gambar *bantu;
     bantu = head;
     do 
    {
        if (bantu->namaFile == key1 && bantu->jenisFile == key2)
        {
            flag1 = key1;
            flag2 = key2;
            cout << "Gambar ditemukan : " << flag1 << "(Nama File) dan " << flag2 << "(Jenis File)\n";
            break;
        }
        bantu = bantu->next;
    }while (bantu != head);
 }
void insertDepan(string databaru1, string databaru2, int databaru3)
{
    Gambar *baru;
    baru = new Gambar;
    baru->prev = NULL;
    baru->namaFile = databaru1;
    baru->jenisFile = databaru2;
    baru->besar = databaru3;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
        tail->next = head;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data masuk\n";
}

void insertBelakang(string databaru1, string databaru2, int databaru3)
{
    struct Gambar *baru;
    baru = new struct Gambar;
    baru->prev = NULL;
    baru->namaFile = databaru1;
    baru->jenisFile = databaru2;
    baru->besar = databaru3;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
        tail->next = head;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data masuk\n";
}

void insertTengahBefore(string databaru1, string databaru2, int databaru3)
{
    struct Gambar *bantu = head;
    string cari1{}, cari2{};
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Masukkan Sebelum Nama File : ";
    std::getline(std::cin, cari1);
    std::cout << "Masukkan Sebelum Jenis File : ";
    std::getline(std::cin, cari2);
    if (!isEmpty())
    {
        struct Gambar *baru;
        baru = new struct Gambar;
        baru->prev = NULL;
        baru->namaFile = databaru1;
        baru->jenisFile = databaru2;
        baru->besar = databaru3;
        baru->next = NULL;
        
        do
        {
            if ((head == tail) && (head->namaFile == cari1 && head->jenisFile == cari2))
            {
                baru->next = head;
                head->prev = baru;
                head = baru;
                tail->next = head;
                head->prev = tail;
                break;
            }
            else if (bantu->next->namaFile == cari1 && bantu->next->jenisFile == cari2)
            {
                if (bantu -> next != head)
                {
                    baru->prev = bantu;
                    baru->next = bantu->next;
                    bantu->next = baru;
                    baru->next->prev = baru;
                    break;
                }
                else
                    cout << "Tidak Bisa Menambah Gambar Sebelum Data Pertama!\n";
            }
            bantu = bantu->next;
        } while (bantu != head);
    }
    else
        cout << "Data tidak ditemukan" << endl;
}

void hapusDepan()
{
    Gambar *hapus;
    string delete1, delete2;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            delete1 = hapus->namaFile;
            delete2 = hapus->jenisFile;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete hapus;
        }
        else
        {
            delete1 = tail->namaFile;
            delete2 = tail->jenisFile;
            delete head;
            head = tail = NULL;
        }
        cout << delete1 << "(Nama File) dan " << delete2 <<  "(Jenis File) " <<" Terhapus\n";
    }
    else
        cout << "Data Masih kosong\n";
}

void hapusBelakang()
{
    Gambar *hapus;
    string delete1, delete2;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = tail;
            delete1 = hapus->namaFile;
            delete2 = hapus->jenisFile;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete hapus;
        }
        else
        {
            delete1 = tail->namaFile;
            delete2 = tail->jenisFile;
            delete head;
            head = tail = NULL;
        }
        cout << delete1 << "(Nama File) dan " << delete2 <<  "(Jenis File) " <<" Terhapus\n";
    }
    else
        cout << "Data Masih kosong\n";
}

 void hapusTengah(string key1, string key2)
 {
     struct Gambar *bantu, *hapus;
     string delete1{}, delete2{};
     bantu = head;
         do 
        {
             if ((head == tail) && (head->namaFile == key1 && head->jenisFile == key2))
            {
                 delete1 = head->namaFile;
                 delete2 = head->jenisFile;
                 delete bantu;
                 head = tail = NULL;
                 break;
            }
             else if ((bantu->namaFile == key1 && bantu->jenisFile == key2) && counGambars(head) == 2)
             {
                 cout << "Data pertama dan terakhir tidak boleh dihapus" << endl;
                 break;
             }
             else if (bantu->next->namaFile == key1 && bantu->next->jenisFile == key2)
            {
                delete1 = bantu->next->namaFile;
                delete2 = bantu->next->jenisFile;
                hapus = bantu->next;
                bantu->next = hapus->next;
                hapus->next->prev = bantu;
                delete hapus;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);
         cout << delete1 << "(Nama File) dan " << delete2 << "(Jenis File) terhapus " << endl;
 }
void tampil()
{
    struct Gambar *bantu;
    int i{1};
    string headerPlaylist{"Daftar Gambar"};
    bantu = head;
    if (isEmpty())
        cout << "Daftar Gambars Lagu Masih Kosong!" << endl;
    else
    {
        cout << setw(45) << std::right << headerPlaylist  << endl;
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
        do
        {
            cout << setw(10) << std::left << i << std::setw(20) << std::left <<bantu->namaFile
            << std::setw(30) << std::left << bantu->jenisFile
            << std::setw(2) << std::left << bantu->besar <<endl;
            bantu = bantu->next;
            i++;
        } while (bantu != head);
        cout << setfill(' ');
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
}

void tampilBelakang()
{
    struct Gambar *bantu;
    int i{1};
    string headerPlaylist{"Daftar Gambar"};
    bantu = tail;
   if (isEmpty())
        cout << "Daftar Gambar Masih Kosong!" << endl;
    else
    {
        cout << setw(45) << std::right << headerPlaylist  << endl;
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
        do
        {
            cout << setw(10) << std::left << i << std::setw(20) << std::left <<bantu->namaFile
            << std::setw(30) << std::left << bantu->jenisFile
            << std::setw(2) << std::left << bantu->besar <<endl;
            bantu = bantu->prev;
            i++;
        } while (bantu != tail);
        cout << setfill(' ');
        cout  << setw(64) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
}

void playFirstSong ()
{
    bantuan = head;
    if (!isEmpty())
    {
        cout << setw(40) << std::right << "Menampilkan Gambar Pertama"  << endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
        cout << std::setw(20) << std::left << bantuan->namaFile
        << std::setw(30) << std::left <<  bantuan->jenisFile
        << std::setw(2) << std::left << bantuan->besar <<endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
    else
        cout << "Daftar Gambar Masih Kosong!" << endl;
}
void playNextSong ()
{
    if (bantuan == NULL)
    {
        playFirstSong();
        return;
    }
    if (!isEmpty())
    {
         if (bantuan != NULL)
            bantuan = bantuan->next;
        cout << setw(40) << std::right << "Menampilkan Gambar Selanjutnya"  << endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
        cout << std::setw(20) << std::left << bantuan->namaFile
        << std::setw(30) << std::left <<  bantuan->jenisFile
        << std::setw(2) << std::left << bantuan->besar <<endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
    else
        cout << "Daftar Gambar Masih Kosong!" << endl;
}
void playPrevSong ()
{
    if (bantuan == NULL)
    {
        playFirstSong();
        return;
    }
    if (!isEmpty())
    {
        if (bantuan != NULL)
            bantuan = bantuan->prev;
        cout << setw(40) << std::right << "Daftar Gambar Sebelumnya"  << endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
        cout << std::setw(20) << std::left << bantuan->namaFile
        << std::setw(30) << std::left <<  bantuan->jenisFile
        << std::setw(2) << std::left << bantuan->besar <<endl;
        cout  << setw(54) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }
    else
        cout << "Daftar Gambar Masih Kosong!" << endl;
}
int main()
{
    system("Color 0B");
    string judul{}, jenisFile{}, key1{}, key2{};
    int pil{}, besar{};
    do
    {
        cout << endl;
        cout << " ================================" << endl;
        cout << " =      DAFTAR GAMBAR LAGU      =" << endl;
        cout << " ================================" << endl;
        cout << " = 1. Insert Gambar dari Depan   =" << endl;
        cout << " = 2. Insert Gambar dari Tengah   =" << endl;
        cout << " = 3. Tambah Gambar dari Belakang =" << endl;
        cout << " = 4. Hapus Gambar di Depan       =" << endl;
        cout << " = 5. Hapus Gambar di Tengah      =" << endl;
        cout << " = 6. Hapus Gambar di Belakang    =" << endl;
        cout << " = 7. Tampil Gambar dari Depan    =" << endl;
        cout << " = 8. Tampil Gambar dari Belakang =" << endl;
        cout << " = 9. Cari Gambar                 =" << endl;
        cout << " = 10. Mainkan Gambar Terawal     =" << endl;
        cout << " = 11. Mainkan Gambar Selanjutnya =" << endl;
        cout << " = 12. Mainkan Gambar Sebelumnya  =" << endl;
        cout << " = 13.Selesai                   =" << endl;
        cout << " ================================" << endl;
        cout << " Masukan Pilihan : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            system("cls");
            {
                std::cout << "Tambahkan Gambar Baru ke Daftar Gambar" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Masukkan Nama File : ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan Nama Jenis File : ";
                std::getline(std::cin, jenisFile);
                std::cout << "Masukkan besar Besar File: ";
                std::cin >> besar;
                insertDepan(judul,jenisFile, besar);
                break;
            }
        case 2:
            system("cls");
            {
                std::cout << "Tambahkan Gambar Baru ke Daftar Gambar" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Masukkan Nama File : ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan Jenis File: ";
                std::getline(std::cin, jenisFile);
                std::cout << "Masukkan besar file: ";
                std::cin >> besar;
                insertTengahBefore(judul,jenisFile,besar);
                break;
            }
        case 3:
            system("cls");
            {
                std::cout << "Tambahkan Gambar Baru ke Daftar Gambar" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Masukkan Nama File : ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan Jenis File: ";
                std::getline(std::cin, jenisFile);
                std::cout << "Masukkan besar file: ";
                std::cin >> besar;
                insertBelakang(judul, jenisFile, besar);
                break;
            }
        case 4:
            system("cls");
            {
                hapusDepan();
                break;
            }
         case 5:
             system("cls");
             {
                 if (!isEmpty())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Masukkan Nama File : ";
                    std::getline(std::cin, judul);
                    std::cout << "Masukkan Jenis File : ";
                    std::getline(std::cin, jenisFile);
                    hapusTengah(judul, jenisFile);
                }
                else
                    cout << "Daftar Gambar Masih Kosong!\n";
                break;
             }
        case 6:
            system("cls");
            {
                hapusBelakang();
                break;
            }
        case 7:
            system("cls");
            {
                tampil();
                break;
            }
        case 8:
            system("cls");
            {
                tampilBelakang();
                break;
            }
        
        case 9:
            system("cls");
            {
                if (!isEmpty())
                {
                    std::cout << "Cari Gambar dari Daftar Gambar" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Masukkan Nama File : ";
                    std::getline(std::cin, judul);
                    std::cout << "Masukkan Jenis File : ";
                    std::getline(std::cin, jenisFile);
                    cariData(judul, jenisFile);
                }
                else
                    cout << "Daftar Gambar Masih Kosong!" << endl;
                break;
            }
            case 10:
            system("cls");
            {
                playFirstSong();
                break;
            }
            case 11:
            system("cls");
            {
                playNextSong();
                break;
            }
            case 12:
            system("cls");
            {
                playPrevSong();
                break;
            }
            case 13 :
            system("cls");
            {
                exit(1);
                break;
            }
        }
        getch();
    } while (pil != 13);
    return 0;
}   