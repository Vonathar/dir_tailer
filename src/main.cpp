#include "DirectoryReader.h"
#include "Tailer.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main ()
{
  cout << "Enter target dir:" << endl;
  string dir_path;
  cin >> dir_path;
  cout << endl;
  vector<File> files = DirectoryReader ().get_all_files (dir_path);
  auto tailer = Tailer (files);
  tailer.start ();
}
