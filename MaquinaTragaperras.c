#include <stdio.h>

	//Prototipo de funciones
	void inicio(void);
		void si(void);
			void inicio_juego(void);
				void veinte_centimos(void);
				void cincuenta_centimos(void);
				void un_euro(void);
				void tirada(void);
				void avance(void);
				void premio(void);
				void mala_suerte(void);
		void indice(void);
		void ayuda(void);
	
	//Variables globales
	int i, j;
	char x; //Variable para controlar el bucle
	float m=0; //Monedero
	double t; //Tipo de apuesta 0.2/0.5/1
	char f; //Cuando no hay fondos suficientes, controla si se añaden más o se acaba el programa
	int fa; //Fondos añadidos cuando no hay suficientes para jugar, que posteriormente se suman al monedero
	int n; //Numero del medio del primer rodillo para comprobar si los otros dos son iguales
	int c; //Contador para ver si los numeros de arriba son iguales para hacer uno o varios avances
	int r; //Es el rodillo que se va a avanzar
	int p; //El premio
	int v[3][3]; //Las 9 posiciones visibles de los 3 rodillos

main(){
	printf("\n\t\t\t==========================================================================");
	printf("\n\t\t\t||======================================================================||");
	printf("\n\t\t\t|| ____  ____    __    ___    __    ____  ____  ____  ____    __    ___ ||");
	printf("\n\t\t\t||(_  _)(  _ %c  /__%c  / __)  /__%c  (  _ %c( ___)(  _ %c(  _ %c  /__%c  / __)||", 92, 92, 92, 92, 92, 92, 92);
	printf("\n\t\t\t||  )(   )   / /(__)%c( (_-. /(__)%c  )___/ )__)  )   / )   / /(__)%c %c__ %c||", 92, 92, 92, 92, 92); 
	printf("\n\t\t\t|| (__) (_)%c_)(__)(__)%c___/(__)(__)(__)  (____)(_)%c_)(_)%c_)(__)(__)(___/||", 92, 92, 92, 92);
	printf("\n\t\t\t||======================================================================||");
	printf("\n\t\t\t==========================================================================\n\n");
	srand(time(NULL));
	do{
		inicio();
	}while(x!='n' && x!='N');
	if(m>0) printf("\nSe te devuelven %.2f euros.", m);
	return 0;
	
}

void inicio(void){
	
	if(m==0){
		printf("\n%cQuieres apostar? (S/N/I/?): ", 168);
		fflush(stdin);
		scanf("%c", &x);
	}else{
		printf("\n%cQuieres seguir apostando?  (S/N/I/?): ", 168);
		fflush(stdin);
		scanf("%c", &x);
	}
	while((x!='s' && x!='S') && (x!='n' && x!='N') && (x!='i' && x!='I') && x!='?'){
		printf("\nPor favor, introduce un valor correcto (S/N/I/?): ");
		fflush(stdin);
		scanf("%c", &x);
	}
	switch(x){
		case 's':
		case 'S':
			inicio_juego();
			break;
		case 'i':
		case 'I':
			indice();
			break;
		case '?':
			ayuda();
			break;
	}
	
}

void indice(void){
	printf("\n\t\t\t  __                    ");
	printf("\n\t\t\t /_/         _ _        ");
	printf("\n\t\t\t|_ _|_ _  __| (_)__ ___ ");
	printf("\n\t\t\t | || ' %c/ _` | / _/ -_)", 92); 
	printf("\n\t\t\t|___|_||_%c__,_|_%c__%c___|", 92, 92, 92);
	printf("\n\nElementos: \n");
	printf("1: Cerezas 0.2\n");
	printf("2: Naranjas 0.8\n");
	printf("3: Manzanas 1.6\n");
	printf("4: Peras 3.2\n");
	printf("5: Fresas 6.4\n");
	printf("6: Sandia 12.8\n");
	printf("7: Diamante verde 25\n");
	printf("8: Diamante rojo 50\n");
	printf("9: Diamante azul 100\n");
	printf("0: Comodin\n\n");
}

