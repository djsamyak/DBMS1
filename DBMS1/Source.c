#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
#pragma warning(disable:4474)
#pragma warning(disable:4477)
#define currentTime (time(NULL)+19800)

struct tm t;

struct LibData
{
	int Sno;
	char name[50];
	char genre[20];
	char user[30];
	int status;
	time_t timeOut;
	time_t timeIn;
	time_t ETA;
};

struct LibData data[100];
int fineAmount;

void main()
{
	{
		printf("%d \n", currentTime);										//To be removed
	}
	int ch, i, totalEntries=0, Entry, lateDays, Record, fineTotal;
	char ch1;
	FILE * fpw, * fpr;
x:
	printf("\nWhat do you wish to do ? \n \n");
	printf("1. Display all records \n");
	printf("2. Add record \n");
	printf("3. Delete record \n");
	printf("4. Search record \n");
	printf("5. Fine calculation \n");
	printf("6. Check Out \n");
	printf("7. Check In \n");
	printf("8. Renewal \n");
	printf("9. Exit \n \n");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:
		{
			fpr = fopen("data.txt", "r");
			if (!fpr)
			{
				printf("File Error! \n");
				goto x;
			}
			else
			{
				printf("\n");
				for (i = 0; i < totalEntries; ++i);
				{
					while (fscanf(fpr, "%d %s %s", &data[i].Sno, data[i].name, data[i].genre) != EOF)
					{
						printf("%3d|%15s|%10s|\n", data[i].Sno, data[i].name, data[i].genre);
					}
				}
			}
			fclose(fpr);
			goto x;
		}
		break;
		case 2:
		{
			fpw = fopen("data.txt", "w");
			while (fpw)
			{
				printf("Do you want to add a new record? (y/n) \n");
				scanf(" %c", &ch1);
				if (ch1 == 'y')
				{
					totalEntries++;
					printf("Enter the data of the book (Serial Number, Name, Genre)\n");
					scanf("%d %s %s", &data[totalEntries].Sno, data[totalEntries].name, data[totalEntries].genre);
					fprintf(fpw, "%d %s %s\n", data[totalEntries].Sno, data[totalEntries].name, data[totalEntries].genre);
					fflush(fpw);
				}
				else
					if (ch1 == 'n')
						goto x;
					else
						goto x;

			}
		}
		break;
		case 3:
		{
			fpr = fopen("data.txt", "r");
			printf("Enter the Serial Number of the entry to be deleted.");
			scanf("%d", &Entry);
			for (i = 0; i < totalEntries; ++i);
			{
				while (fscanf(fpr, "%d", &data[i].Sno) != EOF)
				{
					if (Entry == data[i].Sno)
					{
						data[i].Sno = '\0';
						data[i].name[50] = '\0';
						data[i].genre[20] = '\0';
					}
				}
			}
			fclose(fpr);
			goto x;
		}
		break;
		case 4:
		{
			fpr = fopen("data.txt", "r");
			printf("Enter the Serial Number of the entry to be viewed");
			scanf("%d", &Entry);
			for (i = 0; i < totalEntries; ++i);
			{
				while (fscanf(fpr, "%d %s %s %s %d", &data[i].Sno, data[i].name, data[i].genre, data[i].status, &data[i].user, &data[i].timeOut) != EOF)
				{
					if (Entry == data[i].Sno)
					{
						if(data[i].status == 0)
							printf("%3d|%15s|%10s| IN |\n", data[i].Sno, data[i].name, data[i].genre);
						else if(data[i].status == 1)
							printf("%3d|%15s|%10s| OUT |%40s|%40s|%d|\n", data[i].Sno, data[i].name, data[i].genre, data[i].user, asctime(&data[i].timeOut));
					}
				}
			}
			fclose(fpr);
			goto x;
		}
		break;
		case 5:
		{
			printf("Set the fine amount\n");
			scanf("%d",&fineAmount);

		break;
		case 6:
		{
			printf("Enter the record number to be issued \n");
			scanf("%d",&Record);
			for (i = 0; i < totalEntries; ++i);
			{
				if(Record == data[i].Sno)
				{
					data[i].timeOut==currentTime;
					printf("Enter the user's name \n");
					scanf("%s",data[i].user);
					data[i].status=1;
				}
			}
		}
		break;
		case 7:
		{
			printf("Enter the record number to be returned \n");
			scanf("%d",&Record);
			for (i = 0; i < totalEntries; ++i);
			{
				if(Record == data[i].Sno)
				{
					data[i].timeIn==currentTime;
				}
				if((data->timeIn-data->timeOut)>(7*86400))
				{
					lateDays=((data->timeIn-data->timeOut)/86400)-7;
					fineTotal=fineAmount*lateDays;
					printf("Fine amount is %d Rupees. \n",fineTotal);
				}
			}
		}
		case 8:
		{
			printf("Enter the record number to be renewed \n");
			scanf("%d",&Record);
			for (i = 0; i < totalEntries; ++i);
			{
				if(Record == data[i].Sno)
				{
					data->timeOut=currentTime;
				}
		}
		case 9:
		{
			exit(0);
		}
		break;
		default:
		{
			printf("Enter valid choice \n");
			goto x;
		}
		}
	}
}
}
