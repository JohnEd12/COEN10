#include <stdio.h>
#include <string.h>


int main(void){
	char name[20];
	char schedule[5][20];
	char inital;
	int i;
	char var;
	int answer;
	int counter = 0;
	for(i = 0; i < 5; i++){
		schedule[i][0] = '\0';
	}
	while(1){
	printf("Enter 1 to schedule a lesson\n");
                printf("Enter 2 to cancel a lesson \n");
                printf("Enter 3 to see the list of lesson \n");
                printf("Enter 9 to quit\n");
		printf("Enter 4 to search for an inital \n ");

                scanf("%d", &answer);

	switch(answer){
		case 1 :
			if (counter != 5){
			    printf("What is your name?\n");
			    scanf("%s", name);
				 for(i =0; i <5; i++){
					if(schedule[i][0] == '\0' ){
						printf("You are scheduled for %d o'clock\n ", i+1);
						strcpy(schedule[i], name);
						counter++;
						break;
					}				
			     }
			}
		
		break;
		case 2 :
			 printf("What is your name?\n");
                         scanf("%s", name);
			if(counter == 0 ){
				printf("You have no scheduled appointments\n ");
					
			}else{
				for(i = 4; i>=0; i--){
					if(schedule[i][0] != '\0'){
						schedule[i][0] = '\0';
						counter--;
						printf("Your appointment is now cancelled\n ");
						break;
					}
				}
			}
	
	
        	
		break;
		case 3 :
			for(i = 0; i <5; i++){
				if(schedule[i][0]  == '\0'){
					printf("%d o'clock is free\n ", i+1);
				}else{ 
					printf("%d is not free, it it taken by %s \n", i+1, schedule[i]);
					
				}			
			}				
		
		break;
		case 9 :
			printf("quit");
			return 0;
		
		break;
		case 4 :
			while (getchar() != '\n');
                     scanf("%c", &var);
			for(i = 0; i < 5; i++){
				if(schedule[i][0] == var){
					printf("user %s and time %d \n", schedule[i], i+1); 
				}
			}
		break;
	}
}
}

		


