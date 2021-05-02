#include "File.h"

#include <filesystem>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::filesystem::file_size;

File::File (string path)
{
  this->path = std::move (path);
  update_size_history ();
}

string File::get_name ()
{
  return path.substr (path.find_last_of ('\\') + 1, string::npos);
}

unsigned long long File::get_initial_size ()
{
  return size_history.front ();
}

unsigned long long File::get_current_size ()
{
  return size_history.back ();
}

unsigned long long File::get_last_known_size ()
{
  if (size_history.size () >= 2)
  {
	return size_history.at (size_history.size () - 2);
  }
  else if (size_history.size () == 1)
  {
	return size_history.front ();
  }
  {
	return 0;
  }
}

void File::update_size_history ()
{
  size_history.push_back (file_size (path));
}