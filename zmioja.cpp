#include<iostream>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool igra = true;
int x = 0, y = 1;
short sadx = 4, sady = 0;
short polje_broj[10][10];
short velicina = 3, xh, yh;
bool pojeden = true;

void obrada(){
		while(igra){
         	if( (GetAsyncKeyState( 'A' ) & 0x8000) && !( x== 0 && y == 1)){
                	x = 0;
                	y = -1;
         	}
         	else if( (GetAsyncKeyState( 'W' ) & 0x8000) && !(x == 1 && y == 0)){
                	x = -1;
               		y = 0;
         	}
         	else if( (GetAsyncKeyState( 'D' ) & 0x8000) && !(x == 0 && y == -1)){
            	    x = 0;
            	    y = 1;
         	}
         	else if( (GetAsyncKeyState( 'S' ) & 0x8000) && !(x == -1 && y == 0)){
                	x = 1;
            	    y = 0;
        	}
        	Sleep(100);
     	}
}

void crtaj(){
	while(igra){
		system("cls");
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10 ; j++){
				if(polje_broj[i][j] != 0){
					cout << (char)254;
					polje_broj[i][j]++;
					if(polje_broj[i][j] > velicina)
						polje_broj[i][j] = 0;
					}
				else if((i == xh && j == yh))
					cout << 'O';
				else{
					cout<< " ";
				}
				if(j == 9)
					cout << endl;
			}
		Sleep(200);
	}
}


int main(){
    thread t1(obrada);
    thread t2(crtaj);
    srand(time(0));
    rand();
    while(igra){
    	if(pojeden){
    		xh = rand()%10;
    		yh = rand()%10;
    		while(polje_broj[xh][yh] != 0){
			    xh = rand()%10;
    			yh = rand()%10;
				}
			pojeden = false;
		}
        sadx = (sadx + x)%10;
        sady = (sady + y)%10;
        if(sadx < 0)
    		  	sadx = 9;
		    if(sady < 0)
    				sady = 9;
    if(sadx == xh && sady == yh){
			pojeden = true;
			velicina++;
		}
        if(polje_broj[sadx][sady] != 0)
        	igra = false;
        else
        	polje_broj[(sadx)][(sady)] = 1;
        Sleep(200);
    }
    t1.join();
    t2.join();
    system("Pause");
    return 0;
}
