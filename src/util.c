#include "../lib/util.h"
#include <stdio.h>
#include <unistd.h>

u_int16_t wait_for_msec(u_int16_t msec)
{
	sleep((double)(msec / 1000));
	return 0;
}

u_int16_t save_data(int target_register, u_int32_t written_mask,
					u_int32_t read_mask, float radiation_value, u_int32_t interval)
{
	const char *file_name = "../data/measure.csv";
	time_t raw_time;
	struct tm *time_info;
	time(&raw_time);
	time_info = localtime(&raw_time);
	char *time_stamp = asctime(time_info);
	char *new_time_stamp = malloc(strlen(time_stamp ? time_stamp : "\n"));
	if (time_stamp)
	{
		strcpy(new_time_stamp, time_stamp);
		new_time_stamp[strlen(new_time_stamp) - 1] = '\0';
	}
	time_stamp = new_time_stamp;

	FILE *file;
	if (file = fopen(file_name, "r"))
	{
		fclose(file);
		//printf("file exists!\n");
		file = fopen("../data/measure.csv", "a+");
		fprintf(file, "%s;%d;%x;%x;%0.2f;%d; \n",
				time_stamp, target_register, written_mask, read_mask, radiation_value, interval);
		fclose(file);
	}
	else
	{
		//printf("file does not exist!\n");
		file = fopen("../data/measure.csv", "w");
		printf("file created!\n");
		fprintf(file, "%s;%s;%s;%s;%s;%s; \n",
				"Date", "Register", "Generated mask", "Read mask", "Radiation", "Interval");
		fprintf(file, "%s;%s;%x;%x;%0.2f;%d; \n",
				time_stamp, target_register, written_mask, read_mask, radiation_value, interval);
		fclose(file);
	}
	return 0;
}

void show_mission_logo()
{

	printf("\t                  _____ 					\n");
	printf("\t       MISSION .-'.  ':'-.  RASPBERRY		\n");
	printf("\t             .''::: .:    '.   			\n");
	printf("\t            /   :::::'      \\		    \n");
	printf("\t           ;.    ':' `       ; 			\n");
	printf("\t |-(0)-|   |       '..       | 			\n");
	printf("\t           ; '      ::::.    ; 			\n");
	printf("\t            \\       '::::   /			\n");
	printf("\t             '.      :::  .'				\n");
	printf("\t               '-.___'_.-'			  \n\n");
	printf("\t                   2021					\n");
}