

static size_t BytesApi(char *Out, size_t sz1, size_t sz2, std::string *In) {
	In->append(Out);
	
	return sz1 * sz2;
}

class guild_players {
	private:
		std::string out_api;
		std::string url_guild;
		CURL *Requests;
		
		char get_num(char Byte) {
			switch (Byte) {
				case 'a': return 0x0A;
				case 'b': return 0x0B;
				case 'c': return 0x0C;
				case 'd': return 0x0D;
				case 'e': return 0x0E;
				case 'f': return 0x0F;
				
				case 'A': return 0x0A;
				case 'B': return 0x0B;
				case 'C': return 0x0C;
				case 'D': return 0x0D;
				case 'E': return 0x0E;
				case 'F': return 0x0F;
				
				case '0': return 0x00;
				case '1': return 0x01;
				case '2': return 0x02;
				case '3': return 0x03;
				case '4': return 0x04;
				case '5': return 0x05;
				case '6': return 0x06;
				case '7': return 0x07;
				case '8': return 0x08;
				case '9': return 0x09;
			}
			
			return 0xFF;
		}
		
		void decode_unicode(std::string &UnicodeText) {
			std::string ElementUnicode;
			char utf_symb[3] = {0, 0, 0};
			
			for (unsigned int IterSearch = 0; UnicodeText[IterSearch]; ++IterSearch) {
				if (UnicodeText[IterSearch] == '\\' && UnicodeText[IterSearch + 1] == 'u') {
					ElementUnicode.reserve(7);
					
					ElementUnicode = UnicodeText.substr(IterSearch, 6);
					
					if (ElementUnicode == "\\u0401\0") {
						utf_symb[0] = 0xD0;
						utf_symb[1] = 0x81;
						
						UnicodeText.replace(IterSearch, 6, utf_symb);
						
						utf_symb[0] = 0x00;
						utf_symb[1] = 0x00;
						
						ElementUnicode.clear();
						
						continue;
					}
					
					if (ElementUnicode == "\\u0451\0") {
						utf_symb[0] = 0xD1;
						utf_symb[1] = 0x91;
						
						UnicodeText.replace(IterSearch, 6, utf_symb);
						
						utf_symb[0] = 0x00;
						utf_symb[1] = 0x00;
						
						ElementUnicode.clear();
						
						continue;
					}
					
					switch (ElementUnicode[4]) {
						case 0x31:
							utf_symb[0] = 0xD0;
							utf_symb[1] = 0x90 + get_num(ElementUnicode[5]);
							
							UnicodeText.replace(IterSearch, 6, utf_symb);
							
							utf_symb[0] = 0x00;
							utf_symb[1] = 0x00;
							break;
							
						case 0x32:
							utf_symb[0] = 0xD0;
							utf_symb[1] = 0xA0 + get_num(ElementUnicode[5]);
							
							UnicodeText.replace(IterSearch, 6, utf_symb);

							utf_symb[0] = 0x00;
							utf_symb[1] = 0x00;
							break;
							
						case 0x33:
							utf_symb[0] = 0xD0;
							utf_symb[1] = 0xB0 + get_num(ElementUnicode[5]);
							
							UnicodeText.replace(IterSearch, 6, utf_symb);

							utf_symb[0] = 0x00;
							utf_symb[1] = 0x00;
							break;
							
						case 0x34:
							utf_symb[0] = 0xD1;
							utf_symb[1] = 0x80 + get_num(ElementUnicode[5]);
							
							UnicodeText.replace(IterSearch, 6, utf_symb);

							utf_symb[0] = 0x00;
							utf_symb[1] = 0x00;
							break;
					}
					
					ElementUnicode.clear();
				}
			}
		}
	
