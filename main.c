#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char dataArray[10][500];
    FILE *dataFile;
    dataFile = fopen("CustomerData.txt", "r");


    for (i = 0; i < 8;){
        for (j = 0; j < 10; j++){
            fscanf(dataFile, "%s", &dataArray[i][j]);
            if(dataArray[i][j] == "/n"){
                i++;
        }
    }
}
fclose(dataFile);
for(i = 0; i < 10; i++){
    printf("%s", dataArray[i]);
}
}
