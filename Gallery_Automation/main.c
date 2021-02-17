#include<stdio.h>                       /* Mehmet Aral Isik  */
#include<stdlib.h>
#include<string.h>
#include<locale.h>
typedef struct vututu /* Arac icin bilgi kismi*/
{
    int kod;
    char marka[20];
    char renk[20];
    char tur[20];
    int model;
    int kilometre;
    int papel;
    int hasar;
    int boya;
    int gun;



} Car;
typedef struct adam /* Arac sahibi icin bilgiler */
{
    char isim[20];
    int carsay;
    Car* arabalar;
} Man;

Man* man;

int mansay=0;

void ekleme(char isim[20],int carsay) /* Arac Ekleme*/
{
    if(mansay==0)
    {
        man=(Man*)malloc(sizeof(Man));  /*Hafýza da ilk girilen arac sahibi icin yer acma */
    }
    else
    {
        man=(Man*)realloc(man,sizeof(Man)*(mansay+1));  /* Hafýzadaki yeni girilen arac sahibi kadar arttýrma */
    }
    strcpy((man+mansay)->isim,isim);
    (man+mansay)->carsay=carsay; /* arac sayisi arttirma */

    (man+mansay)->arabalar=(Car*)malloc(sizeof(Car)*carsay); /* Arac sayisi icin yer acma */

    for(int i=0; i<carsay; i++) /* Arac bilgileri alma */
    {
        printf("%d.Arabanin kodu :",i+1);
        scanf("%d",&((man+mansay)->arabalar+i)->kod);
        printf("%d.Arabanin markasi :",i+1);
        scanf("%s",&((man+mansay)->arabalar+i)->marka);
        printf("%d.Arabanin turu :",i+1);
        scanf("%s",&((man+mansay)->arabalar+i)->tur);
        printf("%d.Kac model :",i+1);
        scanf("%d",&((man+mansay)->arabalar+i)->model);

        printf("%d.Arabanin rengi :",i+1);
        scanf("%s",&((man+mansay)->arabalar+i)->renk);
        printf("%d.Kac kilometre :",i+1);
        scanf("%d",&((man+mansay)->arabalar+i)->kilometre);
        printf("%d.Araba kac papel:",i+1);
        scanf("%d",&((man+mansay)->arabalar+i)->papel);
        printf("%d.Araba hasar turu 'Az-1,Cok-2,Hic-3'  :",i+1);
        scanf("%d",&((man+mansay)->arabalar+i)->hasar);
        printf("%d.Araba boyali mi 'evet-1,hayir-2':",i+1);
        scanf("%d",&((man+mansay)->arabalar+i)->boya);



        printf("\n");
    }

    mansay++;   /* bilgi alininca arac sahibi sayisi arttirma */
}
void sanayidurum()  /* Piyasa icin hasar kontrolu ve para durumu */
{   int az_hasar, cok_hasar ,hasarsiz, boyali;
        az_hasar=10000;
        cok_hasar=15000;
        hasarsiz=0;
        boyali=5000;
        int sahibinden=9571,arabam=11387,komisyon=7246;

         for(int i=0; i<mansay; i++)    /* Arac bilgisi getirme */
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
        for(int j=0; j<(man+i)->carsay; j++)    /* Piyasa durumunda hasar durumu ile ilgili fiyatlar */
        {
            printf("%d.Arabanin Az hasarli ve boyali dustugu fiyat:%d \n",j+1,((man+i)->arabalar+j)->papel-az_hasar);
            printf("%d.Arabanin Sahibinden.com kesintili fiyati :%d \n",j+1,((man+i)->arabalar+j)->papel-(az_hasar+sahibinden));
            printf("%d.Arabanin Arabam.com kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(az_hasar+arabam));
            printf("%d.Arabanin Bizim firmanin kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(az_hasar+komisyon));
            printf("\n");
            printf("\n");

            printf("%d.Arabanin Cok hasarli ve boyali dustugu fiyat :%d \n",j+1,((man+i)->arabalar+j)->papel-cok_hasar);
            printf("%d.Arabanin Sahibinden.com kesintili fiyati :%d \n",j+1,((man+i)->arabalar+j)->papel-(cok_hasar+sahibinden));
            printf("%d.Arabanin Arabam.com kesintili fiyati :%d \n",j+1,((man+i)->arabalar+j)->papel-(cok_hasar+arabam));
            printf("%d.Arabanin Bizim firmanin kesintili fiyati :%d \n",j+1,((man+i)->arabalar+j)->papel-(cok_hasar+komisyon));
            printf("\n");
            printf("\n");

            printf("%d.Arabanin Hasarsiz ve boyasiz fiyat:%d \n",j+1,((man+i)->arabalar+j)->papel-hasarsiz);
            printf("%d.Arabanin Sahibinden.com kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(hasarsiz+sahibinden));
            printf("%d.Arabanin Arabam.com kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(hasarsiz+arabam));
            printf("%d.Arabanin Bizim firmanin kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(hasarsiz+komisyon));
            printf("\n");
            printf("\n");

            printf("%d.Yalnizca Boyali  dustugu fiyat:%d \n",j+1,((man+i)->arabalar+j)->papel-boyali);
            printf("%d.Sahibinden.com kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(boyali+sahibinden));
            printf("%d.Arabam.com kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(boyali+arabam));
            printf("%d.Bizim firmanin kesintili fiyati:%d \n",j+1,((man+i)->arabalar+j)->papel-(boyali+komisyon));
            printf("\n");
            printf("\n");

        }
    }

}

void herseyortada() /* Listeleme */
{
    for(int i=0; i<mansay; i++)
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);  /* Bilgileri ekrana verme kismi */
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
        for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin kodu :%d \n",j+1,((man+i)->arabalar+j)->kod);
            printf("%d.Arabanin markasi :%s \n",j+1,((man+i)->arabalar+j)->marka);
            printf("%d.Arabanin turu:%s \n",j+1,((man+i)->arabalar+j)->tur);
            printf("%d.Arabanin modeli:%d \n",j+1,((man+i)->arabalar+j)->model);
            printf("%d.Arabanin rengi :%s \n",j+1,((man+i)->arabalar+j)->renk);
            printf("%d.Kac kilometre:%d \n",j+1,((man+i)->arabalar+j)->kilometre);
            printf("%d.Araba kac papel:%d \n",j+1,((man+i)->arabalar+j)->papel);
            printf("%d.Araba hasar turu 'Az-1,Cok-2,Hic-3':%d\n",j+1,((man+i)->arabalar+j)->hasar);
            printf("%d.Araba boyali mi 'evet-1,hayir-2':%d\n",j+1,((man+i)->arabalar+j)->boya);


            printf("\n");
        }
    }
}
void yabanciturist()    /* Turistler icin imkanlar*/
{   int gun;
    printf("Gun Seciniz '1-2-3-4-5-6-7' :");
            scanf("%d",&gun);
    if(gun==1)
        {printf("Sadece 1000 lira karsiliginda 1 gece konaklama + surus imkani- REZERVASYON NO:0555 555 55 55\n");
        for(int i=0; i<mansay; i++) /*Kisinin arac bilgisi*/
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
        for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin yeni bedeli:%d \n",j+1,((man+i)->arabalar+j)->papel+1000);
        }
    }
        }
    else if(gun==2)
    {
         printf("Sadece 1150 lira karsiliginda 2 gece konaklama + surus imkani- REZERVASYON NO:0555 555 55 55\n");
         for(int i=0; i<mansay; i++)    /*Kisinin arac bilgisi*/
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
         for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin yeni bedeli:%d \n",j+1,((man+i)->arabalar+j)->papel+1150);
        }
    }
    }
    else if(gun==3)
    {
        printf("Sadece 1280 lira karsiliginda 3 gece konaklama + surus imkani- REZERVASYON NO:0555 555 55 55\n");
        for(int i=0; i<mansay; i++) /*Kisinin arac bilgisi*/
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
        for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin yeni bedeli:%d \n",j+1,((man+i)->arabalar+j)->papel+1250);
        }
    }
    }
    else if(gun==4)
        {
            printf("Sadece 1390 lira karsiliginda 4 gece konaklama + surus imkani- REZERVASYON NO:0555 555 55 55\n");
            for(int i=0; i<mansay; i++) /*Kisinin arac bilgisi*/
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
            for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin yeni bedeli:%d \n",j+1,((man+i)->arabalar+j)->papel+1390);
        }
        }
        }
    else if(gun==5)
        {
            printf("Sadece 1500 lira karsiliginda 5 gece konaklama + surus imkani- REZERVASYON NO:0555 555 55 55\n");
            for(int i=0; i<mansay; i++) /*Kisinin arac bilgisi*/
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
            for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin yeni bedeli:%d \n",j+1,((man+i)->arabalar+j)->papel+1500);
        }
        }
        }
    else if(gun==6)
        {
            printf("Sadece 1610 lira karsiliginda 6 gece konaklama + surus imkani- REZERVASYON NO:0555 555 55 55\n");
            for(int i=0; i<mansay; i++) /*Kisinin arac bilgisi*/
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
            for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin yeni bedeli:%d \n",j+1,((man+i)->arabalar+j)->papel+1610);
        }
        }
        }
    else if(gun==7)
        {
            printf("Sadece 1720 karsiliginda 7 gece konaklama + surus imkani- REZERVASYON NO:0555 555 55 55\n");
            for(int i=0; i<mansay; i++) /*Kisinin arac bilgisi*/
    {
        printf("%d.Araba sahibinin adi :%s \n",i+1,(man+i)->isim);
        printf("Araba sayisi:%d \n",(man+i)->carsay);
        printf("\n");
            for(int j=0; j<(man+i)->carsay; j++)
        {
            printf("%d.Arabanin yeni bedeli:%d \n",j+1,((man+i)->arabalar+j)->papel+1720);
        }
        }
        }
    else
        printf("Lutfen 1-7 arasi secim yapiniz.\n");
        return gun;

}

