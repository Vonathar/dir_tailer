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
  this->initial_size = size_history.front ();
}

string File::get_name ()
{
  return path.substr (path.find_last_of ('\\') + 1, string::npos);
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
}

void File::update_size_history ()
{
  size_history.push_back (file_size (path));
}

void File::print_diff ()
{
  unsigned long long current_size = get_current_size ();
  unsigned long long last_known_size = get_last_known_size ();
  cout << "File: " << get_name () << endl;
  cout << "Initial size: " << initial_size << endl;
  cout << "Current size: " << current_size << endl;
  if (current_size > last_known_size)
  {
	cout << "Diff (relative): +" << current_size - last_known_size << endl;
	cout << "Diff (absolute): +" << current_size - initial_size << endl;
  }
  else if (current_size < last_known_size)
  {
	cout << "Diff (relative): -" << last_known_size - current_size << endl;
	cout << "Diff (absolute): -" << initial_size - current_size << endl;
  }
}