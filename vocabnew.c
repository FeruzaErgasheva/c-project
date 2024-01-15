#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//learning
    // english->uzbek
    //uzbek->english

//training
    //english->uzbek
    //uzbek->english

//hint game
//kartochka


#define max 50

typedef struct Vocabulary{
    char uzbek[max];
    char english[max];
}Vocab;

//learning sectionni tanlasa
void learning(Vocab *v,int lines){
    //tilni tanlidi
    int lang;
    int answer;
    do{
    printf("Siz qanday o'rganmoqchisiz:\n\t1.English->Uzbek\n\t2.Uzbek->English\n");
    scanf("%d",&lang);
    puts("");
    }while(lang!=1 &&lang!=2);
    
        while(1){
            for(int i=0;i<lines;i++){
                if(lang==1){
                    printf("%s\t%s\n",v[i].english,v[i].uzbek);
                    puts("");
                }else if(lang==2){
                    printf("%s\t%s\n",v[i].uzbek,v[i].english);
                    puts("");
                }
                do{
                printf("Bu so'zni o'zlashtrib bo'ldingizmi?:\n1.yes\n2.no\n3.ortga qaytish\nYour answer:");
                scanf("%d",&answer);
                }while(answer!=1&&answer!=2&&answer!=3);
                puts("");
                if(answer==1 && i==lines-1 || answer==3){
                    printf("Siz tizimda mavjud so'zlarni o'rganib bo'ldingiz");
                     return;
                }else if(answer==1 ) {
                     continue;
                }
                    else{
                    i=i-1;
                }
                
            }
        
    }
    printf("Siz tizimda mavjud so'zlarni o'rganib bo'ldingiz!!!\n");
}

//training sectionini tanlaganda chiqadi
void training(Vocab *v,int lines){
    srand(time(0));
    int stop=1;
    int lang;
    char answer[max];
    do{
        printf("Qaysi tartibda practika qilmoqchisiz:\n1.English->Uzbek\n2.Uzbek->English\n");
        scanf("%d",&lang);
        puts("");
    }while(lang!=1&&lang!=2);

    while(stop==1){
        int i=rand()%41;
        if(lang==1){
            printf("%s so'zining ma'nosi nima?\nJavob:",v[i].english);
            scanf("%s",answer);
            if(strcmp(answer,v[i].uzbek)==0){
                printf("Javobingiz to'g'ri!");
            }else{
                printf("Javobingiz noto'gri.To'g'ri javob:%s\n",v[i].uzbek);
            }
            puts("");
            do{
            printf("O'ynni davom ettirasizmi:\n1.ha\t0.yo'q\nJavob:");
            scanf("%d",&stop);
            }while(stop!=0&&stop!=1);
        }else if(lang==2){
            printf("%s so'zining ma'nosi nima?\nJavob:",v[i].uzbek);
            scanf("%s",answer);
            if(strcmp(answer,v[i].english)==0){
                printf("Javobingiz to'g'ri!");
            }else{
                printf("Javobingiz noto'gri.To'g'ri javob:%s",v[i].english);
            }
            puts("");
            do{
            printf("O'ynni davom ettirasizmi:\n1.ha\t0.yo'q\nJavob:");
            scanf("%d",&stop);
            }while(stop!=0&&stop!=1);
        }
    }

}


//hint game sectioni
void hint_game(Vocab *v,int lines){
    int stop=1;
    srand(time(0));
    int a,b,c;
    int answer;
    do{
    printf("Hint game o'yiniga hush kelibsiz! Sizga o'zbek tilida so'z beriladi shu so'zni berilgan hintlarga ko'ra inlizcha tarjimasini topishingiz kerak bo'ladi. Shartlarimiz chunarlimi:\n1.ha\t2.yoq");
    scanf("%d",&answer);
    }while(answer!=1&&answer!=2);
    while(stop==1){
        a=rand()%3;
        b=rand()%5;
        c=rand()%7;
        printf("");
    }
    

}

//hint game
int main(){
    Vocab v[100];
    FILE *file=fopen("vocab.txt","r+");

    //structga filedan sortlab joylash uchun kerak
    int count=0;
    char line[max];
    while(fgets(line,sizeof(line),file)){
        sscanf(line,"%[^ ] %s",v[count].english,v[count].uzbek);
        count++;
    }
  

    //menyu settings
    menu:
    int menyu;
    do{
    printf("Bizning tarjimon sistemamizga xush kelibsiz!!!\nMenyu bo'limidan o'zingizga kerakli bo'limni tanlang:\n\t1.Learning\n\t2.Training\n\t3.Hint game\n");
    scanf("%d",&menyu);
    }while(menyu!=1 && menyu!=2 && menyu!=3);

    //agar 1-sectionni tanlasa
    if(menyu==1){
        learning(v,count);
        goto menu;
    }else if(menyu==2){
        training(v,count);
        goto menu;
    }

    

    return  0;
}