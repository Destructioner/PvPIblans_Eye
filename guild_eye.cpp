#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <cstring>
#include "char.h"
#include "guild_api/guild_players.h"
#include "db/database.h"

void get_time(char *buffer, const char *ftime) {
    time_t sectime = time(0); 
    struct tm * timeinfo = localtime (&sectime);
    
    strftime (buffer, 512, ftime, timeinfo);
}

int main(int NumArg, const char *Option[]) {
	char GuildName[512] = {0};

	for (unsigned int SelectOpt = 1; SelectOpt < NumArg; ++SelectOpt) {
		if (cmp(Option[SelectOpt], "--guild-name\0") || cmp(Option[SelectOpt], "-gn\0")) {
			CopyBuffer(GuildName, Option[SelectOpt + 1]);
			EncodeURL(GuildName, 512);
		}
	}
	
	char time_file[512] = {0};
	ZeroBuffer(time_file, 512);
	
	guild_players guild_static(GuildName);
	
	return 0;
}