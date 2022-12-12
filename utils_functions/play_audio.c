#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include "../so_long.h"

void in_progress(char *audio_file)
{
	fflush(stdout);
	char *ar[] = {"afplay",audio_file, NULL};
	execve("/usr/bin/afplay",ar,NULL);
	perror("ERR ");
}
int kill_player()
{
	if(fork() != 0)
		return (0);
	char *ar[] = {"killall", "-STOP", "afplay", NULL};
	execve("/usr/bin/killall",ar,NULL);
	perror("ERR ");
	return (0);
}

void play_audio_repeat(t_map *map,char *audio_file)
{
	int i = 0;
	while(1)
	{
		if(fork() == 0 && !map->is_game_over)
		{
			in_progress(audio_file);
		}
		wait(NULL);
		kill_player();
		wait(NULL);
		i++;
	}
}


void play_audio_once(t_map *map,char *audio_file)
{
	fflush(stdout);
	if(fork() == 0 && !map->is_game_over)
		in_progress(audio_file);
	wait(NULL);
}

void audio(t_map *map, char *audio_file, t_paly_mode mode)
{
	if(fork() == 0)
	{
		if(mode == ONCE)
			play_audio_once(map, audio_file);
		else if(mode == REPEAT)
			play_audio_repeat(map, audio_file);
	}
}