#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>



float get_cpu_usage()
{
int fd,n,i;
float cpu_usage;
char buf[20];
static float avg;

fd=open("cpu.temp",O_RDONLY);

if(fd==-1)
{
	printf("\nerror in opening cpu.temp file\n");
	exit(0);
}

if((n=read(fd,buf,sizeof(buf)))==-1)
{
	printf("\nread error\n");
	exit(0);
}

if(n==0)
{
	printf("\ncpu.temp is empty\n");
	exit(0);
}

buf[n]='\0';


sscanf(buf,"%f",&cpu_usage);

avg=avg+cpu_usage;

//printf("\n|CPU USAGE OF HOST 1       | %f |\n",cpu_usage);
printf("\t\t\t\t\t\t|   CPU USAGE OF HOST 1       | %.4f   |\n",cpu_usage);
		  
return avg;

}





int main()
{
FILE *fp;
int i;
float a,avg;
system("sh title.sh");
//printf("\nRUNNING cpu_usage ON HOST 1\n");
printf("\n\t\t\t\t\t\t****** RUNNING cpu_usage ON HOST 1 ******\n\n");
printf("\t\t\t\t\t\t==========================================\n");for(i=0;i<5;i++)
{
system("sh usage.sh");
a=get_cpu_usage();
}
//printf("---------------------------------\n");
printf("\t\t\t\t\t\t==========================================\n");
avg=a/5;

//printf("\n| Average cpu utilization  | %f |\n",avg);

//printf("---------------------------------\n");
printf("\t\t\t\t\t\t| Average CPU USAGE of HOST 1 | %.4f   |\n",avg);
                    
printf("\t\t\t\t\t\t==========================================\n");

fp=fopen("server1_usage","w");
fprintf(fp,"%f",avg);
fclose(fp);


return 0;
	
}


