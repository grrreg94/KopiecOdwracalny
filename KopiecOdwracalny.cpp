// KopiecOdwracalny.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <algorithm>
using namespace std;
//------------------------------------------------------------------------------------------
void Przywrc(int poz2, int tab[], int poz, bool s)
{
	int i = poz2;


	if (s)
	{
		int L = 2 * i, P = 2 * i + 1;
		int najw;
		if (L <= poz && *(tab + i - 1) < *(tab + L - 1))
			najw = L;
		else
			najw = i;

		if (P <= poz && *(tab + najw - 1) < *(tab + P - 1))
			najw = P;


		if (najw != i)
		{
			swap(*(tab + i - 1), *(tab + najw - 1));
			Przywrc(najw, tab, poz, s);
		}

	}

	else
	if (i >= 0)
	{

		int L = 2 * i, P = 2 * i + 1;
		int najn;
		if (L <= poz && *(tab + i - 1) > *(tab + L - 1))
			najn = L;
		else
			najn = i;

		if (P <= poz && *(tab + najn - 1) > *(tab + P - 1))
			najn = P;


		if (najn != i)
		{
			swap(*(tab + i - 1), *(tab + najn - 1));
			Przywrc(najn, tab, poz, s);

		}
	}
}

//------------------------------------------------------------------------------------------

	void Wyswietl(int tab[], int poz)
	{
		for (int i = 0; i < poz ; i++)
			cout << *(tab + i) << " ";
	}
//------------------------------------------------------------------------------------------

	int UsunTop(int tab[], int pozycja, bool s, bool c)
	{
		if (pozycja == 0)
			return pozycja;

		if (c)
		cout << *(tab) << " ";

		*(tab) = *(tab + pozycja - 1);
		*(tab + pozycja - 1) = -1;
		pozycja-- ;

		for (int n = pozycja / 2; n > 0; n--)
		{
			Przywrc(n, tab, pozycja, s);
		}

		return pozycja;
	}
//------------------------------------------------------------------------------------------



//========================================== M A I N =================================================================

int main()
{
		int tab[65535];
		int i = 0, pozycja = 0, k;

		char ctab[65535], *p;

		bool b1, s = true, c = true;



while (fgets(ctab, 65535, stdin))
{

	for (p = ctab; p < p + (sizeof ctab); p++)
			{

				if (*p == '\n' || b1 == true)
				{
					b1 = false;
					break;
				}


//========================================= S W I T C H ===============================================================
				switch (*p)
				{

//--------case '+':-------------------------------------------------------------------------------------------------------------
				case '+':
					p++;

					if (*p == '\n')
					{
						b1 = true;
						break;
					}

					p++;

					if (*p >= '0' && *p <= '9')
					{
						if (*p >= '0' && *p <= '9')
						{

							i = *p - 48;

							while (*(p + 1) >= '0' && *(p + 1) <= '9')
							{
								i = i * 10 + (*(p + 1) - 48);
								p++;
							}
							tab[pozycja] = i;
							pozycja++;
						}
					
					}

					for (int n = pozycja / 2; n > 0; n--)
					{
						Przywrc(n, tab, pozycja, s);
					}

					b1 = true;
					break;

//---------case '-':------------------------------------------------------------------------------------------------------------
				case '-':
					pozycja = UsunTop(tab, pozycja, s, c);
					break;
//---------case 'p':------------------------------------------------------------------------------------------------------------
				case 'p':

					Wyswietl(tab, pozycja);
					break;

//---------case 'r':------------------------------------------------------------------------------------------------------------
				case 'r':
					c = false;

					while (pozycja) 
					{ pozycja = UsunTop(tab, pozycja, s, c); }

					p++;

					if (*p == ' ')
						p++;

					k = *p - 48; while (*(p + 1) >= '0' && *(p + 1) <= '9')
					{
						k = k * 10 + (*(p + 1) - 48); p++;
					}

					 while (*p != '\n')

					{
						p++;
						if (*p >= '0' && *p <= '9')
						{
							
							i = *p - 48;

							while (*(p + 1) >= '0' && *(p + 1) <= '9')
							{
								i = i * 10 + (*(p + 1) - 48);
								p++;
							}
							tab[pozycja] = i;
							pozycja++;
						}
						
					}
					 for (int n = pozycja / 2; n > 0; n--)
					 {
						 Przywrc(n, tab, pozycja, s);
					 }

					b1 = true;
					c = true;
					break;

//-----------case 's':----------------------------------------------------------------------------------------------------------
				case 's':
					if (s)
						s = false;
					else
						s = true;

						for (int n = pozycja / 2; n > 0; n--)
						{
							Przywrc(n, tab, pozycja, s);
						}
					break;
//-----------case 'q':----------------------------------------------------------------------------------------------------------
				case 'q':
					return 0;
				}
//========================================= S W I T C H   E N D ===============================================================
			}
		}

		return 0;
	}