void silme(int carshb) /* Silme islemi direk arac sahibini siliyor, arac sahibinin secilen arabasini sildirme kismini yapamadim bir turlu */
{
    if(carshb<=0||carshb>mansay){
        printf("Boyle bir arac ve sahibi sahibi yok.\n");
    }else{

        for(int i=carshb;i<mansay;i++){ /* Secilen numaralý arac sahibini siliyor, bos yere ilerdekiler geri geliyor anlatmislardi 1 2 3 4 5 - 1 2 <- 4 5 - 1 2 3 4 */
            *(man+(i-1))=*(man+i);
        }
        mansay--;
        man=(Man*)realloc(man,sizeof(Man)*mansay); /* adam silindigi icin yer duzenlemesi yapiliyor*/
    }
}


void degistirme(int carshb){    /* Guncelleme*/
     if(carshb<=0||carshb>mansay){
        printf("Boyle bir arac sahibi bulunmamaktadir..");
    }else{
        printf("Guncellenecek arac sahibinin araba bilgileri:\n");    /* Arac sahipleri ve bilgileri geliyor*/
        for(int i=0;i<(man+(carshb-1))->carsay;i++){
            printf("%d.Arabanin kodu :%d\n",i+1,(((man+(carshb-1))->arabalar)+i)->kod);
            printf("%d.Arabanin markasi:%s\n",i+1,(((man+(carshb-1))->arabalar)+i)->marka);
            printf("%d.Arabanin turu:%s\n",i+1,(((man+(carshb-1))->arabalar)+i)->tur);
            printf("%d.Arabanin modeli:%d\n",i+1,(((man+(carshb-1))->arabalar)+i)->model);
            printf("%d.Arabanin rengi:%s\n",i+1,(((man+(carshb-1))->arabalar)+i)->renk);
            printf("%d.Arabanin kilometresi:%d\n",i+1,(((man+(carshb-1))->arabalar)+i)->kilometre);
            printf("%d.Arabanin fiyati:%d\n",i+1,(((man+(carshb-1))->arabalar)+i)->papel);
            printf("%d.Araba hasar turu 'Az-1,Cok-2,Hic-3':%d\n",i+1,(((man+(carshb-1))->arabalar)+i)->hasar);
            printf("%d.Araba boyali mi 'evet-1,hayir-2':%d\n",i+1,(((man+(carshb-1))->arabalar)+i)->boya);
            printf("\n");
        }
        printf("Kacinci arabayi guncellemek istiyorsunuz?");
        int maraba;
        scanf("%d",&maraba);

        if(maraba<=0||maraba>(man+(carshb-1))->carsay){
            printf("Boyle bir arac bulunmamaktadir..");
        }else{
            printf("%d.Arabanin yeni kodu:",carshb); /* Ýcindekileri kendi yazdiklarimiz ile degistiriyor*/
            scanf("%d",&(((man+(carshb-1))->arabalar)+(maraba-1))->kod);
            printf("%d.Arabanin yeni markasi:",carshb);
            scanf("%s",&(((man+(carshb-1))->arabalar)+(maraba-1))->marka);
            printf("%d.Arabanin yeni turu:",carshb);
            scanf("%s",&(((man+(carshb-1))->arabalar)+(maraba-1))->tur);
            printf("%d.Arabanin yeni modeli:",carshb);
            scanf("%d",&(((man+(carshb-1))->arabalar)+(maraba-1))->model);
            printf("%d.Arabanin yeni rengi:",carshb);
            scanf("%s",&(((man+(carshb-1))->arabalar)+(maraba-1))->renk);
            printf("%d.Arabanin yeni kilometresi:",carshb);
            scanf("%d",&(((man+(carshb-1))->arabalar)+(maraba-1))->kilometre);
            printf("%d.Arabanin yeni parasi:",carshb);
            scanf("%d",&(((man+(carshb-1))->arabalar)+(maraba-1))->papel);
            printf("%d.Arabanin yeni hasar turu 'Az-1,Cok-2,Hic-3':",carshb);
            scanf("%d",&(((man+(carshb-1))->arabalar)+(maraba-1))->hasar);
            printf("%d.Arabanin yeni boya turu 'evet-1,hayir-2':",carshb);
            scanf("%d",&(((man+(carshb-1))->arabalar)+(maraba-1))->boya);

        }
    }
}

