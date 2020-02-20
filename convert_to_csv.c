//
//  convert_to_csv.c
//  mini6
//
//  Created by Jiayao Zhang on 2019-03-21.
//  Copyright © 2019 Jiayao Zhang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE * fp, * csv;
void load_and_convert(const char* filename){
    char name[1000],age[1000],address[1000];
    char *token1,*token2,*token3;
    char *tmp[50];
    int cnt=0;
    fp=fopen(filename, "rt");
    csv=fopen("output.csv","wt");
    fgets(name,999,fp);
    fgets(age,999,fp);
    fgets(address,999,fp);//the way on slides
    //use strtok to extract pieces of strings. strtok replaces " " by \0, therefore fprintf will stop at different pieces.
    //i use 3 different while loops as strtok functions will not run at the same time.
    token1=strtok(name," \n");
    while(token1!=NULL){
        tmp[cnt]=token1;
        cnt=cnt+3;//here, i put strings of names at position[0] [3] [7]etc, and age at [1][4]..etc
        token1=strtok(NULL," \n");
    }
    cnt=1;
    token2=strtok(age," \n");
    while(token2!=NULL){
        tmp[cnt]=token2;
        cnt=cnt+3;
        token2=strtok(NULL," \n");
    }
    cnt=2;
    token3=strtok(address," \n");
    while(token3!=NULL){
        tmp[cnt]=token3;
        cnt=cnt+3;
        token3=strtok(NULL," \n");
    }
    //printf("%s",tmp[14]);
    //printf("%d",cnt);
    

    int j=0;//same way as how I put it in.
    while(j<cnt-3){
        fprintf(csv, "%s,%s,%s\n",tmp[j],tmp[j+1],tmp[j+2]);
        j=j+3;
    }

    fclose(fp);
    fclose(csv);
}