void ayuda(void){
	printf("\n\t\t\t    _               _      ");
	printf("\n\t\t\t   /_%c _  _ _  _ __| |__ _ ", 92); 
	printf("\n\t\t\t  / _ %c || | || / _` / _` |", 92);
	printf("\n\t\t\t /_/ %c_%c_, |%c_,_%c__,_%c__,_|", 92, 92, 92, 92, 92);
	printf("\n\t\t\t       |__/                ");
	printf("\n\nFuncionamiento: ");
	printf("\n'S'\tContinuaci%cn del programa.", 147);
	printf("\n'N'\tFinal del programa.");
	printf("\n'I'\tIndice.");
	printf("\n'?'\tAyuda.");
}

void inicio_juego(void){
	
	if(m==0){
		printf("\n%cCuanto quieres apostar? ", 168);
		scanf("%f", &m);
		while(m<=0.2 || m>500){
			printf("\nPor favor, introduce una cantidad entre 0.2 y 500: ");
			scanf("%f", &m);
		}
	}else{
		printf("\nTu saldo es: %.2f", m);
	}
	printf("\n%cDe que tipo quieres apostar? (0.2/0.5/1): ", 168);
	scanf("%lf", &t);
	while(t!=0.2 && t!=0.5 && t!=1){
		printf("\nERROR! Introduce un valor v%clido (0.2/0.5/1): ", 160);
		fflush(stdin);
		scanf("%lf", &t);
	}
	if(t>m){
		printf("\nERROR! No hay fondos suficientes. ");
		do{
			printf("\n%cDesea a%cadir fondos? ", 168, 164);
			fflush(stdin);
			scanf("%c", &f);
		}while(f!='s' && f!='S' && f!='n' && f!='N');
		if(f=='s' || f=='S'){
			printf("\nDepositar fondos: ");
			fflush(stdin);
			scanf("%d", &fa);
			m+=fa;
		}else{
			x='n';
			t=0;
		}
	}
	if(t==0.2){
		veinte_centimos();
	}else{
		if(t==0.5){
			cincuenta_centimos();
		}else{
			if(t==1) un_euro();
		}
	}
	
}

void veinte_centimos(void){
	
	tirada();
	m-=0.2;
	
}

void cincuenta_centimos(void){
	
	tirada();
	m-=0.5;
	
}

void un_euro(void){
	
	tirada();
	m-=1;
	
}

void tirada(void){
	
	c=0;
	printf("\n\t\t\t\t\t____________________________________________\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t|| ______________________________________ ||\n");
	printf("\t\t\t\t\t|| |                                    | ||\n");
	printf("\t\t\t\t\t|| |\t\t DIAMOND'S\t\t| ||\n");
	printf("\t\t\t\t\t|| |\t\t  CASINO   \t\t| ||\n");
	printf("\t\t\t\t\t|| |____________________________________| ||\n");
	printf("\t\t\t\t\t||                                        ||\n");
	printf("\t\t\t\t\t||                                        ||\n");
	printf("\t\t\t\t\t|| ______________________________________ ||\n");
	for(i=0;i<3;i++){
		printf("\t\t\t\t\t|| |\t|     |\t|     |\t|     |\t\t| ||\n");
		printf("\t\t\t\t\t|| |");
		for(j=0;j<3;j++){
			do{
				v[i][j]=rand()%10;
			}while(v[i][j]==v[i-1][j] || v[i][j]==v[i-2][j]);
			printf("\t|  %d  |", v[i][j]);
		}
		printf("\t\t| ||\n");
		printf("\t\t\t\t\t|| |\t|     |\t|     |\t|     |\t\t| ||\n");
	}
	printf("\t\t\t\t\t|| |____________________________________| ||\n");
	printf("\t\t\t\t\t|| ______________________________________ ||\n");
	printf("\t\t\t\t\t============================================\n");
	if(v[1][0]==v[1][1] && v[1][0]==v[1][2]) {
		premio();
	}else {
		if(v[1][0]==v[1][1] && v[1][0]!=v[1][2]) {
			if(v[1][2]==0) {
				premio();
			}else {
				avance();
			}
		}else {
			if(v[1][0]==v[1][2] && v[1][0]!=v[1][1]) {
				if(v[1][1]==0) {
					premio();
				}else {
					avance();
				}
			}else {
				if(v[1][1]==v[1][2] && v[1][1]!=v[1][0]) {
					if(v[1][0]==0) {
						premio();
					}else {
						avance();
					}
				}
			}
		}
	}
	if(p==0){
		mala_suerte();		
	}
	
}

