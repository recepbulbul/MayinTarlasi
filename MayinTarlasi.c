#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haritayazdir(char harita[9][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%c ",harita[i][j]);
        }
        printf("\n");
    }
    

}
void haritayazdirint(int harita[11][11]){
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            printf("%d ",harita[i][j]);
        }
        printf("\n");
    }
    

}

void mayinac(int bomb[11][11] ,char harita[9][9],int satir,int sutun){
    int sayac = 0;
    if (bomb[satir][sutun]==1)
    {
        harita[satir-1][sutun-1] = 'B';
        
    }
    else{
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (bomb[satir-1+i][sutun-1+j] == 1)
                {
                    sayac++;
                }
                
            }
            
        }
        harita[satir - 1][sutun - 1] = (sayac == 0) ? ' ' : (char)(sayac + '0');
    }
    

}

int main(){
    char harita[9][9];
    int bomb[11][11];
    int satir,sutun;
    srand(time(NULL));
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            bomb[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < 15; i++)
    {
        int satirrand= rand()%9+1;
        int sutunrand = rand()%9+1;
        bomb[satirrand][sutunrand] = 1;
    }
    haritayazdirint(bomb);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            harita[i][j] = '*';
        }
        
    }
    while (1)
    {
        haritayazdir(harita);

        printf("Satir ve Sutun Giriniz: \n");
        scanf("%d%d",&satir,&sutun);

        mayinac(bomb,harita,satir,sutun);
        if (harita[satir-1][sutun-1] == 'B')
        {

            haritayazdir(harita);
            printf("LOSE");
            break;
            
        }

    }
    
    

    return 0;
}