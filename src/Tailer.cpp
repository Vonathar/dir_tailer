#include "Tailer.h"
#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::chrono::milliseconds;
using std::filesystem::file_size;
using std::this_thread::sleep_for;

Tailer::Tailer (vector<File> files)
{
  this->files = std::move (files);
}

void Tailer::start ()
{
  while (true)
  {
	for (File &file : files)
	{
	  if (file.get_current_size () != file.get_last_known_size ())
	  {
		cout << "*---------- A file has changed ----------*" << endl;
		file.print_diff ();
		cout << "*----------------------------------------*" << endl << endl;
	  }
	  file.update_size_history ();
	}
	sleep_for (milliseconds (1000));
  }
}
