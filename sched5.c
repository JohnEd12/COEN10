#include <stdio.h>
#include <string.h>

int count = 0;
char lessons[5][20];
char rnumbers[5][20];
int rsize[5] = {0,0,0,0,0};
const int SIZE = 5;

void request(void);
void cancel(void);
void list(void);
void startletter(void);
void group(void);
_Bool priority(void);
int letterappear(char chartocheck);

int main(void)
{
    int i;
    char options;
    _Bool priority1 = 0;
    char lettertocheck;
    int letterappearances;
	for(i=0;i<SIZE;i++){
		lessons[i][0] = '\0';

	}
	while(1){
		printf("Enter 1 to request a lesson, 2 to cancel a lesson, 3 to list lessons, 4 to list names starting with a letter, 5 to list reservations of a group size, 6 to reserve with priority, 7 to check appearences of a letter, or 9 to quit.\n");
        scanf(" %c",&options);
        switch(options){
		case '1':
                	request();
			break;
		case '2':
			cancel();
			break;
		case '3':
			list();
			break;
		case '4':
			startletter();
			break;
		case '5': 
			group();
			break;
		case '6':	
			if(priority1 == 0){
				priority1 = priority();
			}
			else
				printf("Priority reservation have already been used.\n");
			break;
		case '7':
			 printf("Which letter do you want to check?\n");
			scanf(" %c",&lettertocheck);
			letterappearances = letterappear(lettertocheck);
			printf("The letter %c appears %d times in all names.\n",lettertocheck,letterappearances);
			break;
		case '9':
			return 0;
		default:
			printf("Please enter the number 1,2,3,4,5,6,7 or 9.\n");
	}


     }
}

void request(void){
	int i;
    char user[20];
    char usernumber[20];
    int groupsize;
	if(count == SIZE){
		printf("All lessons full today, check back later.\n");
	}else{
		i=count-1;
        printf("What is the name?\n");
        scanf("%s",user);
		if(count != 0){
			i=0;
           		 while(i<count){
				if(strcmp(user,lessons[i]) == 0){
					printf("The name is taken.\n");
                    			return;
				}else {
					i++;
				}
			}
		}
		printf("What is the size of group? Please let the size be between 1 and 4.\n");
      		 scanf("%d",&groupsize);
		if (groupsize < 1 || groupsize > 4){
			printf("The size is not between 1 and 4.\n");
			return;
		}
		printf("What is the phone number?\n");
        strcpy(lessons[count],user);
        scanf("%s",usernumber);
		
	 rsize[count] = groupsize;
        strcpy(rnumbers[count],usernumber);
		printf("%s has successfully signed up for a lesson at %d pm.\n",user,count+1);
        count++;
        return;		
	}
}

void cancel(void){
	int i;
    char user[20];
     if(count == 0){
		printf("There are no lessons reserved.\n");
	}
	else{
		printf("What name is the lesson under?\n");
        scanf("%s",user);
		for(i=0;i<count;i++){
			if(strcmp(lessons[i], user) == 0){
				printf("Message to %s : %s has successfully cancelled the lesson at %d pm.\n",rnumbers[i],user,i+1);
        		        lessons[i][0] = '\0';
               			 rnumbers[i][0] = '\0';
               			 rsize[i] = 0;
               			 count--;
               			 break;
			}
		}
		if(i == count){
			printf("There is no reservation under that name.\n");
		}

		else{
			for(;i<count;i++){
				strcpy(lessons[i],lessons[i+1]);
                	strcpy(rnumbers[i],rnumbers[i+1]);
                	rsize[i] = rsize[i+1];
                	printf("Message to %s :The lesson under %s has been moved from %d pm to %d pm.\n",rnumbers[i],lessons[i],i+2,i+1);
			}
			lessons[i][0] = '0';
		}
	}
	return;
}
		
void list(void){
    int i;
    printf("There are currently %d lessons signed up.\n",count);
     for(i=0;i<count;i++){
                printf("%s with number %s has reserved for a lesson at %d pm with group size %d.\n",lessons[i],rnumbers[i],i+1,rsize[i]);
    }

     for(i=count;i<SIZE;i++) {
            printf("Free at %d pm.\n",i+1);
      }
     return;
}
void  startletter(void){
	char namel;
        int i;
        if(count == 0){
                printf("There are no lessons signed up.\n");
                return;

        }

        printf("What does the name start with?\n");
        while(getchar() != '\n');
         scanf("%c",&namel);
        for(i=0;i<SIZE;i++){
                if(lessons[i][0] == namel){
                 printf("%s has reserved a lesson with a group of %d at %d pm.\n",lessons[i],rsize[i],i+1);
                }
        }
        return;

}

void group(void){
    int groupsize;
    int i;
    if (count == 0)  {
      printf("There are no lessons signed up.\n");
       return;
    }
     do {
      printf("What is the group size? All sizes are between 1 and 4.\n");
       scanf("%d",&groupsize);
     }
     while (groupsize < 1 || groupsize > 4);
     for(i=0;i<count;i++)  {
          if(groupsize == rsize[i]){
                  printf("%s has a reservation of size %d at %d pm.\n",lessons[i],groupsize,i+1);
         }
}

                          return;
}
_Bool priority(void){
	int i;
	int numtocheck = (count ==5) ? count-1 : count;
	char user[20];
	char usernumber[20];
	int groupsize;
	printf("What is the reservation name?\n ");
	scanf("%s",user);
	i = 0;
	while(i<numtocheck){
		if(strcmp(user,lessons[1]) == 0){
			printf("The name is taken.\n");
			return 0;
		}else{
			i++;
		}
	}
	printf("What is the size of group? Please let the size be between 1 and 4.\n");
	scanf("%d",&groupsize);
	if(groupsize < 1 || groupsize > 4){
		printf("The size is not between 1 and 4.\n");
		return 0;
	}
	printf("What is the phone number?\n");
    	scanf("%s",usernumber);
	if(count == 5){
		printf("Message to %s: The reservation under %s with group size %d at 5pm has been canceled.\n",rnumbers[4],lessons[4],rsize[4]);
		count--;
	}
	if(count >0){
		for(i = count-1;i>=0;i--){
			printf("Message to %s: The reservation under %s with group size %d has been moved from %d pm to %d pm.\n",rnumbers[i],lessons[i],rsize[i],i+1,i+2);
			strcpy(lessons[i+1],lessons[i]);
			strcpy(rnumbers[i+1],rnumbers[i]);
			rsize[i+1] = rsize[i];
		}
	}
	strcpy(lessons[0],user);
	strcpy(rnumbers[0],usernumber);
	rsize[0] = groupsize;
	printf("%s has successfully signed up for a lesson at 1 pm.\n",user);
	count++;
	return 1;

	}

int letterappear(char chartocheck){
	char *p;
	int i;
	int letterapp = 0;
	for (i=0; i<count; i++){
		p = lessons[i];
		while(*p != '\0'){
			if (*p == chartocheck){
				letterapp++;
			}
			p++;

		}

	}
	return letterapp;


}

