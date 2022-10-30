#include "FileExplorer.h"

int main()
{
	

	//std::cout << "Current root path is: " << fs::current_path().root_path() << '\n';
	//Menu::ContextMenu();
	/*cout << is_volume(fs::path("\\")) << endl;
	cout << fs::path("\\") << endl;*/
	/*vector<string> nice = { "C:\\" };
	fs::directory_iterator g(*nice.begin());*/
	//Menu::Directories(fs::current_path().root_path(), 0);
		FileExplorer fe;
		fe.Start();
	
	return 0;
}