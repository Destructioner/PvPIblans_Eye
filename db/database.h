
#ifndef CHAR_H
#include <char.h>
#endif


	
class database_players {
	private:
		std::ifstream DB_File;
		char LineDB[1024] = {0};
		char PathDB[1024] = {0};
		
	public:
		database_players() {
			ZeroBuffer(LineDB, 1024);
			ZeroBuffer(PathDB, 1024);
		}
		
		database_players(const char *FileDB) {
			ZeroBuffer(LineDB, 1024);
			ZeroBuffer(PathDB, 1024);
			
			DB_File.open(FileDB);
			CopyBuffer(PathDB, FileDB);
		}
		
		byte check_presense(const char *NickName_Player) {
			if (DB_File.is_open()) {
				while (DB_File) {
					DB_File >> LineDB;
					
					Replace(LineDB, '\n', 0x00);
					Replace(LineDB, '\r', 0x00);
					
					if (cmp(LineDB, NickName_Player)) {
						DB_File.close();
						
						ClearBuffer(LineDB);
						return 1;
					}
				}
			}
			
			else {
				DB_File.open(PathDB);
				
				if (DB_File.is_open()) {
					while (DB_File) {
						DB_File >> LineDB;
					
						Replace(LineDB, '\n', 0x00);
						Replace(LineDB, '\r', 0x00);
					
						if (cmp(LineDB, NickName_Player)) {
							DB_File.close();
						
							ClearBuffer(LineDB);
							return 1;
						}
					}
				}
			}

			return 0;
		}
};