#ifndef _DIRECTORYREADER_H_
#define _DIRECTORYREADER_H_

#include "File.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;

/**
 * A class that represents a way to read files from a directory.
 */
class DirectoryReader {

 public:
  /**
   * Returns the files found in the directory at the given path.
   *
   * @param dir_path the path to the directory.
   * @return the files found in the directory.
   */
  vector<File> get_all_files (const string &dir_path);
};

#endif//_DIRECTORYREADER_H_
