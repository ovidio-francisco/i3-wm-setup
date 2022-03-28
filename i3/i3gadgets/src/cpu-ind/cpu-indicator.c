#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include "sysusage.h"


/* Compile with  */
/* gcc cpu-indicator.c -lm -o cpu-indicator && ./cpu-indicator */



char* usageToBar(float usage) {

	float g = usage/(100.0/N_SB);
	int i = (int)g; 

	return barSymbols[i];
}


int usageColorIndex(float usage){

	float g = usage/(100.0/N_CL);
	int i = (int)g; 

	return i;
}



float getCpuUsage() {

	FILE *fp;
	char line[200];
	fp = popen("mpstat 1 1 -o JSON", "r"); 


	char sub[] = "\"idle\": ";
	int ls = strlen(sub);
	char *p;
	float result = -1;


	while( fgets( line, sizeof(line), fp ) ) {
		int i;
		int ll = strlen(line);

		for(i=0; i<ll; i++) {

			int j=0;
			while (line[i] == sub[j]) {
				i++;
				j++;
			}

			if(j==ls) {
				p = &line[i];
				*(p+5) = '\0';
				pclose(fp);
				return 100 - atof(p);
			}
		}
	}

	pclose(fp);
	return -1;
}






void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
    now = clock();

	/* https://c-for-dummies.com/blog/?p=69 */
}



void printIcon(float u) {
	
	char* icon;

	if (u<80)
		icon = ICON_BRAIN;
	else if (u<90)
		icon = ICON_SKULL3;
	else if (u<95)	
		icon = ICON_FIRE1;
	else	
		icon = ICON_FIRE1;


	int ci = usageColorIndex(u);


	printf("<span color='%s'>%s</span>", redscale[ci], icon);
}

void printPercent(float u) {
	if (u < 1)
		printf(MSG_PERCENT_ZERO, u);
	else if (u < 10) 
		printf(MSG_PERCENT_LESS_THAN_10, u);
	else if (u < 100)
		printf(MSG_PERCENT_LESS_THAN_100, u);
	else
		printf(MSG_PERCENT_100, u);
}

void printBar(float u) {
	int ci = usageColorIndex(u);
	char* bar = usageToBar(u);
	char* barColor = redscale[ci];

	if (u < 1)
		printf(MSG_BAR_ZERO,barColor,bar);
	else 
		printf(MSG_BAR_GREATER_THAN_0,barColor,bar);
}


int main(int argc, char *argv[]) {

	int si = SHOW_ICON;
	int sp = SHOW_PERCENT;
	int sb = SHOW_BAR;
	int dl = 0;


	if(argc>1) {
		int i = 0;
		char c;
		while(c = argv[1][i++])
			if (c=='i') si = 1; else
			if (c=='n') si = 0; else
			if (c=='p') sp = 1; else
			if (c=='b') sb = 1; else
			if (c=='d') dl = 1;
	}


	while(1) {
		float u = getCpuUsage();  // usage

		if (si) printIcon(u);
		if (sp) printPercent(u);
		if (sb) printBar(u);

		printf("\n");
		fflush(stdout);  

		if (dl) delay(1000);
	}
}


























/* https://www.raspberrypi.org/forums/viewtopic.php?t=64835 */
/* https://www.raspberrypi.org/forums/viewtopic.php?t=64835 */
/* https://stackoverflow.com/questions/8501706/how-to-get-the-cpu-usage-in-c */

/* https://www.colorhexa.com/ff0000-to-ffffff */
/* https://rosettacode.org/wiki/Get_system_command_output#C */
/* https://stackoverflow.com/questions/3769405/determining-cpu-utilization */
/* https://www.idnt.net/en-GB/kb/941772 */




/* float getCpuUsage() { */

	/* FILE *fp; */
	/* char *buffer; */
	/* size_t t = sizeof(buffer)-1; */
	/* buffer = malloc(10); */
 
	/* fp = popen("mpstat 1 1 | grep Average | awk -F' ' '{print $NF}'", "r");  */
		
	/* fgets(buffer, t, fp);  */
	/* float result = 100.0-atof(buffer); */

	/* [> float result = getUsage(buffer); <] */


	/* free(buffer); */
	/* pclose(fp); */

	/* return result; */
/* } */