void avance(void){
	
	printf("\n\t\t                                                                __                  ");
	printf("\n\t\t                                                               /_/                  ");
	printf("\n\t\t    ___   ___   _  _  ___ ___     _  _   _ _____ ___  __  __   _ _____ ___ ___ ___  ");
	printf("\n\t\t   /_%c %c / /_%c | %c| |/ __| __|   /_%c| | | |_   _/ _ %c|  %c/  | /_%c_   _|_ _/ __/ _ %c ", 92, 92, 92, 92, 92, 92, 92, 92, 92);
	printf("\n\t\t  / _ %c V / _ %c| .` | (__| _|   / _ %c |_| | | || (_) | |%c/| |/ _ %c| |  | | (_| (_) |", 92, 92, 92, 92, 92); 
	printf("\n\t\t /_/ %c_%c_/_/ %c_%c_|%c_|%c___|___| /_/ %c_%c___/  |_| %c___/|_|  |_/_/ %c_%c_| |___%c___%c___/ \n\n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);
	v[2][r]=v[1][r];
	v[1][r]=v[0][r];
	do{
		v[0][r]=rand()%10;
	}while(v[0][r]==v[1][r] && v[0][r]==v[2][r]);
	printf("\n\t\t\t\t\t____________________________________________\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t|| ______________________________________ ||\n");
	printf("\t\t\t\t\t|| |                                    | ||\n");
	printf("\t\t\t\t\t|| |\t\t DIAMOND'S\t\t| ||\n");
	printf("\t\t\t\t\t|| |\t\t  CASINO   \t\t| ||\n");
	printf("\t\t\t\t\t|| |____________________________________| ||\n");
	printf("\t\t\t\t\t||                                        ||\n");
	printf("\t\t\t\t\t||                                        ||\n");
	printf("\t\t\t\t\t|| ______________________________________ ||\n");
	for(i=0;i<3;i++){
		printf("\t\t\t\t\t|| |\t|     |\t|     |\t|     |\t\t| ||\n");
		printf("\t\t\t\t\t|| |");
		for(j=0;j<3;j++){
			printf("\t|  %d  |", v[i][j]);
		}
		printf("\t\t| ||\n");
		printf("\t\t\t\t\t|| |\t|     |\t|     |\t|     |\t\t| ||\n");
	}
	printf("\t\t\t\t\t|| |____________________________________| ||\n");
	printf("\t\t\t\t\t|| ______________________________________ ||\n");
	printf("\t\t\t\t\t============================================\n");
	
}

void premio(void){
	printf("\n\t\t\t\t\t ___ ___ ___ __  __ ___ ___  _ _ _ _ ");
	printf("\n\t\t\t\t\t| _ %c _ %c __|  %c/  |_ _/ _ %c| | | | |", 92, 92, 92, 92);
	printf("\n\t\t\t\t\t|  _/   / _|| |%c/| || | (_) |_|_|_|_|", 92); 
	printf("\n\t\t\t\t\t|_| |_|_%c___|_|  |_|___%c___/(_|_|_|_)\n\n", 92, 92);
	switch(n){
		case 0:
			printf("\n\t\t\t\tHas ganado una tirada de 1 euro. \n\n");
			m++;
			break;
		case 1:
			p=0.2*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 2:
			p=0.8*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 3:
			p=1.6*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 4:
			p=3.2*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 5:
			p=6.4*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 6:
			p=12.8*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 7:
			p=25*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 8:
			p=50*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
		case 9:
			p=100*(t*10);
			printf("\n\t\t\t\tHas ganado %d euros que se a%cadiran a tu saldo. \n\n", p, 164);
			m+=p;
			break;
	}
	p=0;
}

void mala_suerte(void){
	
	printf("\n\t\t  _  _       _           _         _    _    _                       _         _  __");
	printf("\n\t\t | %c| |___  | |_  __ _  | |_  __ _| |__(_)__| |___   ____  _ ___ _ _| |_ ___  (_)/ /", 92);
	printf("\n\t\t | .` / _ %c | ' %c/ _` | | ' %c/ _` | '_ %c / _` / _ %c (_-< || / -_) '_|  _/ -_)  _| | ", 92, 92, 92, 92, 92); 
	printf("\n\t\t |_|%c_%c___/ |_||_%c__,_| |_||_%c__,_|_.__/_%c__,_%c___/ /__/%c_,_%c___|_|  %c__%c___| (_) | ", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);
	printf("\n\t\t                                                                                 %c_%c\n\n", 92, 92);
	
}
