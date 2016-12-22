//to call decision.c and to calculate vm usage

#include<stdio.h>
#include<stdlib.h>

int main()
{

FILE *fp1,*fp2,*fp3;
char heavy[20],light[20];

//printf("\n\t\t\t\t\t\t RUNNING prog.c ON HOST 2\n");

fp1=fopen("source_name","r");
fp2=fopen("light","r");

fscanf(fp1,"%s",heavy);
fscanf(fp2,"%s",light);

fclose(fp1);
fclose(fp2);


//system("rm utilization");
system("sh vm_usage.sh");

system("./decision.out");

printf("\n\n\n\t\t\t\t\t\t MIGRATING VIRTUAL MACHINE FROM %s TO %s \n\n",heavy,light);

system("sh vm_pid.sh");

//printf("\n\t\t\t\t\t\t***** Successfully tansferred *****\n\n");

return 0;
}


