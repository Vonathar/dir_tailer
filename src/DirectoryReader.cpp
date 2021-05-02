#include "DirectoryReader.h"
#include <filesystem>
#include <iostream>

using std::cout;
using std::endl;
using std::filesystem::directory_iterator;

vector<File> DirectoryReader::get_all_files (const string &dir_path)
{
  vector<File> files;
  for (const auto &entry : directory_iterator (dir_path))
  {
	File file (entry.path ().string ());
	files.push_back (file);
  }
  cout << "Files found: " << files.size () << endl;
  return files;
}