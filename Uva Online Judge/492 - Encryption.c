#include <stdio.h>
#include <string.h>
int main ()
{
    int len1, i, j=0, k=0 ;
    char str[1000], cryp[1000];
    char c, o;
    while (gets(str)){
            k=0;
    for (i=0; i<=strlen(str); i++){
        if (str[i] == 'a' || str[i] == 'i' ||str[i] == 'o' ||str[i] == 'e' ||str[i] == 'u' || str[i] == 'A' || str[i] == 'I' ||str[i] == 'O' ||str[i] == 'E' ||str[i] == 'U' ){
            while (str[i] != ' '){
                        if (str[i]==',' || str[i] == '.' || str[i] =='!'){
                            o = str[i];
                            j=1;
                            i++;
                        }
                    if (str[i] == '\0'){
                        cryp[k++] = 'a';
                        cryp[k++] = 'y';
                        //cryp[k++] = '\0';
                        break;
                    }
                cryp[k] = str[i];
                k++;
                i++;
            }
            cryp[k++] ='a';
            cryp[k++] = 'y';
            if (j==1){
                cryp[k++] =o;
                j=0;
            }
           cryp[k++] = str[i];
        }
         else if ( (str[i] > 'a' &&  str[i] < 'z')||  (str[i] > 'A' &&  str[i] < 'Z')) {
            c = str[i++];
            while (str[i] !=' '){
                    if ( (str[i] < 'a' &&  str[i] > 'z')  &&  (str[i] < 'A' &&  str[i] >'Z')){
                            o = str[i];
                            j=1;
                            i++;
                        }
                 if (str[i] == '\0'){
                        cryp[k++] = c;
                        cryp[k++] = 'a';
                        cryp[k++] = 'y';
                        //cryp[k++] = '\0';
                        break;
                    }
                                cryp[k] = str[i];
                                k++;
                                i++;
                    }
                    cryp[k++] = c;
                    cryp[k++] ='a';
                    cryp[k++] = 'y';
            if (j==1){
                cryp[k++] =o;
                j=0;
            }
                    cryp[k++] = str[i];
                }
    }
    cryp[k++] = '\0';
    printf("%s\n", cryp);
    }
    return 0;
}
