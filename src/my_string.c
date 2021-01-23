#include"../include/my_string.h"
#include<string.h>
#include<stdlib.h>
char * my_strcat(char * s1[], int n){
    int s_n = 0;
    for(int i=0;i<n;i++){
        s_n+=strlen(s1[i]);
    }
    char * s = (char *)malloc(s_n+1);
    int s_i = 0;
    char x;
    for(int i=0;i<n;i++){
        for(int j=0;s1[i][j]!='\0';j++){
            s[s_i++] = s1[i][j];
        }
    }
    s[s_i] = '\0';
    return s;
}