	public:
		guild_players(const char *GuildName) : Requests(0) {
			const int LengthName = 136 + len(GuildName);
			const int LengthEncode = len(GuildName) + 150;
			
			char GuildEncode[LengthEncode];
			ZeroBuffer(GuildEncode, LengthEncode);
			CopyBuffer(GuildEncode, GuildName);
			
			EncodeURL(GuildEncode, LengthEncode);
			
			char temp_name[LengthName];
			ZeroBuffer(temp_name, LengthName);
			
			CopyBuffer(temp_name, "https://sirus.su/api/base/guilds/57/\0");
			AppendBuffer(temp_name, GuildEncode);
			
			url_guild.reserve(len(temp_name));
			url_guild.append(temp_name);
			
			Requests = curl_easy_init();
			
			curl_easy_setopt(Requests, CURLOPT_URL, temp_name);
			curl_easy_setopt(Requests, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67\0");
			curl_easy_setopt(Requests, CURLOPT_SSL_VERIFYPEER, 0);
			curl_easy_setopt(Requests, CURLOPT_SSL_VERIFYHOST, 0);
			curl_easy_setopt(Requests, CURLOPT_WRITEFUNCTION, BytesApi);
			curl_easy_setopt(Requests, CURLOPT_WRITEDATA, &out_api);
			
			curl_easy_perform(Requests);
			curl_easy_cleanup(Requests);
		}
		
		unsigned char target_guild(const char *GuildName) {
			const int LengthName = 136 + len(GuildName);
			const int LengthEncode = len(GuildName) + 150;
			
			char GuildEncode[LengthEncode];
			ZeroBuffer(GuildEncode, LengthEncode);
			CopyBuffer(GuildEncode, GuildName);
			
			EncodeURL(GuildEncode, LengthEncode);
			
			char temp_name[LengthName];
			ZeroBuffer(temp_name, LengthName);
			
			CopyBuffer(temp_name, "https://sirus.su/api/base/guilds/57/\0");
			AppendBuffer(temp_name, GuildEncode);
			
			url_guild.reserve(len(temp_name));
			url_guild.append(temp_name);
			
			Requests = curl_easy_init();
			
			curl_easy_setopt(Requests, CURLOPT_URL, temp_name);
			curl_easy_setopt(Requests, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67\0");
			curl_easy_setopt(Requests, CURLOPT_SSL_VERIFYPEER, 0);
			curl_easy_setopt(Requests, CURLOPT_SSL_VERIFYHOST, 0);
			curl_easy_setopt(Requests, CURLOPT_WRITEFUNCTION, BytesApi);
			curl_easy_setopt(Requests, CURLOPT_WRITEDATA, &out_api);
			
			curl_easy_perform(Requests);
			curl_easy_cleanup(Requests);
			
			if (out_api.find("<title>\0") != std::string::npos) {
				return 0;
			}
			
			else {
				return 1;
			}
		}
		
		
		unsigned char update_data() {
			if (! out_api.empty()) out_api.clear();
			
			Requests = curl_easy_init();
			
			curl_easy_setopt(Requests, CURLOPT_URL, url_guild.c_str());
			curl_easy_setopt(Requests, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67\0");
			curl_easy_setopt(Requests, CURLOPT_SSL_VERIFYPEER, 0);
			curl_easy_setopt(Requests, CURLOPT_SSL_VERIFYHOST, 0);
			curl_easy_setopt(Requests, CURLOPT_WRITEFUNCTION, BytesApi);
			curl_easy_setopt(Requests, CURLOPT_WRITEDATA, &out_api);
			
			curl_easy_perform(Requests);
			curl_easy_cleanup(Requests);
			
			if (out_api.find("<title>\0") != std::string::npos) {
				return 0;
			}
			
			else {
				return 1;
			}
		}
		
		
		unsigned char get_list_players(const char *FileToWrite) {
			if (! out_api.empty()) {
				std::ofstream ListAdd(FileToWrite, std::ios_base::ate | std::ios_base::app | std::ios_base::binary);
				
				if (! ListAdd) {
					ListAdd.close();
					
					ListAdd.open(FileToWrite, std::ios_base::out | std::ios_base::binary);
					ListAdd.close();
					
					ListAdd.open(FileToWrite, std::ios_base::ate | std::ios_base::app | std::ios_base::binary);
				}
				
				std::string NickName;
				
				for (unsigned long long OffsetName = out_api.find("titled_name"), OffsetWrite_Start = 0, OffsetWrite_End = 0; OffsetName != std::string::npos; OffsetName = out_api.find("titled_name", OffsetName)) {
					OffsetWrite_Start = OffsetName;
					OffsetWrite_Start += 14;
					
					OffsetWrite_End = OffsetWrite_Start;
					
					for (; out_api[OffsetWrite_End] != '"'; ++OffsetWrite_End);
					
					NickName.reserve(OffsetWrite_End - OffsetWrite_Start);
					NickName += out_api.substr(OffsetWrite_Start, OffsetWrite_End - OffsetWrite_Start);
					
					decode_unicode(NickName);
					
					ListAdd << NickName << std::endl;
					NickName.clear();
					
					++OffsetName;
				}
				
				ListAdd.close();
				
				return 1;
			}
			
			return 0;
		}
			
			
		short num_players() {
			short CountPlayer = 0;
			
			if (! out_api.empty()) {
				unsigned long long OffsetJson = 0;
				OffsetJson = out_api.find("account\0");
				
				for (; OffsetJson != std::string::npos; ++CountPlayer, ++OffsetJson, OffsetJson = out_api.find("account\0", OffsetJson));
			}
			
			else return -1;
			
			return CountPlayer;
		}
};