#include <stdio.h>
#include <string.h>


typedef struct vocabulary{
    char english[30];
    char uzbek[30];
    char russian[30];

}vocab;


int main(){
    vocab v[100];
    FILE *file=fopen("vocab.txt","r+");
    char line[100];
    int count=0;
    int lines=0;
    //filedagi sozlarni saralab structga joylaydi
        while(fgets(line,sizeof(line),file)){
            sscanf(line,"%[^ ] %[^ ] %s",v[count].english,v[count].uzbek,v[count].russian);
            count++;
            lines++;
        } 
        
    //language setting
    // int language;
    // printf("Qaysi modeni tanlaysiz:\n1.English->Uzbek\n2.Uzbek->English:");
    // puts("");
    // scanf("%d",&language);
    // if(language==1){
    //     goto english_uzbek;
    // }else if(language==2){
    //     goto uzbek_english;
    // }

    //ingliz tilidan ozbek tiliga tarjia
    // char word[10];
    // int k=0;
    // english_uzbek:
    //         scanf("%s",word);
    //         while(strcmp(word,"stop")!=0){
    //             for(int i=0;i<lines;i++){
    //                 k=0;
    //                 if(strcmp(word,v[i].english)==0){
    //                     printf("%s\t%s\n",v[i].english, v[i].uzbek);
    //                     k++;
    //                     break;
    //                 }
    //             }
    //             if(k==0){
    //                 printf("siz kiritgan soz mavjud emas\n");
    //             }
    //             scanf("%s",word);
    //         }

    //uzbek tilidan ingliz tiliga tajima qiladi
    // uzbek_english:
    char word[30];
int k;
           scanf("%s",word);
            while(strcmp(word,"stop")!=0){
                for(int i=0;i<lines;i++){
                    k=0;
                    if(strcmp(word,v[i].uzbek)==0){
                        printf("%s\t%s\n",v[i].uzbek, v[i].english);
                        k++;
                        break;
                    }
                }
                printf("%d",k);
                if(k==0){
                    printf("The searching word doesn't exist\n");
                }
                scanf("%s",word);
            }

   
}