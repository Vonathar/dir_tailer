#ifndef _TAILER_H_
#define _TAILER_H_
#include "File.h"
#include <iostream>
#include <vector>

using std::vector;

/**
 * A class that represents a multi-file tailer, responsible to keep track of the
 * size of all the files it tails.
 */
class Tailer {

 private:
  vector<File> files;

 public:
  /**
   * Creates a new instance, responsible for the tailing of the given files.
   *
   * @param files the files that will be tailed.
   */
  explicit Tailer (vector<File> files);

  /**
   * Starts the tailer, which continuously watches its files for any change in
   * their size.
   */
  [[noreturn]] void start ();
};

#endif//_TAILER_H_
