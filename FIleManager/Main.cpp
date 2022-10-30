#include "Menu.h"
#include "FIleExplorer.h"

int main()
{
	setlocale(0, "");

	//std::cout << "Current root path is: " << fs::current_path().root_path() << '\n';
	//Menu::ContextMenu();
	/*cout << is_volume(fs::path("\\")) << endl;
	cout << fs::path("\\") << endl;*/
	/*vector<string> nice = { "C:\\" };
	fs::directory_iterator g(*nice.begin());*/
	//Menu::Directories(fs::current_path().root_path(), 0);
		FIleExplorer fe;
		fe.Start();
	
	return 0;
}