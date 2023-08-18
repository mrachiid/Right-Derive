#include<stdio.h> 
#include<stdlib.h>
#include<string.h> // biblio de chaine de caractere
#include<math.h>
#include<conio.h> // getch
#define pi 3.141592654

int Menu()
{
		system("cls"); //efface l'้cran
		printf("             ษออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("             บ                                                      บ\n");
		printf("             บ                    Menu Principal                    บ\n");
		printf("             บ                                                      บ\n");
		printf("             ศออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        printf("\n           pour calculer le derive d''un function  taper f'(X0)        ");
		printf("\n           taper exit pour arreter le programme                       ");
		printf("\n\n\n\n\n>>");
		getch();			// entrer un caractere
		system("cls");
}
//effacer espace
  void removeSpaces(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')								
            str[count++] = str[i];                        
    str[count] = '\0';
}
// dimension
int taille(char *p){
	int i;
		for(i=0;p[i]!='\0';i++){}				
		return i;
}
//existance d'un nombre
bool isExistNombre(char * p){
	char t[30];
	strcpy(t,p);
	strtok(t,"(");							
	int i=taille(t)+1;
	while(p[i]!='\0'){
		if(p[i]-'0'<0 ||p[i]-'0'>9) return false;
		i++;
	}
	return true;	
}
//// convertir nombre entier
double movenbre(char *p){
	 double n=0;
		char t[30];
	strcpy(t,p);
	strtok(t,"(");							
	int i=taille(t)+1;
 	int toto=taille(p)-i-1;
	while(p[i]!='\0'){
n=n+(double)(p[i]-'0')*pow(10,toto);
	toto--;
	i++;
	}
return n;
}

float derive(double (*f)(double), double x0)
{
    const double delta = 1.0e-6;
    double x1 = x0 - delta;
    double x2 = x0;
    double y1 = f(x1);
    double y2 = f(x2);
    return  (float)((y2 - y1) / (delta));
}
//pour verifie est ce que le cara avant dernier est ')'
bool ifContParenFin(char *p){
	removeSpaces(p);								
	return p[taille(p)-1]==')';
}
///couper la chaine jusqu'a le char ')'
 void removeParantFin(char *p){
strtok(p,")");										
}
//pour verifie est ce que le chaine est contient le char '('
bool isContparentsDebu( char *p){
	int i,taill;
	taill=taille(p);							
for(i=0;i<taill;i++){								
		if(p[i]=='(') return true;
	}
	return false;
}
///existance de virgule
bool ifcontvergir(char *p){
	int i=0,taill;
	taill=taille(p);
for(i=0;i<taill;i++){								
		if(p[i]=='.') return true;
	}
	return false;
}
///convertir la partie entier d'un nombre decimal 
double movepartieintier(char *p){
	char z[100];
	strcpy(z,p);
	strtok(z,".");						
if(isExistNombre(z))
return 	movenbre(z);
else return -500000;
}
///inverse un tableau
void inverse(char *p){
	int i=0,j=taille(p)-1;
	char tmp;
	while(i<j){
		tmp=p[i];						
		p[i]=p[j];
		p[j]=tmp;
		i++;
		j--;
	}
}
///convertir la partie decimal 
float movepartiedicimale(char*p){
	char tab[100],tt[100]="f(";
	 int j=0;
	for(int i=taille(p)-1;p[i]!='.';i--){			/// tab = ) nbr decimaux
		tab[j]=p[i];									
		j++;
	}
	inverse(tab);									
	for(int i=0;i<taille(tab);i++){						///tt = f(partie decimal)
		tt[2+i]=tab[i];
	}
	if(isExistNombre(tt)){								
	float y=movenbre(tt);								/// verifie est ce que un nombre + prend la ็a valeur
	return y*pow(10,-taille(tab));
	}
	else return -500000;
}
/// traitement partie entier
void traimententier(char *p){
	bool x=isContparentsDebu(p)&&ifContParenFin(p);
	removeParantFin(p);	
if( x&& isExistNombre(p)){
	char  z[100];
	strcpy(z,p);
	strtok(p,"(");
double y=movenbre(z);   
if((p[0]=='s'||p[0]=='S') &&(p[1]=='i'||p[1]=='I')&& (p[2]=='n'||p[2]=='N') &&p[3]=='\''){
float der =derive(sin,y);
printf("Sin'(%f)=%f\n",y,der);					////sin
}
else if((p[0]=='c'||p[0]=='C') &&(p[1]=='o'||p[1]=='O')&& (p[2]=='s'||p[2]=='S') &&p[3]=='\''){
	float der =derive(cos,y);
printf("Cos'(%f)=%f\n",y,der);								////cos
}
else if((p[0]=='e'||p[0]=='E') &&(p[1]=='X'||p[1]=='x')&& (p[2]=='p'||p[2]=='P') &&p[3]=='\''){
		float der =derive(exp,y);
printf("exp'(%f)=%f\n",y,der);							///exp
}
else if((p[0]=='l'||p[0]=='L') &&(p[1]=='o'||p[1]=='O')&& (p[2]=='G'||p[2]=='g') &&p[3]=='\''){
		float der =derive(log,y);
printf("Log'(%f)=%f\n",y,der);							///ln
}
else if((p[0]=='t'||p[0]=='T') &&(p[1]=='a'||p[1]=='A')&& (p[2]=='n'||p[2]=='N') &&p[3]=='\''){
		float der =derive(tan,y);
printf("Tan'(%f)=%f\n",y,der);										////tan
}
else if((p[0]=='s'||p[0]=='S') &&(p[1]=='i'||p[1]=='I')&& (p[2]=='n'||p[2]=='N') && (p[3]=='H'||p[3]=='h') &&p[4]=='\''){	
float der =derive(sinh,y);
printf("Sinh'(%f)=%f\n",y,der);          						///sinh
}
else if((p[0]=='c'||p[0]=='C') &&(p[1]=='o'||p[1]=='O')&& (p[2]=='s'||p[2]=='S') && (p[3]=='H'||p[3]=='h') &&p[4]=='\''){
	float der =derive(cosh,y);
printf("Cosh'(%f)=%f\n",y,der);								////cosh
}
else if((p[0]=='t'||p[0]=='T') &&(p[1]=='a'||p[1]=='A')&& (p[2]=='n'||p[2]=='N') && (p[3]=='H'||p[3]=='h') &&p[4]=='\''){
		float der =derive(tanh,y);
printf("Tanh'(%f)=%f\n",y,der);							/// tanh
}
else if((p[0]=='A'||p[0]=='a') &&(p[1]=='c'||p[1]=='C') &&(p[2]=='o'||p[2]=='O')&& (p[3]=='s'||p[3]=='S') &&p[4]=='\''){
	float der =derive(acos,y);
printf("Arccos'(%f)=%f\n",y,der); 			///arccos [-1 ; 1] ---->  [0 ; pi]
}
else if((p[0]=='A'||p[0]=='a') &&(p[1]=='s'||p[1]=='S') &&(p[2]=='I'||p[2]=='i')&& (p[3]=='n'||p[3]=='N') &&p[4]=='\''){
		float der =derive(asin,y);
printf("Arcsin'(%f)=%f\n",y,der);				///arcsin [-1 ; 1] ---->  [-pi/2 ; pi/2]
}
else if((p[0]=='A'||p[0]=='a') &&(p[1]=='t'||p[1]=='T') &&(p[2]=='a'||p[2]=='A')&& (p[3]=='n'||p[3]=='N') &&p[4]=='\''){
		float der =derive(atan,y);
printf("Arctan'(%f)=%f\n",y,der);			//arctag R ---->  [-pi/2 ; pi/2]
}
else{
	printf("erreur\n");
	   printf(">>>");
}
}
else {printf("erreur");
   printf("\n");
   printf(">>>");
   	 
}
}
/// traitement partie dicimal
void traimentendecimal(char *p){
	bool x=isContparentsDebu(p);	
if(x){
	char  z[100];
	strcpy(z,p);
	strtok(p,"(");
double y=(double)movepartiedicimale(z);
double u=(double)movepartieintier(z);
if((p[0]=='s'||p[0]=='S') &&(p[1]=='i'||p[1]=='I')&& (p[2]=='n'||p[2]=='N') &&p[3]=='\''){
float der =derive(sin,y+u);
printf("Sin'(%lf)=%f\n",y+u,der);					///sin
}
else if((p[0]=='c'||p[0]=='C') &&(p[1]=='o'||p[1]=='O')&& (p[2]=='s'||p[2]=='S') &&p[3]=='\''){
	float der =derive(cos,y+u);
printf("Cos'(%lf)=%f\n",y+u,der);					///cos
}
else if((p[0]=='e'||p[0]=='E') &&(p[1]=='X'||p[1]=='x')&& (p[2]=='p'||p[2]=='P') &&p[3]=='\''){
		float der =derive(exp,y+u);
printf("exp'(%lf)=%f\n",y+u,der); 						///exp
}
else if((p[0]=='l'||p[0]=='L') &&(p[1]=='o'||p[1]=='O')&& (p[2]=='G'||p[2]=='g') &&p[3]=='\''){
		float der =derive(log,y+u);
printf("Ln'(%lf)=%f\n",y+u,der);							///ln
}
else if((p[0]=='t'||p[0]=='T') &&(p[1]=='a'||p[1]=='A')&& (p[2]=='n'||p[2]=='N') &&p[3]=='\''){
		float der =derive(tan,y+u);
printf("Tan'(%lf)=%f\n",y+u,der);										////tan
}
else if((p[0]=='e'||p[0]=='E') &&(p[1]=='X'||p[1]=='x')&& (p[2]=='p'||p[2]=='P') &&p[3]=='\''){
		float der =derive(exp,y+u);
printf("exp'(%f)=%f\n",y+u,der);							///exp
}
else if((p[0]=='s'||p[0]=='S') &&(p[1]=='i'||p[1]=='I')&& (p[2]=='n'||p[2]=='N') && (p[3]=='H'||p[3]=='h') &&p[4]=='\''){	
float der =derive(sinh,y+u);
printf("Sinh'(%f)=%f\n",y+u,der);          						///sinh
}
else if((p[0]=='c'||p[0]=='C') &&(p[1]=='o'||p[1]=='O')&& (p[2]=='s'||p[2]=='S') && (p[3]=='H'||p[3]=='h') &&p[4]=='\''){
	float der =derive(cosh,y+u);
printf("Cosh'(%f)=%f\n",y+u,der);								////cosh
}
else if((p[0]=='t'||p[0]=='T') &&(p[1]=='a'||p[1]=='A')&& (p[2]=='n'||p[2]=='N') && (p[3]=='H'||p[3]=='h') &&p[4]=='\''){
		float der =derive(tanh,y+u);
printf("Tanh'(%f)=%f\n",y+u,der);							/// tanh
}
else if((p[0]=='A'||p[0]=='a') &&(p[1]=='c'||p[1]=='C') &&(p[2]=='o'||p[2]=='O')&& (p[3]=='s'||p[3]=='S') &&p[4]=='\''){
	float der =derive(acos,y+u);
printf("Arccos'(%f)=%f\n",y+u,der); 			///arccos [-1 ; 1] ---->  [0 ; pi]
}
else if((p[0]=='A'||p[0]=='a') &&(p[1]=='s'||p[1]=='S') &&(p[2]=='I'||p[2]=='i')&& (p[3]=='n'||p[3]=='N') &&p[4]=='\''){
		float der =derive(asin,y+u);
printf("Arcsin'(%f)=%f\n",y+u,der);				///arcsin [-1 ; 1] ---->  [-pi/2 ; pi/2]
}
else if((p[0]=='A'||p[0]=='a') &&(p[1]=='t'||p[1]=='T') &&(p[2]=='a'||p[2]=='A')&& (p[3]=='n'||p[3]=='N') &&p[4]=='\''){
		float der =derive(atan,y+u);
printf("Arctan'(%f)=%f\n",y+u,der);			//arctag R ---->  [-pi/2 ; pi/2]
}
else{
	printf("erreur\n");
	   printf(">>>");
}
}
else {printf("erreur");
   printf("\n");
   printf(">>>");  	 
}
}

int main(){
	
	Menu();
while(true){
char p[100];
bool x;
printf(">>>");
gets(p);
removeSpaces(p);
if(!ifcontvergir(p))
{
 traimententier(p);
}
else if (ifcontvergir(p))
 {
 	removeParantFin(p);
	if(movepartiedicimale(p)==-500000 ||movepartieintier(p)==-500000){
	printf("erreurr");}
	else traimentendecimal(p);
}
if(!strcmp(p,"exit"))
return 0;
}
}


