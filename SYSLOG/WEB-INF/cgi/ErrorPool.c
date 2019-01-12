#include<stdio.h>
#include<dirent.h>
#include<string.h>
typedef struct
{
    char serialNo[10];
    char tag[25];
    char date[15];
    char time[20];
    char type[20];
    char message[100];
}LogRecord;
LogRecord lr;
FILE*fptr,*fptr1;
void printErrorPoolDetails(FILE*filterFileKaNaam)
{
    if(filterFileKaNaam)
    {
    while(1)
                   {
                       fscanf(filterFileKaNaam,"%[^T]s",lr.serialNo);
                       fseek(filterFileKaNaam,1,SEEK_CUR);
                       fscanf(filterFileKaNaam,"%[^T]s",lr.tag);
                       fseek(filterFileKaNaam,1,SEEK_CUR);
                       fscanf(filterFileKaNaam,"%[^T]s",lr.date);
                       fseek(filterFileKaNaam,1,SEEK_CUR);
                       fscanf(filterFileKaNaam,"%[^T]s",lr.time);
                       fseek(filterFileKaNaam,1,SEEK_CUR);
                       fscanf(filterFileKaNaam,"%[^T]s",lr.type);
                       fseek(filterFileKaNaam,1,SEEK_CUR);
                       if(fscanf(filterFileKaNaam,"%[^\n]s",lr.message)==EOF)
					   {
						   break;
					   }
                       if(strstr(lr.tag,"ERROR")!=NULL)
                       {
                           printf("<tr><td><center>%s</center></td><td>%s</td><td>%s</td><td>%s</td></tr>",lr.type,lr.message,lr.date,lr.time);
                       }
                       if(feof(filterFileKaNaam))
                       {
                           break;
                       }
                       fseek(filterFileKaNaam,2,SEEK_CUR);
                       
                   }
    }
    else
    {
        printf("\nerror is coming");
    }
}
int main()
{
    char *data;
    char actualMachine[30];
    char machine[30];
    char filePath[30]="g:\\vmdata\\";
    char *tempfilepath="g:\\vmdata\\";
    int i=0;
     printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
    data=getenv("QUERY_STRING");
    sscanf(data,"machine=%s",actualMachine);
    while(actualMachine[i]!='\0')
    {
        if(actualMachine[i]=='+')
        {
            actualMachine[i]=' ';
        }
        i++;
    }
    printf(" <html><head><meta name=viewport content=width=device-width, initial-scale=1><style>body {font-family: Lato, sans-serif;}.sidenav {height: 100%%;width: 350px;position: fixed;z-index: 1;top: 0;left: 0;background-color: #111;overflow-x: hidden;padding-top:20px;}.sidenav a {padding: 6px 8px 6px 16px;text-decoration: none;font-size: 25px;color: #818181;display: block;}.sidenav a:hover {color: #f1f1f1;}.main {margin-left: 350px; font-size: 28px; padding: 0px 10px;}@media screen and (max-height: 450px) {.sidenav {padding-top: 15px;}.sidenav a {font-size: 18px;}}li {color: cyan;} </style></head>");
            printf("<body>"); printf("<div class=sidenav>");
         struct dirent *de; 
           DIR *dr = opendir("C:\\Users\\User\\Saved Games\\Documents\\Virtual Machines"); 
           if (dr == NULL) 
           { 
            printf("Could not open current directory" );  
           }
           else{
              printf("<ul>");
              while ((de = readdir(dr)) != NULL)
              {
                  if(strcmp(de->d_name,".")==0||strcmp(de->d_name,"..")==0)
                      continue;
                  strcpy(machine,de->d_name);
                   i=0;
                  while(machine[i]!='\0')
                  {
                      if(machine[i]==' ')
                      {
                          machine[i]='+';
                      }
                      i++;
                  }
            printf("<li><a href=Vm.cgi?machine=%s>%s</a>",machine,de->d_name);
                  if(strcmp(actualMachine,de->d_name)==0)
                  {
                  printf("<ul><li><a href=Network.cgi?machine=%s>Network Details</a></li><li><a href=Configuration.cgi?machine=%s>Configuration Details</a></li><li><a href=Performance.cgi?machine=%s>Performance Details</a></li><li><a href=ErrorPool.cgi?machine=%s>Error Pool</a></li><li><a href=Stats.cgi?machine=%s>Statistics</li></a></ul>",machine,machine,machine,machine,machine);
                  }
                  
              }
               
           }
           closedir(dr);  
           closedir(dr);
           printf("</ul></div>");
           printf("<div class=main><center><h2>Welcome to your Virtual Machine</h2></center>");
           printf("<center><h1>%s</h1></center>",actualMachine);
    
    printf("<br>");
               printf("<center><table border=1 style=border-collapse:collapse;><tr><th colspan=4 style=\"font-size=50px\"><b>Error Pool </b></th></tr><tr><th>Type</th><th>Message</th><th>Date</th><th>Time</th></tr>");
               strcat(filePath,actualMachine);
               strcat(filePath," vmware");
               strcat(filePath,".txt");
               fptr1=fopen(filePath,"r");
               printErrorPoolDetails(fptr1);
               fclose(fptr1);
    
               strcpy(filePath,tempfilepath);
               strcat(filePath,actualMachine);
               strcat(filePath," vmware-0");
               strcat(filePath,".txt");
               fptr1=fopen(filePath,"r");
               printErrorPoolDetails(fptr1);
               fclose(fptr1);
    
    
    
               strcpy(filePath,tempfilepath);
               strcat(filePath,actualMachine);
               strcat(filePath," vmware-1");
               strcat(filePath,".txt");
               fptr1=fopen(filePath,"r");
               printErrorPoolDetails(fptr1);
               fclose(fptr1);
    
               strcpy(filePath,tempfilepath);
               strcat(filePath,actualMachine);
               strcat(filePath," vmware-2");
               strcat(filePath,".txt");
               fptr1=fopen(filePath,"r");
               printErrorPoolDetails(fptr1);
               printf("</table></center>");
               fclose(fptr1);
    
    
    
    
    
        printf("</div></body></html>");
           
    return 0;
}