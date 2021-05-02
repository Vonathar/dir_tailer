#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <vector>

using std::string;
using std::vector;

/**
 * A class that represents a file on the local system.
 */
class File {

 private:
  string path;
  unsigned long long initial_size;
  vector<unsigned long long> size_history;

 public:
  /**
   * Creates a new instance that points to a given file.
   *
   * @param path the path of the file.
   */
  explicit File (string path);

  /**
   * Returns the name of this file, including its extension.
   *
   * @return the file name.
   */
  string get_name ();

  /**
   * Returns the first known size for this file.
   *
   * @return the initial size.
   */
  unsigned long long get_initial_size ();

  /**
   * Returns the most recent known size for this file.
   *
   * @return the current size.
   */
  unsigned long long get_current_size ();

  /**
   * Returns the second most recent known size for this file.
   *
   * @return the last known size.
   */
  unsigned long long get_last_known_size ();

  /**
   * Adds the current size of this file to the history.
   */
  void update_size_history ();
};

#endif
