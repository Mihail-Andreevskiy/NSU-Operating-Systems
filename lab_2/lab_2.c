#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

extern char* tzname[];
extern long timezone;


int main(){
	time_t now;
	struct tm *sp;

	(void) time(&now);
	printf("%s", ctime(&now) );

	sp = localtime(&now);
        printf("%d/%d/%d %02d:%02d isdst=%d %s\n\n",
                sp->tm_mday, sp->tm_mon + 1,
                sp->tm_year + 1900, sp->tm_hour,
                sp->tm_min, sp->tm_isdst, tzname[sp->tm_isdst]);


	int UTCshift = timezone/60/60;
	printf("timezone = %ld sec (%ld hours)\n", timezone, UTCshift);
	now += timezone;	// making "now" for UTC0

	sp = localtime(&now);
	printf("try with shifting \"now\" to UTC0:\n%d/%d/%d %02d:%02d\n\n",
                sp->tm_mday, sp->tm_mon + 1,
                sp->tm_year + 1900, sp->tm_hour,
                sp->tm_min);



	now -= 8 * 60 * 60;	//UTC shift for California

	sp = localtime(&now);
	printf("try with shifting \"now\":\n\"timezone\' = %ld\n%d/%d/%d %02d:%02d\n\n",
                8*60*60,
		sp->tm_mday, sp->tm_mon + 1,
                sp->tm_year + 1900, sp->tm_hour,
                sp->tm_min);



	putenv("TZ=America/Los_Angeles");
	(void) time(&now);
	sp = localtime(&now);
	printf("After changing TZ:\ntimezone = %ld sec (%ld hours)\n", timezone, timezone/60/60);
	printf("%d/%d/%d %02d:%02d isdst=%d %s\nTZ = %s\n", 
		sp->tm_mday, sp->tm_mon + 1,
		sp->tm_year + 1900, sp->tm_hour,
		sp->tm_min, sp->tm_isdst, tzname[0],
		getenv("TZ"));


	
	exit(0);

}





