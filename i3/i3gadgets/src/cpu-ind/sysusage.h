#ifndef SYSUSAGE_H
#define SYSUSAGE_H

#define N_SB 8                    // Number of bar simbols 
#define N_CL 16                   // Number of bar colors 
#define LOW_FREQ (100.0/N_SB/4.0) // A frequency that I concider low 


#define ESCAPE_PERCENTS 0 


#define SHOW_ICON    1
#define SHOW_PERCENT 0
#define SHOW_BAR     0


#define ICON_TUX    ""
#define ICON_SKULL1 "☠"
#define ICON_SKULL2 ""
#define ICON_SKULL3 ""
#define ICON_BRAIN  ""
#define ICON_BOMB   ""
#define ICON_FIRE1  ""
#define ICON_FIRE2  ""


char redscale [][8] = {
		"#ffffff",
		"#ffeaea",
		"#ffd4d4",
		"#ffbfbf",
		"#ffaaaa",
		"#ff9595",
		"#ff8080",
		"#ff6a6a",
		"#ff5555",
		"#ff4040",
		"#ff2b2b",
		"#ff1515",
		"#ff0000",
		"#ff0000",
		"#ff0000",
		"#ff0000",
};

/* ▁▂▃▄▅▆▇█☠*/ 
/* 012345678 */ 
char barSymbols [][4] = {
						"▁",
						"▂",
						"▃",
						"▄",
						"▅",
						"▆",
						"▇",
						"█",
						"☠",
						"☠",
						"☠"
				   };


#define MSG_BAR_ZERO            "<span color='black'>▁</span>"
#define MSG_BAR_LOW             "<span color='%s'>▁</span>"
#define MSG_BAR_GREATER_THAN_0  "<span color='%s'>%s</span>"

// <span color='black'>0</span> is needed becouse status bar 
// sometimes hasn't a monospace font
#define MSG_PERCENT_ZERO           "<span color='black'>0</span>0%%"
#define MSG_PERCENT_LOW            "<span color='black'>0</span>%1.f%%"
#define MSG_PERCENT_LESS_THAN_10   "<span color='black'>0</span>%1.f%%"
#define MSG_PERCENT_LESS_THAN_100  "%2.f%%"
#define MSG_PERCENT_100            "%3.f%%"

#define MAX_STRING_SIZE 60
#define MSG_NUMBER 5

#endif






