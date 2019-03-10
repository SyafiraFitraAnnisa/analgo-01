#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 

// Jumlah pasangan
#define N 5

// Fungsi ini akan mengeluarkan nilai true jika cewek w lebih suka cowok m1 dari pada m 
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1) 
{ 
 for (int i = 0; i < N; i++) 
 { 
  // jika m1 datang lebih dulu, maka bernilai true, dan w berpasangan dengan m1
  if (prefer[w][i] == m1) 
   return true; 

  // jika m datang lebih dulu, maka w putus dengan m1, dan berpasangan dengan m
  if (prefer[w][i] == m) 
  return false; 
 } 
} 

// cowok diwakilkan dengan angka 0 sampai N-1. cewek diwakilkan angka N sampai 2N-1
void stableMarriage(int prefer[2*N][N]) 
{ 
	
 // menyimpan pasangan cewek
 int wPartner[N]; 

 // array untuk menyimpan ketersediaan cowok
 bool mFree[N]; 

 // menginisiasi semua cowok dan cewek tidak berpasangan
 memset(wPartner, -1, sizeof(wPartner)); 
 memset(mFree, false, sizeof(mFree)); 
 int freeCount = N; 

 // Wketika ada cowok tidak berpasangan
 while (freeCount > 0) 
 { 
  // pilih cowok pertama yg tidak berpasangan
  int m; 
  for (m = 0; m < N; m++) 
   if (mFree[m] == false) 
    break; 

   // satu persatu pasangkan cowok dengan cewek
   // m adalah cowok yang tidak berpasangan
  for (int i = 0; i < N && mFree[m] == false; i++) 
  { 
   int w = prefer[m][i]; 

   // jika cewek ada yg tidak berpasangan, maka w dan m jadi pasangan
   if (wPartner[w-N] == -1) 
   { 
    wPartner[w-N] = m; 
    mFree[m] = true; 
    freeCount--; 
   } 

   else // jika w telah berpasangan
   { 
    // temukan pasangan w saat ini 
    int m1 = wPartner[w-N]; 

	// jika w lebih menyukai m dari pada m1 yang pasangannya saat ini,
	// maka putuskan w dan m1, kemudian pasangkan w dengan m
    if (wPrefersM1OverM(prefer, w, m, m1) == false) 
    { 
     wPartner[w-N] = m; 
     mFree[m] = true; 
     mFree[m1] = false; 
    } 
   } 
  } 
 } 


 // Print hasil pasangannya
 cout << "Woman Man" << endl; 
 for (int i = 0; i < N; i++) 
 cout << " " << i+N << "\t" << wPartner[i] << endl; 
} 


int main() 
{ 
 int prefer[2*N][N] = { 
		{6, 5, 8, 9, 7},      
        {8, 6, 5, 7, 9},      
        {6, 9, 7, 8, 5},      
        {5, 8, 7, 6, 9},     
        {6, 8, 5, 9, 7},      
        {4, 0, 1, 3, 2},      
        {2, 1, 3, 0, 4},      
        {1, 2, 3, 4, 0},      
        {0, 4, 3, 2, 2},      
        {3, 1, 4, 2, 0} 
 }; 
 
 /* Keterangan angka
    Laki            Perempuan
    0.Victor        5.Amy
    1.Wyatt         6.Bertha
    2.Xavier        7.Clare
    3.Yancey        8.Diane
    4.Zeus          9.Erika
    */
 stableMarriage(prefer); 

 return 0; 
}