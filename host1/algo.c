#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<string.h>


int main()
{
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp,*fq,*fp7;
int mod[3]={0,0,0};
int i,j;
float c;
float ser1,ser2,ser3,minload,maxload,threshold,mean;
float work_transfer,temp,temp2,lower_threshold,upper_threshold;
char light[30],heavy[30],moderate[30],source_name[30],target_name[30],light_name[30],heavy_name[30];

system("sh temp2.sh");

fp1=fopen("server1_usage","r");
fp2=fopen("server2_usage","r");
fp3=fopen("server3_usage","r");

if(fp1==NULL)
{
	printf("\nError in opening server1_usage\n");
	exit(0);
}
if(fp2==NULL)
{
        printf("\nError in opening server2_usage\n");
	exit(0);

}
if(fp3==NULL)
{
        printf("\nError in opening server3_usage\n");
	exit(0);
}


	fscanf( fp1, "%f", &ser1);
	fscanf( fp2, "%f", &ser2);
	fscanf( fp3, "%f", &ser3);


	threshold=(ser1+ser2+ser3)/3;

/*
//To find MAX
if(ser1 > ser2 && ser1 > ser3)
{        
	printf("Maximum Load is %f\n",ser1);
	maxload=ser1;
}
else if(ser2 > ser1 && ser2 > ser3)
{
	printf("Maximum Load is %f\n",ser2);
	maxload=ser2;
}
else 
{
	printf("Maximum Load is %f\n",ser3);
	maxload=ser3;
}


if(ser1 < ser2 && ser1 < ser3)
{   
	printf("Minimum Load is %f\n",ser1);
	minload=ser1;
}	
else if(ser2 < ser1 && ser2 < ser3)
{
	
	printf("Minimum Load is %f\n",ser2);
	minload=ser2;
}
else
{ 
	printf("Minimum Load is %f\n",ser3);
	minload=ser3;       
}


*/


float a[3]={ser1,ser2,ser3};


/*
a[0]=ser1;
a[1]=ser2;
a[2]=ser3;
*/

// to find min

system("sh title1.sh");

for(i=0;i<3;i++)
{
      for(j=i+1;j<3;j++)
      {
           if(a[i]>a[j])
	   {
               c=a[i];
              a[i]=a[j];
              a[j]=c;
           }
      }
}

minload=a[0];

//printf("\n\nMinimum Load is %f\n",minload);
printf("\n\t\t\t\t\t\t\t==============================\n");
printf("\n\t\t\t\t\t\t\t   Minimum Load is %f\n",minload);

//to find max

for(i=0;i<3;i++)
{
      for(j=i+1;j<3;j++)
      {
           if(a[i]<a[j])
	   {
               c=a[i];
              a[i]=a[j];
              a[j]=c;
           }
      }
}





maxload=a[0];

//printf("\n\nMaximum Load is %f\n",maxload);
printf("\t\t\t\t\t\t\t   Maximum Load is %f\n",maxload);
printf("\n\t\t\t\t\t\t\t==============================\n");








	mean=(minload+maxload)/2;

	//printf("\n\nMeanload=%f\n",mean);
	//printf("\n\nTHRESHOLD=%f\n",threshold);
	
	printf("\n\t\t\t\t\t\t\t   Meanload=%f\n",mean);
	printf("\t\t\t\t\t\t\t   THRESHOLD=%f\n",threshold);
	
	work_transfer=threshold-minload;		

	//printf("\n\nWORK TRANSFER =%f\n",work_transfer);
	printf("\t\t\t\t\t\t\t   WORK TRANSFER =%f\n",work_transfer);

	printf("\n\t\t\t\t\t\t\t==============================\n");
	
	fp4=fopen("worktransfer","w");
	fprintf(fp4,"%f",work_transfer);
	fclose(fp4);

	temp=fabs(threshold-mean);	
	temp2=threshold/5;

	if(temp2>temp)
		temp=temp2;

	lower_threshold=threshold-temp;
	upper_threshold=threshold+temp;
	//printf("\n\nlower threshold = %f\nupper threshold = %f\n",lower_threshold,upper_threshold);
	//printf("\n\nCpu_usage of HOST1 = %f\nCpu_usage of HOST2 = %f\nCpu_usage of HOST3 = %f\n",ser1,ser2,ser3);

	printf("\n\t\t\t\t\t\t\t   lower threshold = %f\n\t\t\t\t\t\t\t   upper threshold = %f\n",lower_threshold,upper_threshold);
	printf("\n\t\t\t\t\t\t\t==============================\n");
	

	printf("\n\n\t\t\t\t\t\t\t==================================");	
	printf("\n\t\t\t\t\t\t\t| CPU usage of HOST1 | %f |",ser1);
	printf("\n\t\t\t\t\t\t\t| CPU usage of HOST2 | %f |",ser2);
	printf("\n\t\t\t\t\t\t\t| CPU usage of HOST3 | %f |",ser3);
	printf("\n\t\t\t\t\t\t\t==================================\n");
	

printf("\n\n\t\t\t\t\t\t\t=================================\n");

//server1
if(ser1<lower_threshold)
{

	//printf("\n\nHost1 is lightly loaded\n");	
	printf("\n\t\t\t\t\t\t\t   Host1 is lightly loaded");	
	strcpy(light,"host1");
	strcpy(light_name,"mak@mak");
	strcpy(target_name,"mak@mak");
	fp5=fopen("name","w");
	fprintf(fp5,"%s",light);
	fclose(fp5);
	


}
else if(lower_threshold<=ser1 && ser1<upper_threshold)
{

	//printf("\n\nHost1 is moderately loaded\n");
	printf("\n\t\t\t\t\t\t\t   Host1 is moderately loaded");	
	strcpy(moderate,"host1");	
	mod[0]=1;

}
else
{

	//printf("\n\nHost1 is highly loaded\n");	
	printf("\n\t\t\t\t\t\t\t   Host1 is highly loaded");	
	strcpy(heavy,"host1");
	strcpy(heavy_name,"mak@mak");
	strcpy(source_name,"mak@mak");
}
	

//server2
if(ser2<lower_threshold)
{

	//printf("\n\nHost2 is lightly loaded\n");
	printf("\n\t\t\t\t\t\t\t   Host2 is lightly loaded");	
	strcpy(light,"host2");
	strcpy(light_name,"jitesh@client1");
	strcpy(target_name,"jitesh@client1");
	fp5=fopen("name","w");
	fprintf(fp5,"%s",light);
	fclose(fp5);
	



}
else if(lower_threshold<=ser2 && ser2<upper_threshold)
{

	//printf("\n\nHost2 is moderately loaded\n");
	printf("\n\t\t\t\t\t\t\t   Host2 is moderately loaded");	
	strcpy(moderate,"host2");	
	mod[1]=1;

}
else
{

	//printf("\n\nHost2 is highly loaded\n");
	printf("\n\t\t\t\t\t\t\t   Host2 is highly loaded");	
	strcpy(heavy,"host2");
	strcpy(heavy_name,"jitesh@client1");
	strcpy(source_name,"jitesh@client1");

}


//server3
if(ser3<lower_threshold)
{

	//printf("\n\nHost3 is lightly loaded\n");
	printf("\n\t\t\t\t\t\t\t   Host3 is lightly loaded");	
	strcpy(light,"host3");
	strcpy(light_name,"server3@client3");
	strcpy(target_name,"server3@client3");
	fp5=fopen("name","w");
	fprintf(fp5,"%s",light);
	fclose(fp5);
	



}
else if(lower_threshold<=ser3 && ser3<upper_threshold)
{

	//printf("\n\nHost3 is moderately loaded\n");
	printf("\n\t\t\t\t\t\t\t   Host3 is moderately loaded");	
	strcpy(moderate,"host3");	
	mod[2]=1;

}
else
{

	//printf("\n\nHost3 is highly loaded\n");
	printf("\n\t\t\t\t\t\t\t   Host3 is highly loaded");	
	strcpy(heavy,"host3");
	strcpy(heavy_name,"server3@client3");
	strcpy(source_name,"server3@client3");

}
printf("\n\n\t\t\t\t\t\t\t=================================");


if(mod[0]==1 && mod[1]==1 && mod[2]==1)
{
	printf("\n\t\t\t\t\t\t\t   ALL IN MODERATE REGION...");
	printf("\n\t\t\t\t\t\t\t=================================\n");

	exit(0);
}


//printf("\n\nLoad must be transferred from %s to %s\n\n\n",heavy,light);
printf("\n\n\t\t\t\t\t\t\tLoad must be Transferred from '%s' to '%s'\n\n",heavy,light);

fp7=fopen("source_name","w");
fprintf(fp7,"%s",heavy);
fclose(fp7);


	fp6=fopen("light","w");
	fp=fopen("light_name","w");
	fq=fopen("target_name","w");
	fprintf(fp6,"%s",light);
	fprintf(fp,"%s",light_name);
	fprintf(fq,"%s",target_name);

	fclose(fp);
	fclose(fq);
	fclose(fp6);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);


	if(strcmp(heavy,"host1")==0)
	{

		system("./prog.out");

	}
	else if(strcmp(heavy,"host2")==0)
	{

		//printf("\n\tTransfering Files to HOST 2");		
		system("sh server2.sh");
		system("sh pr1.sh");
		system("sh vm_ser2.sh");
		

	}
	else if(strcmp(heavy,"host3")==0)
	{
		//printf("\n\tTransfering Files to HOST 3\n");
		system("sh server3.sh");
		system("sh pr2.sh");
		system("sh vm_ser3.sh");

	}

return 0;
}
