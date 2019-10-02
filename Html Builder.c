#include <stdio.h>
#include <conio.h>
#define down 80
#define up 72
#define enter 13


void ColorBG(int *arrow, int *key, int *optionsQuant){
system("cls");

while(1){

    puts("\n  Choose a color for background: \n");


    printf(" %s Blue\n", (*arrow == 1) ? "=>" : "  ");
    printf(" %s Red\n", (*arrow == 2) ? "=>" : "  ");
    printf(" %s Yellow\n", (*arrow == 3) ? "=>" : "  ");
    printf(" %s Green\n", (*arrow == 4) ? "=>" : "  ");
    printf(" %s White\n", (*arrow == 5) ? "=>" : "  ");
    printf(" %s Gray\n", (*arrow == 6) ? "=>" : "  ");
    printf(" %s Black\n", (*arrow == 7) ? "=>" : "  ");
    printf(" %s Type one\n", (*arrow == 8) ? "=>" : "  ");

    *key = getch();
    if(*key == down) *arrow = *arrow + 1;
    if(*key == up) *arrow = *arrow - 1;
    if(*arrow > *optionsQuant){*arrow = 1;}
    if(*arrow < 1){*arrow = *optionsQuant;}
    system("cls");
    if(*key == enter){break;}
    }



}

void ColorFont(int *arrow, int *key, int *optionsQuant){
system("cls");

while(1){

    puts("\n  Choose a color for the font: \n");
    printf(" %s Blue\n", (*arrow == 1) ? "=>" : "  ");
    printf(" %s Red\n", (*arrow == 2) ? "=>" : "  ");
    printf(" %s Yellow\n", (*arrow == 3) ? "=>" : "  ");
    printf(" %s Green\n", (*arrow == 4) ? "=>" : "  ");
    printf(" %s White\n", (*arrow == 5) ? "=>" : "  ");
    printf(" %s Gray\n", (*arrow == 6) ? "=>" : "  ");
    printf(" %s Black\n", (*arrow == 7) ? "=>" : "  ");
    printf(" %s Type one\n", (*arrow == 8) ? "=>" : "  ");


    *key = getch();
    if(*key == down) *arrow = *arrow + 1;
    if(*key == up) *arrow = *arrow - 1;
    if(*arrow > *optionsQuant){*arrow = 1;}
    if(*arrow < 1){*arrow = *optionsQuant;}
    system("cls");
    if(*key == enter){break;}
    }



}

int main (){

    char texto[100000];
    char titulo[20];
    FILE *index;
    FILE *css;
    int arrow;
    int optionsQuant;
    int key;
    char iCommas = '"';
    char specialCharKey = '{';
    char specialCharKey2 = '}';
    char barra = '/';

    index = fopen("index.html", "w"); //W = Write

    /*------------------------------------------------
      <head> and title
    ------------------------------------------------*/

    fflush(stdin);
    printf("\n  Type a title for your site: \n   ");
    scanf("%s", &titulo);
    fprintf(index, "<html><head><title>%s</title>", titulo); //Título
    fprintf(index, "<link rel=%cstylesheet%c type=%ctext%ccss%c", iCommas, iCommas, iCommas, barra, iCommas);
    fprintf(index, " href=%cestilo.css%c/>", iCommas, iCommas); //Título
    system("cls");

    /*------------------------------------------------
      <body>
    ------------------------------------------------*/

    fprintf(index, "<body>");

    optionsQuant = 7; //Number of options
    arrow = 1;

    scanf("%*c");
    printf("\n  Digite um texto: \n   ");


    fgets(texto, 100000, stdin);
   // printf("%s", texto);

    fprintf(index, "<h1>%s</h1></body>", texto);
    fclose(index);

    css = fopen("estilo.css", "w");
    fprintf(css, "body%c", specialCharKey);

    optionsQuant = 8; //Number of options
    scanf("%*c");
    ColorBG(&arrow, &key, &optionsQuant);

    if(arrow == 1) {char background[16] = "#66a3ff"; fprintf(css, "background-color: %s; ", background);};
    if(arrow == 2) {char background[16] = "#ff3300"; fprintf(css, "background-color: %s; ", background);};
    if(arrow == 3) {char background[16] = "#ffff80"; fprintf(css, "background-color: %s; ", background);};
    if(arrow == 4) {char background[16] = "#b3ffcc"; fprintf(css, "background-color: %s; ", background);}; //Color From background
    if(arrow == 5) {char background[16] = "#ffffff"; fprintf(css, "background-color: %s; ", background);};
    if(arrow == 6) {char background[16] = "#f0f0f0"; fprintf(css, "background-color: %s; ", background);};
    if(arrow == 7) {char background[16] = "#000000"; fprintf(css, "background-color: %s; ", background);};
    if(arrow == 8) {
            system("cls");
            printf("\n  Type the color (hexacode): \ \n  #");
            char background[16] = "#000000";
            scanf("%s", background);
            fprintf(css, "background-color: #%s; ", background);
    }


    arrow = 1;
    optionsQuant = 8; //Number of options

    ColorFont(&arrow, &key, &optionsQuant);

    if(arrow == 1) {char background[16] = "#66a3ff"; fprintf(css, "color: %s; ", background);}
    if(arrow == 2) {char background[16] = "#ff3300"; fprintf(css, "color: %s; ", background);}
    if(arrow == 3) {char background[16] = "#ffff80"; fprintf(css, "color: %s; ", background);}
    if(arrow == 4) {char background[16] = "#b3ffcc"; fprintf(css, "color: %s; ", background);} //Color From background
    if(arrow == 5) {char background[16] = "#ffffff"; fprintf(css, "color: %s; ", background);}
    if(arrow == 6) {char background[16] = "#f0f0f0"; fprintf(css, "color: %s; ", background);}
    if(arrow == 7) {char background[16] = "#000000"; fprintf(css, "color: %s; ", background);}
    if(arrow == 8) {
            printf("\n  Type the color (hexacode): \ \n  #");
            char background[16] = "#000000";
            scanf("%*c%s", background);
            fprintf(css, "color: #%s; ", background);}



    system("cls");

    fprintf(css, "%c", specialCharKey2);
    fclose(css);


    printf("\n Open the file that was created <%cindex.html%c>\n\n", iCommas, iCommas);

    return(0);
}