int main()
{


    int secimasamasi;
    int sureklilik=1;
    while(sureklilik) /* Menunun surekli hale gelmesi icin*/
    {
        printf("1.Ekleme\n2.Silme\n3.Arac Guncelleme\n4.Listeleme\n5.Yabanci Turist imkani\n6.Piyasa Durumu\n0.Cikis\n");
        printf("===>");
        scanf("%d",&secimasamasi);
        char isim[20];
        int carsay;
        int carshb;
        switch(secimasamasi) /* Menude sectigimiz case e giriyor*/
        {
        case 1:/*Ekleme yapma*/
            printf("Eklemek istediginiz arac sahibinin ismi nedir?: ");
            scanf("%s",isim);
            printf("%s adli arac sahibinin kac arabasi var?: ",isim);
            scanf("%d",&carsay);
            ekleme(isim,carsay);

            break;
        case 2:/* Silme*/
            printf("Kacinci arac sahibini silmek istiyorsunuz?");
            scanf("%d",&carshb);
            herseyortada();
            silme(carshb);
            break;
        case 3:/*Guncelleme*/
            printf("Kacinci arac sahibini guncellemek istiyorsunuz?");
            scanf("%d",&carshb);
            degistirme(carshb);

            break;
        case 4:/*Listeleme*/
            herseyortada();

            break;
        case 5:/*yabanci turist imkani*/
            yabanciturist();

            break;
        case 6:/*Piyasa hasar kontrol*/
            sanayidurum();
            break;
        case 0:/*cikis kismi*/
            sureklilik=0;
            break;

        default:
            printf("Yanlis secim");
        }
        printf("devam etmek icin bir tusa basiniz..");
        getch();
        system("cls");/* her menuye donuste o ana kadar olan gereksiz kismi siliyor*/
    }


    return 0;
}
                                                                                /*Mehmet Aral Isik*/
