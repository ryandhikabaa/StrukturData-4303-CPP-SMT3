#include <iostream>
using namespace std;

int main()
{
  cout << "Nama : Ferris Tita Sabilillah" << endl;
  cout << "NIM : A11.2021.13579" << endl;
  cout << "Kelp : A11.43UG1" << endl;
  cout << endl;
  int i, j, baris1, kolom1, baris2, kolom2, baris3, kolom3, k;
  int matriksawal[10][10], hasiltranspose[10][10], matriks1[10][10], matriks2[10][10], hasil[10][10];
  int jumlah = 0;
  cout << "Masukkan jumlah baris matriks pertama: ";
  cin >> baris1;
  cout << "Masukkan jumlah kolom matriks pertama: ";
  cin >> kolom1;
  cout << endl;
  cout << "Masukkan elemen matrix pertama: " << endl;
  for (i = 0; i < baris1; i++)
  {
    for (j = 0; j < kolom1; j++)
    {
      cout << "element a" << i + 1 << j + 1 << ": ";
      cin >> matriks1[i][j];
    }
  }
  cout << endl;
  cout << "Masukkan elemen matrix kedua: " << endl;
  for (i = 0; i < baris1; i++)
  {
    for (j = 0; j < kolom1; j++)
    {
      cout << "element a" << i + 1 << j + 1 << ": ";
      cin >> matriks2[i][j];
    }
  }
  cout << endl;
  cout << "hasil penjumlahan matrix pertama dan kedua: " << endl;
  for (i = 0; i < baris1; i++)
  {
    for (j = 0; j < kolom1; j++)
    {
      hasil[i][j] = matriks1[i][j] + matriks2[i][j];
      cout << hasil[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
  cout << "hasil pengurangan matriks pertama dan kedua: \n";
  for (i = 0; i < baris1; i++)
  {
    for (j = 0; j < kolom1; j++)
    {
      hasil[i][j] = matriks1[i][j] - matriks2[i][j];
      cout << hasil[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
  cout << "Masukkan jumlah baris matriks ketiga: ";
  cin >> baris2;
  cout << "Masukkan jumlah kolom matriks ketiga: ";
  cin >> kolom2;
  cout << endl;
  if (kolom1 != baris2)
  {
    cout << "Matriks satu dan tiga tidak dapat dikalikan satu sama lain.\n";
  }
  else
  {
    cout << "Masukkan elemen matriks ketiga: \n";
    for (i = 0; i < baris2; i++)
    {
      for (j = 0; j < kolom2; j++)
      {
        cout << "element a" << i + 1 << j + 1 << ": ";
        cin >> matriks2[i][j];
      }
    }
    for (i = 0; i < baris1; i++)
    {
      for (j = 0; j < kolom2; j++)
      {
        for (k = 0; k < baris2; k++)
        {
          jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        }
        hasil[i][j] = jumlah;
        jumlah = 0;
      }
    }
    cout << endl;
    cout << "Hasil perkalian matriks pertama dan ketiga: \n";
    for (i = 0; i < baris1; i++)
    {
      for (j = 0; j < kolom2; j++)
      {
        cout << hasil[i][j] << "\t";
      }
      cout << endl;
    }
  }
  cout << endl;
  cout << "Masukkan jumlah baris matriks keempat: ";
  cin >> baris3;
  cout << "Masukkan jumlah baris matriks keempat: ";
  cin >> kolom3;
  cout << endl;
  cout << "Masukkan elemen matrix keempat: " << endl;
  for (int i = 0; i < baris3; ++i)
  {
    for (int j = 0; j < kolom3; ++j)
    {
      cout << "element a" << i + 1 << j + 1 << ": ";
      cin >> matriksawal[i][j];
    }
  }
  cout << endl;
  cout << "matriks keempat semula: " << endl;
  for (int i = 0; i < baris3; ++i)
  {
    for (int j = 0; j < kolom3; ++j)
    {
      cout << " " << matriksawal[i][j];
      if (j == kolom3 - 1)
        cout << endl;
    }
  }
  for (int i = 0; i < baris3; ++i)
    for (int j = 0; j < kolom3; ++j)
    {
      hasiltranspose[j][i] = matriksawal[i][j];
    }
  cout << "matriks keempat setelah transpose :" << endl;
  for (int i = 0; i < kolom3; ++i)
    for (int j = 0; j < baris3; ++j)
    {
      cout << " " << hasiltranspose[i][j];
      if (j == baris3 - 1)
        cout << endl;
    }
  return 0;
}
