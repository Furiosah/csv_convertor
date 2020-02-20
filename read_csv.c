//
//  read_csv.c
//  mini6
//
//  Created by Jiayao Zhang on 2019-03-23.
//  Copyright © 2019 Jiayao Zhang. All rights reserved.
//

#include "read_csv.h"
void read_csv(const char * csv_filename){
    FILE * in;
    char array[1000];
    in=fopen(csv_filename, "rt");
    fgets(array, 999, in);
    while(!feof(in)){
        printf("%s",array);
        fgets(array, 999, in);
    }
    fclose(in);
}
