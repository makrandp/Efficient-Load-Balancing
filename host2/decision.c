#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

FILE *fp1,*fp2,*fp3,*fp4;

int a,i=0,j=0,cnt=0,k=0,index,pid[50];

float load[50],work,compare[50],min=0.0;

//int i,index=0;

printf("\n\t\t\t\t\t RUNNING decision.c ON HOST 2\n");

fp1=fopen("utilization","r");
fp2=fopen("worktransfer","r");
fp3=fopen("final_pid","w");


while((fscanf(fp1,"%d%f",&pid[i],&load[i]))!=EOF)
{
	i++;
	cnt++;
}


fscanf(fp2,"%f",&work);


for(k=0;k<cnt;k++)
{
		compare[k]=fabs(load[k]-work);
}




//printf("\n\nwork to be transfer = %f\n",work);
printf("\n\n\t\t\t\t\t\t========================================================\n");
printf("\t\t\t\t\t\t\t   work to be transfer = %f\n",work);


printf("\t\t\t\t\t\t========================================================\n");



for(j=0;j<cnt;j++)
{
		printf("\n\t\t\t\t\t\t\t   cpu utilization = %f\n",load[j]);
		printf("\t\t\t\t\t\t\t   difference = %f\n",compare[j]);
		printf("\t\t\t\t\t\t\t   pid = %d\n",pid[j]);
		printf("\t\t\t\t\t\t\t ------------------------------\n");
}





for (i=0;i<cnt;i++)
{
	  if(i==0) 
	  {
	  	min=compare[i];
	        index = i;
	  }
	  else if(compare[i]<min)
	  { 
	    	min=compare[i];
	   	index = i; 		
	  }
	
}


//pid of vm to transfer

fprintf(fp3,"%d",pid[index]);


//printf("minimum = %f at index %d & pid = %d\n",min,index,pid[index]);  
printf("\n\n\t\t\t\t\t\tVM with minimum Load = %f at index %d & pid = %d\n",min,index,pid[index]);  

printf("\t\t\t\t\t\t========================================================\n");

	
fclose(fp1);
fclose(fp2);
fclose(fp3);


return 0;
}

/*
for(i=0;i<3;i++)
scanf("%f",&load[i]);

printf("\nwork\n");
scanf("%f",&work);

for(i=0;i<3;i++)
compare[i]=fabs(load[i]-work);





for (i=0;i<3;i++)
{
	  if (i==0) {
	     min=compare[i];
	     index = i;
	  }
	  else
	    if (compare[i]<min){ 
	    	min=compare[i];
	   	index = i; 		
	   }
	
}



printf("\nmin = %f and index = %d\n",min,index);

*/

