//
//  main.c
//  mini6
//
//  Created by Jiayao Zhang on 2019-03-23.
//  Copyright © 2019 Jiayao Zhang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "convert_to_csv.h"
#include "read_csv.h"
void find_name(const char * csv_filename,const char* name){
    char array[1000];
    FILE * fp;
    //char str[100];
    int i,j;
    int cnt=0;
    int found=0;
    fp=fopen(csv_filename,"rt");
    fgets(array,999,fp);
    while(!feof(fp)){
        fgets(array,999,fp);
    }//copy file into array
    for(i=0;i<strlen(array)-strlen(name);i++){//loop through array
        found=1;
        for(j=0;j<strlen(name);j++){
            if(array[i + j] != name[j])
            {//check char by char
                found = 0;
                break;
            }
        }
        if(found == 1)
        {//only if matches all, it gives 1
            printf("%s\n", name);
            cnt++;//a method to check occurence, found is not useful, it always ends at 0
        }
    }
    if(cnt==0){
        printf("Name not found\n");
    }
    fclose(fp);
    
}

void add_record(const char* csv_filename,const char* name,const int age, const char* city){
    FILE * csv;
    //char tmp[1000];
    csv=fopen(csv_filename, "at");
    //sprintf(tmp, "%s,%d,%s",name,age,city);
    //printf("%s", tmp);
    fprintf(csv,"%s,%d,%s\n",name, age, city);
    fclose(csv);
}
int find_line(const char * csv_filename,const char * str){
    FILE *fp;
    int count = 1;  // Line counter (result)
    char buf[1000];

    // Open the file
    fp = fopen(csv_filename, "rt");
    
    
    // Extract characters from file and store in character c
    fgets(buf,999,fp);
    while(!feof(fp)){
        if(strstr(buf,str)==0){
            count++;
            fgets(buf,999,fp);
        }else{
            return count;
        }
        
        
    }
    // Close the file
    fclose(fp);
    return count;
}
void delete_record(const char * csv_filename,const char* name){
    FILE *old, *new;
    char buf[1000];
    int i=1;
    int status;
    int line=find_line(csv_filename, name);
    char * token;
    old=fopen(csv_filename,"rt");
    new=fopen("tmp.csv","wt");
    token=fgets(buf,999,old);
    while(!feof(old)){
        if(i!=line){
            fputs(token, new);
        }
        token=fgets(buf,999,old);
        i++;
    }

    status=remove(csv_filename);
    status=rename("tmp.csv", "output.csv");
    fclose(old);
    fclose(new);


}
int main(){
    load_and_convert("input.txt");
    read_csv("output.csv");
    printf("\n");

    find_name("output.csv","Maria");
    printf("\n");
    find_name("output.csv","Jason");
    printf("\n");
    add_record("output.csv","Jason",36,"Skookumchuk");
    read_csv("output.csv");
    printf("\n");

    delete_record("output.csv", "Maria");
    read_csv("output.csv");
    printf("\n");
    
    return 0;
}
