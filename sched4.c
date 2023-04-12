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
		case '4'
			startletter();
			break;
		case '5' 
			group();
			break;
		case '6'	
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
		

	

