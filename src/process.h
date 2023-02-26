#pragma once
#include <seqan3/core/debug_stream.hpp>
#include <seqan3/io/sequence_file/all.hpp>
#include <sstream>
#include "cgr.h"



void process(std::string type);
void process_cgr(std::string type, std::vector<int**> *cgr_vector);